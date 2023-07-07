.set ALIGN,  	1 << 0
.set MEMINFO, 	1 << 1
#if defined GRAPHICS
.set GRAPHICS,	1 << 2
.set FLAGS, 	ALIGN | MEMINFO | GRAPHICS
#else 
.set FLAGS, 	ALIGN | MEMINFO
#endif
.set MAGIC,		0x1BADB002
.set CHECKSUM, 	-(MAGIC + FLAGS)

.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM
.skip 24
#if defined GRAPHICS
.long MODE
.long WIDTH
.long HEIGHT
.long DEPTH
#endif

.section .bss
.align 4
stack_bottom:
.skip 0x4000 # 16 Kib
stack_top:

.section .text
.global _start
.type _start, @function
_start:

	mov %ebx, 0x70000			# Store multiboot info structure for later use

	# Since we want our C labels to reference higher-half values, we need to enter our C code already mapped
	# to the higher half.
	# This means we need to manually allocate pages for the kernel and paging strucutes into the higher half
	# as well as identity mapping them, before enabling paging, switching to the higher half, then unallocating
	# the identity mappings

	.set TABLE_LENGTH, 		0x400					# Length of a page table
	.set PAGE_LENGTH, 		0x1000					# Size of a page in bytes

	.set KERNEL_HIGH,		0xC0000000				# Where the kernel should be mapped to

	.extern __KENREL_END
	.set PAGE_DIRECTORY,	(__KERNEL_END) - KERNEL_HIGH		# Address of the page directory

	.set KERNEL_PTAB,		PAGE_DIRECTORY+0x1000
	.set KERNEL_PTAB_OFFSET,	0xc00

	.set PSTRUCT_PTAB,		PAGE_DIRECTORY+0x2000
	.set PSTRUCT_PTAB_OFFSET,	0xd00

	.set KERNEL_PTAB_LOW,		PAGE_DIRECTORY+0x3000
	.set KERNEL_PTAB_OFFSET_LOW,	0x000

	mov $KERNEL_PTAB, %eax
	or $0x3, %eax
	mov $KERNEL_PTAB_OFFSET, %ebx
	mov %eax, PAGE_DIRECTORY(%ebx)		# Sets the page directory entry for the higher half kernel

	mov $PSTRUCT_PTAB, %eax
	or $0x3, %eax
	mov $PSTRUCT_PTAB_OFFSET, %ebx
	mov %eax, PAGE_DIRECTORY(%ebx)		# Sets the page directory entry for the higher half paging structures

	mov $KERNEL_PTAB_LOW, %eax
	or $0x3, %eax
	mov $KERNEL_PTAB_OFFSET_LOW, %ebx
	mov %eax, PAGE_DIRECTORY(%ebx)		# Sets the page directory entry for the lower half kernel

	mov $TABLE_LENGTH, %ecx
	xor %edx, %edx
fill_kernel_page:
	mov $TABLE_LENGTH, %eax	
	sub %ecx, %eax 			
	shl $0x2, %eax
	add $0x3, %edx			# Adds writeable and present flags to edx
	mov %edx, KERNEL_PTAB(%eax) # Assigns the page
	sub $0x3, %edx			# Removes flags from edx

	add $PAGE_LENGTH, %edx	# Next page
	dec %ecx				# One less page to allocate
	test %ecx, %ecx			# Are we done?
	jne fill_kernel_page	# If not, allocate another page

	mov $TABLE_LENGTH, %ecx
	mov $PAGE_DIRECTORY, %edx
fill_pstruct_page:
	mov $TABLE_LENGTH, %eax	
	sub %ecx, %eax 			
	shl $0x2, %eax
	
	add $0x3, %edx			# Adds writeable and present flags to edx
	mov %edx, PSTRUCT_PTAB(%eax) # Assigns the page
	sub $0x3, %edx			# Removes flags from edx

	add $PAGE_LENGTH, %edx	# Next page
	dec %ecx				# One less page to allocate
	test %ecx, %ecx			# Are we done?
	jne fill_pstruct_page	# If not, allocate another page

	mov $TABLE_LENGTH, %ecx
	xor %edx, %edx
fill_kernel_page_low:
	mov $TABLE_LENGTH, %eax	
	sub %ecx, %eax 			
	shl $0x2, %eax
	add $0x3, %edx			# Adds writeable and present flags to edx
	mov %edx, KERNEL_PTAB_LOW(%eax) # Assigns the page
	sub $0x3, %edx			# Removes flags from edx

	add $PAGE_LENGTH, %edx	# Next page
	dec %ecx				# One less page to allocate
	test %ecx, %ecx			# Are we done?
	jne fill_kernel_page_low	# If not, allocate another page

	mov $TABLE_LENGTH, %ecx
	mov $PAGE_DIRECTORY, %edx

	mov $PAGE_DIRECTORY, %eax
	mov %eax, %cr3				# Load the page directory into cr3

	mov %cr0, %eax
	or $0x80000000, %eax		# Enable paging
	mov %eax, %cr0 

	mov $kernel_high, %eax
	jmp %eax					# Jump to higher half kernel

kernel_high:
	xor %edx, %edx				# We want to fill the table with zeroes

	mov $KERNEL_PTAB_OFFSET_LOW, %ebx
	mov %edx, PAGE_DIRECTORY(%ebx)		# Sets the page directory entry for the lower half kernel to 0
	
	mov $TABLE_LENGTH, %ecx
remove_kernel_page_low:
	mov $TABLE_LENGTH, %eax	
	sub %ecx, %eax 			
	shl $0x2, %eax
	add $KERNEL_HIGH, %eax			# Now have to access through the high mapping
	mov %edx, KERNEL_PTAB_LOW(%eax) # Removes the page
	

	dec %ecx				# One less page to remove
	test %ecx, %ecx			# Are we done?
	jne remove_kernel_page_low	# If not, remove another page

	mov $stack_top, %esp

	# Now ready to enter the kernel, stack is set up for 16 KiB,
	# Kernel is mapped to 0xC0000000.
	mov 0xc0070000, %eax		# Load multiboot structure
	add $KERNEL_HIGH, %eax		# Move to high kernel addressing
	push %eax
	.extern kernel_init
	call kernel_init

				cli				# Unbothered by interrupts
kernel_hang:	hlt				# Stop the CPU
				jmp kernel_hang	# If we somehow get out, get back in