
#include <kernel/tty.h>

int waiting_for_char;

int tty_get_char(void) {
    return ((unsigned char*)TBUFFER)[current_off-2];
}