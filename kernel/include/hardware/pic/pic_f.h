#ifndef _PIC_F_H
#define _PIC_F_H

#include <stdint.h>

void remap_pics(uint16_t master_offset, uint16_t slave_offset);

void set_mask(uint8_t mask);

void pic_send_eoi(uint8_t irq);

#endif