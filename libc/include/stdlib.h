#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>

#if defined __cplusplus
extern "C" {
#endif

#if defined __is_kernel

void	*kmalloc(size_t n_alloc);

#else

void	*malloc(size_t n_alloc);

#endif

#if defined __iscplusplus
}
#endif

#endif