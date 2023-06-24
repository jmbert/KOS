/* The bootloader will look at this image and start execution at the symbol
   designated as the entry point. */
ENTRY(_start)

KERNEL_LOWER = 1M;
KERNEL_HIGHER = 0xC0000000;
 
/* Tell where the various sections of the object files will be put in the final
   kernel image. */
SECTIONS
{

	. = KERNEL_HIGHER+KERNEL_LOWER;

	.text ALIGN(1K) : AT(ADDR(.text) - KERNEL_HIGHER)
	{
		*(.multiboot)
		*(.text)
	}

	/* Read-write data (uninitialized) and stack */
	.bss ALIGN(1K) : AT(ADDR(.bss) - KERNEL_HIGHER)
	{
		*(COMMON)
		*(.bss)
	}
 
	/* Read-only data. */
	.rodata ALIGN(1K) : AT(ADDR(.rodata) - KERNEL_HIGHER)
	{
		*(.rodata)
	}
 
	/* Read-write data (initialized) */
	.data ALIGN(1K) : AT(ADDR(.data) - KERNEL_HIGHER)
	{
		*(.data)
	}

	/DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
		*(.note.gnu.build-id)
		*(.debug_*)
	}

}
