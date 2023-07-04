#include <tools.h>

void outb(uint8_t val, uint16_t port) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) :"memory");
}