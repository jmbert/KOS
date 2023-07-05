#ifndef _STDIO_H
#define _STDIO_H



#if defined __cplusplus
extern "C" {
#endif

int		printf(char *fmt, ...);

int     sprintf(char *str, char *fmt, ...);

int     putchar(char c);

int     puts(char *s);

#if defined __iscplusplus
}
#endif

#define EOF 0

#endif