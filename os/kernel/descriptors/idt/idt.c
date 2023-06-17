/**
 * \file idt.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <descriptors/idt/idt.h>

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    gate_desc_t* descriptor = &idt[vector];
 
    descriptor->isr_offset_lower        = (uint32_t)isr & 0xFFFF;
    descriptor->segselect      = 0x08; // this value can be whatever offset your kernel code selector is in your GDT
    descriptor->access_byte     = flags;
    descriptor->isr_offset_higher       = (uint32_t)isr >> 16;
    descriptor->reserved       = 0;
}
extern void* isr_stub_table[];

void init_idt() {
    uint32_t offset = ((uint32_t)&idt[0]);
    idtr.offset_lower = offset;
    idtr.offset_higher = offset >> 16;
    idtr.size = (uint16_t)sizeof(gate_desc_t) * 255;
 
    for (uint8_t vector = 0; vector < 32; vector++) {
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
    }
 
    __asm__ volatile ("lidt %0" : : "m"(idtr)); // load the new IDT
    __asm__ volatile ("sti"); // set the interrupt flag
}