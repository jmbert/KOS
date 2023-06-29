#include <string.h>

#include <stdint.h>

size_t strlen(const char *s) {
    #if defined __is_libk
    // Is in kernel
    for (size_t len = 0;;len++) {
        if (s[len] == '\0') {
            return len;
        }
    }
    #else 
    //  Not in kernel

    #endif
}