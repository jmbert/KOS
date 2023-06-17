/**
 * \file gdt.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __GDT_H
#define __GDT_H

#include <std/types.h>

typedef struct __GDT_REGISTER {
    uint16_t size;
    uint32_t offset;
}gdtr_t;

typedef struct __GDT_ENTRY {
    uint16_t limit_lower;
    uint16_t base_lower;
    uint8_t base_middle;
    uint8_t access_byte;
    uint8_t flags_limit_upper;
    uint8_t base_upper;
}gdt_entry_t;

extern gdt_entry_t gdt[];

extern gdtr_t *gdtr;

void init_gdt(void);

#endif /* __GDT_H */