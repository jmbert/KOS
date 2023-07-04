#include <kernel/init.h>

#include <gdt.h>
#include <idt.h>
#include <tty.h>

#include <pg/pg_map.h>

void arch_init(multiboot_info_t *minfo) {
    kmap_pages(GBUFFER, minfo->framebuffer_addr, (minfo->framebuffer_bpp * minfo->framebuffer_height * minfo->framebuffer_width)/0x1000, 0x3);

    gdt_init();
    idt_init();
}