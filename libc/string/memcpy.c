#include <string.h>

#include <stdint.h>

void *memcpy(void *dest, void *src, size_t n) {
    #if defined __is_libk
    for (size_t off = 0; off < n; off++) {
        *((uint8_t*)dest+off) = *((uint8_t*)src+off);
    }

    return dest;
    #else 
    /* Unused so far, just to satisfy --pedantic */

    uint8_t *arith_dest = (uint8_t*)dest;
    uint8_t *arith_src = (uint8_t*)src;
    arith_src += n;
    arith_dest += n;

    return 0;

    #endif
}