#ifndef _EXCEPTION_ENTRY_H
#define _EXCEPTION_ENTRY_H

#include <arch/interrupts/isr_stackframes.h>

enum {
	DIVERR,
	DEBUG,
	NMI,
	BRK,
	OVRFLOW,
	BNDRG,
	INVOP,
	DNA,
	DOUBLE,
	COPROC_UNUSED,
	INVTSS,
	SNP,
	SSF,
	GPF,
	PAGE_FAULT,
	x87_FPE = 0x10,
	ALIGN_CHECK,
	MACHINE_CHECK,
	SIMD_FPE,
	VIRT,
	CPE,
	HYPER_INJ = 0x1C,
	VMMCE,
	SECURITY
};

#define EXCEPTION_ENTER_NOCODE(name) 	asm(".global " #name "_enter\n" \
											#name "_enter:\n" \
											"push %esp\n" \
											"call " #name "\n" \
											"iret")
										
											
#define EXCEPTION_ENTER_CODE(name) 	asm(".global " #name "_enter\n" \
										#name "_enter:\n" \
										"mov %esp, %eax\n" \
										"sub $0x4, %eax\n" \
										"push %eax\n" \
										"call " #name "\n" \
										"add $0x8, %esp\n" \
										"iret")
										
											

#define EXCEPTION_DECL_NOCODE(name) void name(except_sf_t *sf)
#define EXCEPTION_DECL_CODE(name) 	void name(except_sf_t *sf, uword_t error_code)

#endif