#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>

#if defined __cplusplus
extern "C" {
#endif

#if defined __is_libk

#define KERNEL_HEAP_START 0xC0500000
#define KERNEL_HEAP_LENGTH 0x500000

void	*kmalloc(size_t n_alloc);

#elif defined __is_kernel

#define KERNEL_HEAP_START 0xC0500000
#define KERNEL_HEAP_LENGTH 0x500000

void	*kmalloc(size_t n_alloc);

#else

#define HEAP_START 0x000000
#define HEAP_LENGTH 0x500000

void	*malloc(size_t n_alloc);

#endif

#if defined __iscplusplus
}
#endif

#endif