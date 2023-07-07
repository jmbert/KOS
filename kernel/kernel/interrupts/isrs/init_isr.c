#include <kernel/interrupts/init_isr.h>

static void register_exceptions(void) {

    for (size_t vec = 0; vec < EXCEPTION_ISRS; vec++) {
        register_isr(no_handler_enter, vec);
    }
    

    register_isr(division_error_enter,	DIVERR);
	register_isr(debug_exception_enter,	DEBUG);
	register_isr(invalid_opcode_enter,	INVOP);
}

void init_isr(void) {
    register_exceptions();
}