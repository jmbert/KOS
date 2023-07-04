A hobby kernel built by me

Uses some code from https://wiki.osdev.org

./build creates the elf binary
./iso creates the elf binary and ISO file
./qemu creates the elf binary, ISO file and begins emulation

To change the target host, run :

export HOST=TARGET_ARCH

Architecture information:

For an architecture to compile, it must have: 
kernel/arch/TARGET_ARCH
kernel/arch/TARGET_ARCH/make.config (which must declare the variables KERNEL_ARCH_CFLAGS, KERNEL_ARCH_CPPFLAGS, KERNEL_ARCH_LDFLAGS, KERNEL_ARCH_LIBS and KERNEL_ARCH_OBJS)
kernel/arch/TARGET_ARCH/linker.ld 
kernel/arch/TARGET_ARCH/include/kernel/init.h 
init.h must declare :
void arch_init(multiboot_info_t *minfo);
Which must be implemented

libc/arch/TARGET_ARCH
libc/arch/TARGET_ARCH/make.config (which must declare the variables ARCH_CFLAGS, ARCH_CPPFLAGS, KERNEL_ARCH_CFLAGS, KERNEL_ARCH_CPPFLAGS, ARCH_FREEOBJS and ARCH_HOSTEDOBJS)

Kernel wrapper functions for architecture-specific functions must be implemented as so:

#if (HOST=i686-elf)
#include <path/to/i686/specific/header>
#elif (HOST=x86_64)
#include <path/to/x86_64/specific/header>
#else
#error Error: Provide THIS_FEATURE functionality for the desired architecture 

void some_wrapper_function(void) {

#if (HOST=i686-elf)
	i686_specific_function()
#elif (HOST=x86_64)
	x86_64_specific_function()
#else
	#error Error: Provide THIS_FEATURE functionality for the desired architecture 
}

In libc, whether the library is being compiler for the user or kernel can be tested by the macro __is_libk
Source files must include <sys/cdefs.h> as the first line.
In header files, you can include code only for libc source files by placing it inside:

#if defined __KOS_LIBC
/* Some library-only macros/definitions */
#endif

All libc functions must either be the same across user and kernel implementation or have seperate implementations, i.e:

void some_libc_function(void) {
#if defined __is_libk
/* Kernel implementation */
#else 
/* User implementation */
#endif
}

Alternatively, there may be seperate versions for use by the kernel or user, i.e.:

#if defined __is_libk
void *kmalloc(size_t size) {
	/* Kernel Malloc */
}
#else
void *malloc(size_t size) {

}
#endif

Macros defined at the command line include :
__is_libk   - For libc, no value, indicates whether this is being compiled for the kernel
__is_libc   - For libc, no value, indicates whether this is being compiled for the user
__is_kernel	- For kernel, no value, indicates that this is part of the kernel source code

Environment variable macros (should be set for the desired build):
HOST		- For kernel and libc, contains the target host architecture
MODE		- For kernel, indicates the graphics mode
WIDTH		- For kernel, contains the width in characters or pixels of the screen
WIDTH		- For kernel, contains the height in characters or pixels of the screen
DEPTH		- For kernel, contains the bpp for the linear framebuffer mode, or ignored for EGA mode
GBUFFER		- For kernel, contains the virtual address of the graphics buffer start