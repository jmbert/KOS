#ifndef _INIT_ISR_H
#define _INIT_ISR_H

#include <kernel/interrupts/exceptions.h>
#include <kernel/interrupts/isr_table.h>

EXCEPTION_ENTRY_C(division_error_enter);
EXCEPTION_ENTRY_C(debug_exception_enter);
EXCEPTION_ENTRY_C(invalid_opcode_enter);

void init_isr(void);

#endif