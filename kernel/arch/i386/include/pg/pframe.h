#ifndef _PFRAME_H
#define _PFRAME_H

#include <pg/pg_types.h>

#define PAGE_USED 1
#define PAGE_UNUSED 0

pframe_t    kalloc_pframe(void);
pframe_t    kfree_pframe(void);

#endif