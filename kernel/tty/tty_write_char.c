#include <kernel/tty.h>

size_t current_off;

size_t scrolls = 0;

uint16_t special_flags[GBUFFER_LEN];

int tty_write_char(char c) {

	if (c == '\n') {
		special_flags[current_off] = current_off%WIDTH << 8 | 0x1;
		tty_newline();
		return 0;
	}
	
	if (c == '\t') {
		for (int i = 0;i < TAB_LEN;i++) {
			tty_write_char(' ');
		}
		return 0;
	}

	if (c == '\b') {
		current_off-= 2;
		((char*)TBUFFER)[current_off] = ' ';
		return 0;
	}
	
	if (current_off > GBUFFER_LEN) {
		scroll_down();
		
		current_off -= WIDTH;
	}

	((char*)TBUFFER)[current_off] = c;
	current_off += 2;

	*(size_t*)0xc0070000 = current_off;
	*(size_t*)0xc0070010 = GBUFFER_LEN;

	set_cursor(current_off/2);

	return 0;
}