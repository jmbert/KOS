#include <multiboot2.h>

#include <kernel/init.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <tty.h>

void kernel_main(void) {

}

void kernel_init(multiboot_info_t *minfo) {
    arch_init(minfo);

    tty_change_col(0x1F);

    kernel_main();
}