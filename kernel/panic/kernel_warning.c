#include <panic.h>
#include <tty.h>
#include <stdio.h>

void kernel_warning(char *warning) {
    tty_change_col(0x5F);
    printf("WARNING: %s\n", warning);
    
}