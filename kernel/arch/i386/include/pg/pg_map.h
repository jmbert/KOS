#ifndef _PG_MAP_H
#define _PG_MAP_H

#include <pg/pg_types.h>

void    kmap_pages(uintptr_t to, uintptr_t from, size_t pages, uint8_t flags);

#endif