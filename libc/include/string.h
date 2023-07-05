#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

#if defined __cplusplus
extern "C" {
#endif

void*	memcpy(void *dest, void *src, size_t n);
void*	memmove(void *dest, void *src, size_t n);
int		memcmp(const void *s1, const void *s2, size_t n);

size_t	strlen(const char *s);

#if defined __iscplusplus
}
#endif

#endif