#include <kernel/tty.h>

void scroll_down(void) {
	for (size_t y = 0; y < HEIGHT; y++) {
		for (size_t x = 0; x < WIDTH; x+=2) {
			((char*)GBUFFER)[y * WIDTH + x]= ((char*)TBUFFER)[(y+1)*WIDTH + x];
		}
	}
}