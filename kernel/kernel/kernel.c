#include <multiboot.h>

#include <arch/init.h>

#include <kernel/tty.h>
#include <kernel/panic.h>

#include <kernel/interrupts/isr_table.h>
#include <kernel/interrupts/isrs/isr_exceptions.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

__attribute__((noreturn))
void kernel_end(void) {
	KERNEL_PANIC("Reached end of kernel execution", 0);
}

void kernel_main(void) {

}

__attribute__((noreturn))
void kernel_init(multiboot_info_t *minfo) {
	disable_cursor();
	arch_init(minfo);

	tty_change_col(0x1F);
	
	register_isr(division_error_enter,	DIVERR);
	register_isr(debug_exception_enter,	DEBUG);
	register_isr(invalid_opcode_enter,	INVOP);

	kernel_main();
	kernel_end();
}