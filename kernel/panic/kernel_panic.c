#include <panic.h>
#include <tty.h>
#include <stdio.h>

void kernel_panic(char *err) {
    tty_change_col(0x4F);
    printf("PANIC: %s", err);
    asm("cli;hlt");
    for (;;);
}