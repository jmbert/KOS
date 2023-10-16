#ifndef _PIC_DEFS_H
#define _PIC_DEFS_H

#define MPIC 		0x20
#define MPIC_CMD 	MPIC
#define MPIC_DAT 	MPIC | 1

#define SPIC 		0xA0
#define SPIC_CMD 	SPIC
#define SPIC_DAT 	SPIC | 1

enum {
	PIT_IRQ				=   0,
	KEY_IRQ				=   1 << 0x0,
	SPIC_IRQ			=   1 << 0x1,
	COM2_IRQ			=   1 << 0x2,
	COM1_IRQ			=   1 << 0x3,
	LPT2_IRQ			= 	1 << 0x4,
	FLOPPY_IRQ			=   1 << 0x5,
	LPT1_IRQ			=   1 << 0x6,
	CMOS_RTC_IRQ		=   1 << 0x7,
	FREE_PERI_1_IRQ		=   1 << 0x8,
	LEGACY_SCSI_IRQ     =   1 << 0x8,
	NIC_1_IRQ           =   1 << 0x8,
	FREE_PERI_2_IRQ		=	1 << 0x9,
	SCSI_1_IRQ          =   1 << 0x9,
	NIC_2_IRQ           =   1 << 0x9,
	FREE_PERI_3_IRQ		=   1 << 0xa,
	SCSI_2_IRQ          =	1 << 0xa,
	NIC_3_IRQ           = 	1 << 0xa,
	MOUSE_IRQ			=   1 << 0xb,
	FPU_IRQ				=   1 << 0xc,
	COPROC_IRQ          =	1 << 0xc,
	INTERPROC_IRQ       =	1 << 0xc,
	PRIM_ATA_HD_IRQ		=	1 << 0xd,
	SECO_ATA_HD_IRQ		=	1 << 0xe,
};

#define INIT_ICW1       0x10

#define ICW1_ICW4	    0x01		/* Indicates that ICW4 will be present */
#define ICW1_SINGLE	    0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	    0x08		/* Level triggered (edge) mode */

#define ICW4_8086	    0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	    0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	    0x10		/* Special fully nested (not) */

#define PIC_EOI			0x20

#define MPIC_IRQVECS	0x20
#define SPIC_IRQVECS	MPIC_IRQVECS+0x8

#endif