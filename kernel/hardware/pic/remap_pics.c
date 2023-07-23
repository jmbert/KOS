#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

#include <kernel/tools.h>

void remap_pics(uint16_t master_offset, uint16_t slave_offset) {
    outb(INIT_ICW1 | ICW1_ICW4, MPIC_CMD);
    outb(INIT_ICW1 | ICW1_ICW4, MPIC_CMD);

    outb(master_offset, MPIC_DAT);
    outb(slave_offset, SPIC_DAT);

    outb(SPIC_IRQ, MPIC_DAT);
    outb(2, SPIC_DAT);

#if (HOST==i386)
    outb(ICW4_8086, MPIC_DAT);
    outb(ICW4_8086, SPIC_DAT);
#else
#error PIC not compatible with non-x86 and non-x80 products
#endif

    outb(0xff, MPIC_DAT);
    outb(0xff, SPIC_DAT);
}