#include <kernel/interrupts/init_isr.h>

static void register_exceptions(void) {
    register_isr(division_error_enter,	DIVERR);
	register_isr(debug_exception_enter,	DEBUG);
	register_isr(invalid_opcode_enter,	INVOP);
}

void init_isr(void) {
    register_exceptions();
}