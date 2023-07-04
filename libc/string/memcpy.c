#include <string.h>

#include <stdint.h>

void *memcpy(void *dest, void *src, size_t n) {
    #if defined __is_libk
    // Is in kernel
    for (size_t off = 0; off < n; off++) {
        *((uint8_t*)dest+off) = *((uint8_t*)src+off);
    }

    return dest;
    #else 
    //  Not in kernel

    #endif
}