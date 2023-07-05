#include <stdint.h>
#include <stdio.h>
#include "__exception_isr.h"

#if (HOST==i686-elf)
#include <idt/exception_handler.h>
void exception_handler(uint16_t irq) {
    switch (irq) {
    case 0x6:
        __invalid_instr_handler();
    }
    return;
}
#else
#error Exception Handling must be implemented in this targeted architecture
#endif