#ifndef _ISR_TABLE_H
#define _ISR_TABLE_H

#include <arch/interrupts/isr_stackframes.h>

#include <stddef.h>

#define MAX_ISRS 0x400

#define EXCEPTION_ISRS 0x20

typedef void (*isr_entry_fp)(void);

extern isr_entry_fp   isr_table[MAX_ISRS];
extern size_t       n_isrs;

void register_isr(isr_entry_fp new_isr, size_t irq);

#endif