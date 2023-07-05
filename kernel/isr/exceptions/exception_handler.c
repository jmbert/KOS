#include <stdint.h>
#include <stdio.h>
#include <panic.h>
#include <stdlib.h>
#include "__exception_isr.h"

#if (HOST==i686-elf)
#include <idt/exception_handler.h>
void exception_handler(uint16_t irq, uint8_t *int_stackframe) {
    switch (irq) {
    case PAGE_FAULT:;
        __page_fault_handler(*int_stackframe);
        break;
    case 0x6:;
        __invalid_instr_handler();
        break;
    default:;
        char *str = kmalloc(sizeof(char)*2000);
        sprintf(str, "Generic Exception #%d", irq);
        kernel_panic(str);
        break;
    }
    return;
}
#else
#error Exception Handling must be implemented in this targeted architecture
#endif