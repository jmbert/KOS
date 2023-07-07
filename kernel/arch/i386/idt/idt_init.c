#include <arch/i386/idt.h>

#ifdef DEBUG
#include <stdio.h>
#endif

idt_gate_t 	idt[MAX_ISRS];
idtr_t 		idtr;

void idt_init(void) {
	__update_idt();

	idtr.size = sizeof(idt_gate_t)*MAX_ISRS;
	idtr.off_low = 	((uintptr_t)idt) & 0x0000ffff;
	idtr.off_high = ((uintptr_t)idt) >> 16;


	asm("lidt %0\n"
		"sti"
		 :: 
		 "m"(idtr));
}