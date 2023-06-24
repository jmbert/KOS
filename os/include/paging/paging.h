/**
 * \file paging.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __PAGING_H
#define __PAGING_H

#include <std/types.h>
#include <common/values.h>

#define PAGE_SIZE 4 * KiB

#define PAGE_USED 0x01
#define PAGE_UNUSED 0x00

#define KALLOC_PER_CALL 20

#define PAGEDIR_LENGTH 0x400
#define PAGETAB_LENGTH 0x400

#define PAGETAB_SIZE PAGETAB_LENGTH*PAGE_SIZE
#define PAGEDIR_SIZE PAGEDIR_LENGTH*PAGETAB_SIZE

#define PAGEALIGN_MASK 0xfffff000

#define PFRAME_DIR_FLAG_PRESENT 1 << 0
#define PFRAME_DIR_FLAG_WRITEABLE 1 << 1
#define PFRAME_DIR_FLAG_USER 1 << 2
#define PFRAME_DIR_FLAG_WRITE_CACHING 1 << 3
#define PFRAME_DIR_FLAG_CACHE_DISABLE 1 << 4
#define PFRAME_DIR_FLAG_ACCESSED 1 << 5
#define PFRAME_DIR_FLAG_DIRTY 1 << 6
#define PFRAME_DIR_FLAG_PAGE_SIZE 1 << 7
#define PFRAME_DIR_FLAG_GLOBAL 1 << 8 

#define PFRAME_TAB_FLAG_PRESENT 1 << 0
#define PFRAME_TAB_FLAG_WRITEABLE 1 << 1
#define PFRAME_TAB_FLAG_USER 1 << 2
#define PFRAME_TAB_FLAG_WRITE_CACHING 1 << 3
#define PFRAME_TAB_FLAG_CACHE_DISABLE 1 << 4
#define PFRAME_TAB_FLAG_ACCESSED 1 << 5
#define PFRAME_TAB_FLAG_DIRTY 1 << 6
#define PFRAME_TAB_FLAG_GLOBAL 1 << 7


typedef uint32_t pagedir_entry_t;

typedef uint32_t pagetable_entry_t;

typedef uintpaddr_t pageframe_t;

extern pagedir_entry_t *page_directory;

uintpaddr_t kalloc_pframe(void);

void mmap(uintpaddr_t from, uintvaddr_t to, uint64_t size);

void umap(uintvaddr_t start, uintvaddr_t end);

#endif /* __PAGING_H */