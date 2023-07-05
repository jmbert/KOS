#include <stdint.h>
#include <stdio.h>


#if (HOST==i686-elf)
#include <idt/exception_handler.h>
void exception_handler(uint16_t irq) {
    return;
}
#else
#error Exception Handling must be implemented in this targeted architecture
#endif