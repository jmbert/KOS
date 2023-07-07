#include <kernel/tty.h>
#include <kernel/tools.h>

void set_cursor(size_t new) {
	outb(0x0F, VGA_PORT_1);
	outb((uint8_t) (new & 0xFF), VGA_PORT_2);
	outb(0x0E, VGA_PORT_1);
	outb((uint8_t) ((new >> 8) & 0xFF), VGA_PORT_2);
}