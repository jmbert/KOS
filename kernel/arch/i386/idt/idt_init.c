#include <idt.h>
#include <gdt.h>

#include <string.h>

extern void *isr_stub_table[];

idtr_t idtr;

//#error Stuff happening here, maybe being overwritten? Can't tell

void idt_set_descriptor(uint8_t vector, void* isr, uint8_t flags) {
    interrupt_gate_t *gate = &idt[vector];
 
    gate->off_low        = (uint32_t)isr & 0xFFFF;
    gate->segselect      = GDT_KERNEL_CODE; // this value can be whatever offset your kernel code selector is in your GDT
    gate->flags            = flags;
    gate->off_high       = (uint32_t)isr >> 16;
    gate->zero          = 0;
}

void idt_init() {
    idtr.offset_low = (uint32_t)&idt[0];
    idtr.offset_high = ((uint32_t)&idt[0]) >> 16;
    idtr.size = (uint16_t)sizeof(interrupt_gate_t) * 0x20 - 1;
 
    for (uint8_t vector = 0; vector < 0x20; vector++) {
        
        idt_set_descriptor(vector, isr_stub_table[vector], 0x8E);
        
    }

    memcpy((uint8_t*)0xc0070000, (uint8_t*)(&idtr), sizeof(idtr_t));
    
 
    __asm__ volatile ("lidt %0" : : "m"(idtr)); // load the new IDT
    __asm__ volatile ("sti"); // set the interrupt flag
}