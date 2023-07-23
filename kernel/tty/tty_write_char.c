#include <kernel/tty.h>

size_t current_off;

size_t scrolls = 0;

int tty_write_char(char c) {

	if (c == '\n') {
		tty_newline();
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