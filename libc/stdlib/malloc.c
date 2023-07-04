#include <sys/cdefs.h>

#include <stdlib.h>

#include <stdint.h>

size_t allocd = 0;

#if defined __is_libk

#define KERNEL_HEAP_START 0xC0500000
#define KERNEL_HEAP_LENGTH 0x500000

void *kmalloc(size_t n_alloc) {
    void *new_malloc = (void*)(KERNEL_HEAP_START+allocd);
    allocd += n_alloc;
    return new_malloc;
}

#undef KERNEL_HEAP_START
#undef KERNEL_HEAP_LENGTH

#else

#define HEAP_START 0x000000
#define HEAP_LENGTH 0x500000

void *malloc(size_t n_alloc) {
    void *new_malloc = (void*)(HEAP_START+allocd);
    allocd += n_alloc;
    return new_malloc;
}

#undef HEAP_START
#undef HEAP_LENGTH

#endif