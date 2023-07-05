#include <pg/pframe.h>
#include <pg/pg_defs.h>

extern uintptr_t __KERNEL_END;

uint8_t framemap[8192];

pframe_t kalloc_pframe(void) {
    size_t i = 3;
    for (;framemap[i] == PAGE_USED;i++);
    framemap[i] = PAGE_USED;
    return (0x200000 + (i * PG_SIZE_SMALL));
}