#include <arch/i386/pg/pg_tools.h>

void set_page_directory(pframe_t * pdir) {
    asm("push %%eax\n"
        "mov %0, %%eax\n"
        "mov %%eax, %%cr3\n"
        "pop %%eax\n"
        ::
        "m"(pdir));
}