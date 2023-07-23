#ifndef _INIT_ISR_H
#define _INIT_ISR_H

#include <kernel/interrupts/exceptions.h>
#include <kernel/interrupts/isr_table.h>

EXCEPTION_ENTRY_C(no_handler);
EXCEPTION_ENTRY_C(no_handler_code);

EXCEPTION_ENTRY_C(division_error);
EXCEPTION_ENTRY_C(debug_exception);
EXCEPTION_ENTRY_C(invalid_opcode);
EXCEPTION_ENTRY_C(page_fault);

void init_isr(void);

#endif