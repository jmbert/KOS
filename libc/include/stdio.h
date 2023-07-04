#ifndef _STDIO_H
#define _STDIO_H



#if defined __cplusplus
extern "C" {
#endif

#if defined __is_libk

void write_character(char c);

#endif

int    printf(char *s, ...);

int    putchar(char c);

int    puts(char *s);

#if defined __iscplusplus
}
#endif

#define EOF 0

#endif