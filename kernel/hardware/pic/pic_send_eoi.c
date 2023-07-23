#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

#include <kernel/tools.h>

void pic_send_eoi(uint8_t irq) {
    if(irq >= 8) {
		outb(PIC_EOI, SPIC_CMD);
    }
	outb(PIC_EOI, MPIC_CMD);
}