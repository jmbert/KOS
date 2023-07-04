#include <tty.h>

void tty_change_col(uint8_t new_colour) {
    for (size_t i = 1; i < GBUFFER_LEN;i+=2) {
        ((char*)GBUFFER)[i] = new_colour;
    }
}