#ifndef _IDT_H
#define _IDT_H

#include <stdint.h>
#include <stddef.h>

typedef struct __IDTR {
    uint16_t size;
    uint16_t offset_low;
    uint16_t offset_high;
}idtr_t;

typedef struct __IDT_ENTRY {
    uint16_t off_low;
    uint16_t segselect;
    uint8_t zero;
    uint8_t flags;
    uint16_t off_high;
}interrupt_gate_t;

extern interrupt_gate_t idt[256];

void set_idt_entry(size_t index, uintptr_t offset, uint16_t segselect, uint8_t flags);

void idt_init();

#endif