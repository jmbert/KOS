#include <arch/i386/pg/pg_tools.h>
#include <arch/i386/pg/pg_defs.h>

#include <kernel/tools.h>

size_t __KERNEL_END = 0xc0200000;

pframe_t *get_page_directory(void) {
    //pframe_t *pdir = (pframe_t*)get_ctrl_reg_3();
    return (pframe_t*)PG_STRUCTS_START;
}