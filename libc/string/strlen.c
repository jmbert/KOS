#include <string.h>

#include <stdint.h>

size_t strlen(const char *s) {
    #if defined __is_libk
    for (size_t len = 0;;len++) {
        if (s[len] == '\0') {
            return len;
        }
    }
    #else 

    /* Unused, just to satisfy --pedantic */

    s++;

    return 0;

    #endif
}