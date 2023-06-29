#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>

#include <stddef.h>

void*	memcpy(void *dest, void *src, size_t n);
void*	memmove(void *dest, void *src, size_t n);
int		memcmp(const void *s1, const void *s2, size_t n);

size_t	strlen(const char *s);

#endif