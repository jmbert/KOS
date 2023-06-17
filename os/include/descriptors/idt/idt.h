/**
 * \file idt.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __IDT_H
#define __IDT_H

#include <std/types.h>

typedef struct __IDT_REGISTER {
    uint16_t size;
    uint16_t offset_lower;
    uint16_t offset_higher;
}idtr_t;

typedef struct __IDT_GATE_DESC {
    uint16_t isr_offset_lower;
    uint16_t segselect;
    uint8_t reserved;
    uint8_t access_byte;
    uint16_t isr_offset_higher;
}gate_desc_t __attribute__((packed));

extern idtr_t idtr;

extern gate_desc_t idt[256];

void init_idt(void);

#endif /* __IDT_H */