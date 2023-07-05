#include <idt/idt.h>

void set_idt_entry(size_t index, uintptr_t offset, uint16_t segselect, uint8_t flags) {
    interrupt_gate_t gate;
    gate.off_low = offset;
    gate.off_high = offset << 16;
    gate.segselect = segselect;
    gate.flags = flags;

    gate.zero = 0;
    
    idt[index] = gate;
}