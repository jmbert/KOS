#ifndef _EXCEPTION_ISR_H
#define _EXCEPTION_ISR_H

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
void __invalid_instr_handler(void) __attribute__((noreturn));

#endif