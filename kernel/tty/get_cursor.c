#include <tty.h>

#include <tools.h>

size_t get_cursor(void) {
    size_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((size_t)inb(0x3D5)) << 8;
    return pos;
}