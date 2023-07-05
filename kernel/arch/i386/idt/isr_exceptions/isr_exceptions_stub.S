.extern exception_handler
.macro isr_exception irq
isr_exception_\irq:
	push %esp				/* Pass pointer to the interrupt stack frame */
	push $\irq				/* Pass interrupt number */
	call exception_handler
	pop %eax          		/* Get argument off of stack */
	iret
.endm

isr_exception 0x0
isr_exception 0x1
isr_exception 0x2
isr_exception 0x3
isr_exception 0x4
isr_exception 0x5
isr_exception 0x6
isr_exception 0x7
isr_exception 0x8
isr_exception 0x9
isr_exception 0xa
isr_exception 0xb
isr_exception 0xc
isr_exception 0xd
isr_exception 0xe
isr_exception 0xf
isr_exception 0x10
isr_exception 0x11
isr_exception 0x12
isr_exception 0x13
isr_exception 0x14
isr_exception 0x15
isr_exception 0x16
isr_exception 0x17
isr_exception 0x18
isr_exception 0x19
isr_exception 0x1a
isr_exception 0x1b
isr_exception 0x1c
isr_exception 0x1d
isr_exception 0x1e
isr_exception 0x1f

.global isr_stub_table
isr_stub_table:
.long isr_exception_0x0
.long isr_exception_0x1
.long isr_exception_0x2
.long isr_exception_0x3
.long isr_exception_0x4
.long isr_exception_0x5
.long isr_exception_0x6
.long isr_exception_0x7
.long isr_exception_0x8
.long isr_exception_0x9
.long isr_exception_0xa
.long isr_exception_0xb
.long isr_exception_0xc
.long isr_exception_0xd
.long isr_exception_0xe
.long isr_exception_0xf
.long isr_exception_0x10
.long isr_exception_0x11
.long isr_exception_0x12
.long isr_exception_0x13
.long isr_exception_0x14
.long isr_exception_0x15
.long isr_exception_0x16
.long isr_exception_0x17
.long isr_exception_0x18
.long isr_exception_0x19
.long isr_exception_0x1a
.long isr_exception_0x1b
.long isr_exception_0x1c
.long isr_exception_0x1d
.long isr_exception_0x1e
.long isr_exception_0x1f