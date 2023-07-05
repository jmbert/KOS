#include <panic.h>
#include <tty.h>
#include <stdio.h>

void kernel_panic(char *err, int (try_save)(uint8_t *), uint8_t *save_info) {
    tty_change_col(0x4F);
    printf("PANIC: %s\n", err);

    if (!try_save) {
        printf("FATAL: No save protocol\n");
        asm("cli;hlt");
        for (;;);
    }

    if (try_save(save_info)) {
        printf("FATAL: Failed to save\n");
        asm("cli;hlt");
        for (;;);
    } else {
        kernel_save("");
    }
    
}