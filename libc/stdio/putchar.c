#include <stdio.h>

#if defined __is_libk

#include <tty.h>

#endif

int putchar(char c) {
    #if defined __is_libk /* In kernel space */
    #if (MODE==0) /* EGA text mode */

	if (tty_write_char(c)) {
        return EOF;
    }

    return (int)((unsigned char)c);

    #else /* Linear framebuffer */
    /* Unused, just to satisfy --pedantic */

    c++;

    return 0;

    #endif

    #else /* In userspace */

    /* Unused, just to satisfy --pedantic */

    c++;

    return 0;

    #endif
}