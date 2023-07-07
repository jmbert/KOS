#ifndef _IDT_H
#define _IDT_H

#include <stdint.h>

#include <kernel/interrupts/isr_table.h>

#define INTERRUPT_NORMAL_FLAGS  0x8E
#define INTERRUPT_TRAP_FLAGS    0x8F
#define INTERRUPT_TASK_FLAGS    0x85

typedef struct  __IDT_GATE {
    uint16_t    isr_low;
    uint16_t    seg_select;
    uint8_t     zero;
    uint8_t     flags;
    uint16_t    isr_high;
}idt_gate_t;

typedef struct  __IDTR {
    uint16_t    size;
    uint16_t    off_low;
    uint16_t    off_high;
}idtr_t;

extern idt_gate_t idt[MAX_ISRS];

void    idt_init(void);

void    __update_idt(void);

#endif