#include <sys/cdefs.h>

#include <stdio.h>

int puts(char *s) {
    printf("%s", s);
    return 0;
}