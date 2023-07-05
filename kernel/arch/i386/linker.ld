ENTRY(_start)
KERNEL_HIGH = 0xC0000000;

SECTIONS {

    . = KERNEL_HIGH + 1M;

    __KERNEL_START = .;

    .text ALIGN(4K) : AT(ADDR(.text) - KERNEL_HIGH) {
        *(.multiboot)
        *(.text)
    }

    .data ALIGN(4K) : AT(ADDR(.data) - KERNEL_HIGH) {
        *(.data)
    }

    .rodata ALIGN(4K) : AT(ADDR(.rodata) - KERNEL_HIGH) {
        *(.rodata)
    }

    .bss ALIGN(4K) : AT(ADDR(.bss) - KERNEL_HIGH) {
        *(COMMON)
        *(.bss)
    }

    . = ALIGN(2M); /* Align end to 2M boundary */

    __KERNEL_END = .;
    __KERNEL_LEN = __KERNEL_END-__KERNEL_START;
}