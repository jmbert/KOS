#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

#include <kernel/tools.h>

void set_mask(uint8_t mask) {
 
    if (mask & 0xf0) {
        outb(SPIC_DAT, mask >> 0x4);
    }
    outb(MPIC_DAT, mask);        

}