#include <tty.h>

#include <tools.h>

size_t get_cursor(void) {
    size_t pos = 0;
    outb(0x0F, VGA_PORT_1);
    pos |= inb(VGA_PORT_2);
    outb(0x0E, VGA_PORT_1);
    pos |= ((size_t)inb(VGA_PORT_2)) << 8;
    return pos;
}