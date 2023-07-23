#include <kernel/interrupts/isr_table.h>
#include <arch/interrupts/update_interrupts.h>

isr_entry_fp isr_table[MAX_ISRS];

void register_isr(isr_entry_fp new_isr, size_t irq) {
	isr_table[irq] = new_isr;
	UPDATE_INTERRUPTS;
}