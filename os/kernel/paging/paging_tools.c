/**
 * \file paging_tools.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <paging/paging.h>
#include <common/tools.h>

static void mmap_page(uint32_t page_index, uintvaddr_t to, uint8_t flags) {
    uint32_t pagetable_index = page_index/PAGETAB_LENGTH;
    uint32_t page_offset = page_index%PAGETAB_LENGTH;

    pagetable_entry_t *page_table = page_directory[pagetable_index] & PAGEALIGN_MASK;


    page_table[page_offset] = (to) | flags;
}

void mmap(uintpaddr_t from, uintvaddr_t to, uint64_t size) {
    
    write_32(from, KERNEL_HIGH_START + 0x70000);

    uint32_t page_index = to >> 12;

    uint32_t table_index = page_index/PAGETAB_LENGTH;
    uint32_t end_page_index = page_index+(size >> 12)+1;
    uint32_t end_table_index = (end_page_index/PAGETAB_LENGTH)+1;

    for (; table_index < end_table_index;table_index++) {
        if (!(page_directory[table_index] & (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE))) {
            uintpaddr_t table = kalloc_pframe();
            page_directory[table_index] = table | (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE);
        }
    }

    for (; size > 0; from += PAGE_SIZE, size -= PAGE_SIZE, page_index++) {
        mmap_page(page_index, from, (PFRAME_TAB_FLAG_PRESENT | PFRAME_TAB_FLAG_WRITEABLE));
        
    }

    
    
}

static void umap_page(uint32_t page_index) {
    
    uint32_t pagetable_index = page_index/PAGETAB_LENGTH;
    uint32_t page_offset = page_index%PAGETAB_LENGTH;

    uintvaddr_t page_address = page_index << 12;

    pagetable_entry_t *page_table = page_directory[pagetable_index] & PAGEALIGN_MASK;

    page_table[page_offset] = 0;
    invalidate_page(page_address);
}

void umap(uintvaddr_t start, uintvaddr_t end) {
    uint32_t page_index = start >> 12;
    uint32_t end_index = end >> 12;

    uint32_t table_index = page_index/PAGETAB_LENGTH;
    uint32_t end_table_index = (end_index/PAGETAB_LENGTH)+1;

    
    for (;page_index < end_index;page_index++) {
        umap_page(page_index);
    }

    for (; table_index < end_table_index;table_index++) {
        if (page_directory[table_index] & (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE)) {
            page_directory[table_index] = 0;
        }
    }
}