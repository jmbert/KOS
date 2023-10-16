#ifndef _INIT_ISR_H
#define _INIT_ISR_H

#include <kernel/interrupts/exceptions.h>
#include <kernel/interrupts/isr_table.h>
#include <kernel/interrupts/irqs.h>

void no_handler_enter(void);
void no_handler_code_enter(void);

void division_error_enter(void);
void debug_exception_enter(void);
void invalid_opcode_enter(void);
void page_fault_enter(void);

void keyboard_irq_enter(void);
void pit_irq_enter(void);

void init_isr(void);

#endif