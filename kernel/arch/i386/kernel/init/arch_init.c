#include <arch/init.h>

#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/pg/pframe.h>
#include <arch/i386/pg/pg_map.h>
#include <arch/i386/pg/pg_defs.h>

#include <kernel/tty.h>

#include <stdlib.h>

void arch_init(multiboot_info_t *minfo) {
    kmap_pages(GBUFFER, minfo->framebuffer_addr, (minfo->framebuffer_bpp * minfo->framebuffer_height * minfo->framebuffer_width)/PG_SIZE_SMALL, 0x3);
    kmap_pages(KERNEL_HEAP_START, kalloc_pframe(), KERNEL_HEAP_LENGTH/PG_SIZE_SMALL, 0x3);

    gdt_init();
    idt_init();
}