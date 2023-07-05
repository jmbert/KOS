#include <sys/cdefs.h>

#include <stdlib.h>

#include <stdint.h>

size_t allocd = 0;

#if defined __is_libk

void *kmalloc(size_t n_alloc) {
    void *new_malloc = (void*)(KERNEL_HEAP_START+allocd);
    allocd += n_alloc;
    return new_malloc;
}

#else

void *malloc(size_t n_alloc) {
    void *new_malloc = (void*)(HEAP_START+allocd);
    allocd += n_alloc;
    return new_malloc;
}

#endif