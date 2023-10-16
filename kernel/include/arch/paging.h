#ifndef _GENERAL_PAGING_H
#define _GENERAL_PAGING_H


#include <stddef.h>

#if (HOST==i386)

extern size_t __KERNEL_START;

#define __KERNEL_START __KERNEL_START

#include <arch/i386/pg/pg_defs.h>
#include <arch/i386/pg/pg_tools.h>
#include <arch/i386/pg/pg_map.h>
#include <arch/i386/pg/pframe.h>

#define KALLOC_FRAME()                              kalloc_pframe()
#define MAP_PAGES(_to, _from, _n_pages, _flags)     kmap_pages(_to, _from, _n_pages, _flags)

#define PG_SIZE PG_SIZE_SMALL

#else
#error Target Architecture must support paging
#endif

#endif