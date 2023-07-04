#ifndef _GDT_H
#define _GDT_H

#include <stdint.h>
#include <stddef.h>

#define GDT_KERNEL_CODE 0x8
#define GDT_KERNEL_DATA 0x10
#define GDT_USER_CODE 0x18
#define GDT_USER_DATA 0x20

typedef struct __GDTR {
    uint16_t size;
    uint32_t offset;
}gdtr_t;

typedef struct __GDT_ENTRY {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_mid;
    uint8_t access_byte;
    uint8_t flags : 4;
    uint8_t limit_upper : 4;
    uint8_t base_upper;
}gdt_entry_t;

extern gdt_entry_t gdt[5];

void gdt_init(void);

void set_gdt_entry(gdt_entry_t *gdt, size_t index, uintptr_t base, uintptr_t limit, uint8_t access_byte, uint8_t flags);

void load_gdt(gdt_entry_t *gdt);

void setGdt(size_t size, gdt_entry_t* off);

void reload_segments(void);

#endif