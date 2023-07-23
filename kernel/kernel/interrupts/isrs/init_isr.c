#include <kernel/interrupts/init_isr.h>

static void register_exceptions(void) {

	for (size_t vec = 0; vec < EXCEPTION_ISRS; vec++) {
		switch (vec)
		{
		case DOUBLE:
		case INVTSS:
		case SNP:
		case SSF:
		case GPF:
		case PAGE_FAULT:
		case ALIGN_CHECK:
		case CPE:
		case VMMCE:
		case SECURITY:
			register_isr(no_handler_code_enter, vec);
			break;
		
		default:
			register_isr(no_handler_enter, vec);
			break;
		}
	}
	

	register_isr(division_error_enter,	DIVERR);
	register_isr(debug_exception_enter,	DEBUG);
	register_isr(invalid_opcode_enter,	INVOP);
	register_isr(page_fault_enter,      PAGE_FAULT);
}

void init_isr(void) {
	register_exceptions();
}