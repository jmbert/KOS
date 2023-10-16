#ifndef _IRQ_ENTRY_H
#define _IRQ_ENTRY_H

#include <arch/interrupts/isr_stackframes.h>

#define IRQ_ENTER(name) 	asm(".global " #name "_enter\n" \
								#name "_enter:\n" \
								"push %esp\n" \
								"call " #name "\n" \
								"add $0x4, %esp\n"\
								"iret")							

#define IRQ_DECL(name) void name(except_sf_t *sf)

#endif