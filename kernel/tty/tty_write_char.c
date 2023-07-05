#include <tty.h>

size_t current_off;

int tty_write_char(char c) {
    if (current_off < GBUFFER_LEN) {
        ((char*)GBUFFER)[current_off] = c;
        current_off += 2;
    }

    set_cursor(current_off/2);

    return 0;
}