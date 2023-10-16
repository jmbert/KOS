#ifndef _STDIO_H
#define _STDIO_H



#if defined __cplusplus
extern "C" {
#endif

int		printf(char *fmt, ...);

int     sprintf(char *str, char *fmt, ...);

int     putchar(char c);

int     puts(char *s);

#if defined __is_kernel

#define kprintf(fmt, ...) printf(fmt, __VA_ARGS__)
#define kputchar(c) putchar(c)
#define kputs(c) puts(c)

#pragma GCC poison printf
#pragma GCC poison putchar
#pragma GCC poison puts

#endif

#if defined __iscplusplus
}
#endif

#define EOF 0

#endif