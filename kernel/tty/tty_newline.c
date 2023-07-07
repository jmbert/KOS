#include <kernel/tty.h>

void tty_newline(void) {
    size_t current_line = current_off/WIDTH;
    current_off = (current_line+1)*WIDTH;
}