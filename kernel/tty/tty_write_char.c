#include <kernel/tty.h>

size_t current_off;

int tty_write_char(char c) {

    if (c == '\n') {
        tty_newline();
        return 0;
    }

    if (current_off < GBUFFER_LEN) {
        ((char*)GBUFFER)[current_off] = c;
        current_off += 2;
    }

    set_cursor(current_off/2);

    return 0;
}