#include <string.h>

#include <stdint.h>

int memcmp(const void *s1, const void *s2, size_t n) {
    #if defined __is_libk
    uint8_t *arith_s1 = (uint8_t*)s1;
    uint8_t *arith_s2 = (uint8_t*)s2;

    for (size_t off = 0; off < n; off++) {
        if (arith_s1+off != arith_s2+off) {
            return 0;
        }
    }
    return 1;
    #else 

    /* Unused so far, just to satisfy --pedantic */

    uint8_t *arith_s1 = (uint8_t*)s1;
    uint8_t *arith_s2 = (uint8_t*)s2;
    arith_s1 += n;
    arith_s2 += n;

    return 0;
    #endif
}