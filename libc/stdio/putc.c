#include <stdio.h>

#if defined __is_libk

#include <tty.h>

#endif

void putc(char c) {
    #if defined __is_libk /* In kernel space */
    #if (MODE==0) /* EGA text mode */

	tty_write_char(c);

    #else /* Linear framebuffer */

    #endif

    #else /* In userspace */

    #endif
}