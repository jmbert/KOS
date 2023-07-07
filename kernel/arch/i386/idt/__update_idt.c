#include <arch/i386/idt.h>
#include <arch/i386/gdt.h>
#include <arch/wordsize.h>

void __update_idt(void) {
    for (size_t vec = 0; vec < MAX_ISRS; vec++) {
		idt_gate_t current_gate;
		if (vec < 0x20) {
			current_gate.flags = INTERRUPT_TRAP_FLAGS;
		} else {
			current_gate.flags = INTERRUPT_NORMAL_FLAGS;
		}

		current_gate.seg_select = GDT_KERNEL_CODE;
		uword_t isr = (uword_t)(isr_table[vec]);

		current_gate.isr_low = 	isr & 0x0000ffff;
		current_gate.isr_high = isr >> 16;

		idt[vec] = current_gate;
	}
}