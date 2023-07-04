#include <tty.h>

#include <tools.h>

void set_cursor(size_t new) {
	outb(0x0F, 0x3D4);
	outb((uint8_t) (new & 0xFF), 0x3D5);
	outb(0x0E, 0x3D4);
	outb((uint8_t) ((new >> 8) & 0xFF), 0x3D5);
}