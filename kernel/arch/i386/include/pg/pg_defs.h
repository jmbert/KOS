#ifndef _PG_DEFS_H
#define _PG_DEFS_H

#define PG_STRUCTS_START    0xd0000000
#define PG_STRUCT_MAX       0x0FFFFFFFF

#define PG_SIZE_SMALL       0x1000
#define PG_TABLE_LEN_SMALL  0x400

#define KERNEL_PAGE_DIRECTORY ((pframe_t*)PG_STRUCTS_START)

#define PFRAME_ALIGN_MASK 	0xfffff000

#endif