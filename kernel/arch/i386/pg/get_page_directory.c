#include <pg/pg_tools.h>

pframe_t *get_page_directory(void) {
    pframe_t *pdir;
    asm("push %%eax\n"
        "mov %%cr3, %%eax\n"
        "mov %%eax, %0\n"
        "pop %%eax\n"
        :
        "=m"(pdir));
    return pdir;
}