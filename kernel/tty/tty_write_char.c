#include <tty.h>

size_t current_off;

void tty_write_char(char c) {
    if (current_off < GBUFFER_LEN) {
        ((char*)GBUFFER)[current_off] = c;
        ((char*)GBUFFER)[current_off+1] = 0x1F;
        current_off += 2;
    }

    set_cursor(current_off/2);
}