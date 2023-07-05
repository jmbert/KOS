#include <panic.h>
#include <tty.h>
#include <stdio.h>

void kernel_save(char *info_save) {
    tty_change_col(0x1F);
    printf("RECOVERED: %s\n", info_save);
}