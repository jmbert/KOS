#include <string.h>

#include <stdint.h>

int memcmp(const void *s1, const void *s2, size_t n) {
    #if defined __is_libk
    for (size_t off = 0; off < n; off++) {
        if (s1+off != s2+off) {
            return 0;
        }
    }
    return 1;
    #else 

    #endif
}