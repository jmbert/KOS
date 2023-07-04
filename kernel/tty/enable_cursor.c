#include <tty.h>

#include <tools.h>

void enable_cursor(void) {
    outb(0x0A, VGA_PORT_1);
	outb((inb(VGA_PORT_2) & 0xC0) | 14, VGA_PORT_2);
 
	outb(0x0B, VGA_PORT_1);
	outb((inb(VGA_PORT_2) & 0xE0) | 15, VGA_PORT_2);
}