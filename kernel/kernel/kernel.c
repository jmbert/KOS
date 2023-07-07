#include <multiboot.h>

#include <arch/init.h>

#include <kernel/tty.h>
#include <kernel/panic.h>

#include <kernel/interrupts/init_isr.h>

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

__attribute__((noreturn))
void kernel_end(void) {
	KERNEL_PANIC("Reached end of kernel execution", 0);
}

void kernel_main(void) {
	asm("int $0x10");
}

__attribute__((noreturn))
void kernel_init(multiboot_info_t *minfo) {
	disable_cursor();
	arch_init(minfo);

	tty_change_col(0x1F);
	
	init_isr();

	kernel_main();
	kernel_end();
}