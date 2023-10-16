#include <multiboot.h>
#include <arch/init.h>

#include <arch/paging.h>

#include <kernel/tty.h>
#include <kernel/panic.h>
#include <macros.h>
#include <kernel/interrupts/exceptions.h>
#include <kernel/interrupts/init_isr.h>

#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

#include <hardware/ps2/ps2-f.h>

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

__attribute__((noreturn))
void kernel_end(void) {
	KERNEL_PANIC("Reached end of kernel execution", 0);
}

void kernel_main(void) {
	for (;;);
}

__attribute__((noreturn))
void kernel_init(multiboot_info_t *minfo) {
	disable_cursor();
	arch_init(minfo);

	tty_change_col(0x1F);

	init_isr();

	remap_pics(MPIC_IRQVECS, SPIC_IRQVECS);

	set_mask(0xfd);

	init_ps2();

	kernel_main();
	kernel_end();
}