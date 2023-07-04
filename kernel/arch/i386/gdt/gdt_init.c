#include <gdt.h>

extern void (setGdt)(size_t, gdt_entry_t*); /* From load_gdt.S */

gdt_entry_t gdt[5];

void gdt_init(void) {
    set_gdt_entry(gdt, 0, 0, 0, 0, 0); /* Null entry */
    set_gdt_entry(gdt, 1, 0, 0xFFFFF, 0x9A, 0xC); /* Kernel Code Segment */
    set_gdt_entry(gdt, 2, 0, 0xFFFFF, 0x92, 0xC); /* Kernel Data Segment */
    set_gdt_entry(gdt, 3, 0, 0xFFFFF, 0xFA, 0xC); /* Userspace Code Segment */
    set_gdt_entry(gdt, 4, 0, 0xFFFFF, 0xF2, 0xC); /* Userspace Data Segment */

    setGdt(sizeof(gdt_entry_t)*5, gdt);
}