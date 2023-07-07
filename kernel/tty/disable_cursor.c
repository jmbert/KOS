#include <kernel/tty.h>
#include <kernel/tools.h>

void disable_cursor(void) {
    outb(0x0a, VGA_PORT_1);
    outb(0x20, VGA_PORT_2);
}