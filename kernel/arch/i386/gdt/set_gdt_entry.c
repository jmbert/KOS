#include <arch/i386/gdt.h>

void set_gdt_entry(gdt_entry_t *gdt, size_t index, uintptr_t base, uintptr_t limit, uint8_t access_byte, uint8_t flags) {
    gdt_entry_t entry;

    entry.access_byte = access_byte;

    entry.flags = flags;

    entry.limit_low = limit;
    entry.base_low = base;

    entry.limit_upper = limit >> 16;
    entry.base_mid = base >> 16;
    entry.base_upper = base >> 24;

    gdt[index] = entry;
}