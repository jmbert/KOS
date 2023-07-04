#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>

#if defined __is_libk

void	*kmalloc(size_t n_alloc);

#else

void	*malloc(size_t n_alloc);

#endif

#endif