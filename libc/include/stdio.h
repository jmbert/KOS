#ifndef _STDIO_H
#define _STDIO_H

#include <sys/cdefs.h>

#if defined __is_libk

void write_character(char c);

#endif

void    printf(char *s, ...);

void    putc(char c);

void    puts(char *s);

#endif