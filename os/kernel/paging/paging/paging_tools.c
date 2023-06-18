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

void setup_directory(pagedir_entry_t page_directory[PAGEDIR_LENGTH]) {
    for (int i = 0; i < PAGEDIR_LENGTH; i++) {
        
        page_directory[i] = (PFRAME_DIR_FLAG_PRESENT);
    }
    
}

static void mmap_table(uintphysaddr_t from, uintvaddr_t to, uint64_t size) {
    pagetable_entry_t *table = kalloc_pframe();

    uint32_t page_index = to / (PAGE_SIZE);

    uint32_t table_index = page_index / (PAGETAB_LENGTH);
    
    page_directory[table_index] = ((uintphysaddr_t)table) | (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE);
    for (uint16_t i = 0; size > 0; i++, size -= PAGE_SIZE) {
        table[i] = (from + i*PAGE_SIZE) | (PFRAME_TAB_FLAG_PRESENT | PFRAME_TAB_FLAG_WRITEABLE);
    }
}

void mmap(uintphysaddr_t from, uintvaddr_t to, uint64_t size) {

    uint32_t table_size = PAGETAB_SIZE;

    uint32_t _floor_n_tables = size/table_size;
    
    uint64_t allocd = 0;

    for (int i = 0; i <= _floor_n_tables; i++, allocd += PAGETAB_SIZE) {
        mmap_table(from+allocd, to+allocd, PAGETAB_SIZE);
    }

    if (allocd < size) {
        mmap_table(from+allocd+PAGETAB_SIZE, to+allocd+PAGETAB_SIZE, size-allocd);
    }
    
}

void umap(uintvaddr_t start, uintvaddr_t end) {
    start, end &= 0xfffff000; /* Discard offset bits */

    uint32_t start_table_index = start/(PAGETAB_LENGTH);
    uint32_t end_table_index  = end/(PAGETAB_LENGTH);
    
    pagetable_entry_t *start_table = page_directory[start_table_index] & 0xfffff000;
    pagetable_entry_t *end_table = page_directory[end_table_index] & 0xfffff000;

    if (start_table_index == end_table_index) {
        for (uint16_t pframe = start; pframe <= end; pframe++) {
            start_table[pframe] = 0 | (PFRAME_TAB_FLAG_PRESENT);
        }
        if (start == start_table_index*PAGETAB_LENGTH && end == (end_table_index+1)*PAGETAB_LENGTH) {
            page_directory[start_table_index] = 0 | (PFRAME_DIR_FLAG_PRESENT);
        }
    } else {
        for (uint16_t pframe = start; pframe < (start_table_index+1)*PAGETAB_LENGTH; pframe++) {
            start_table[pframe] = 0 | (PFRAME_TAB_FLAG_PRESENT);
        }
        if (start == start_table_index*PAGETAB_LENGTH) {
            page_directory[start_table_index] = 0 | (PFRAME_DIR_FLAG_PRESENT);
        }
        for (int table_index = start_table_index+1; table_index < end_table_index; table_index++) {
            pagetable_entry_t *table = page_directory[table_index] & 0xfffff000;
            for (uint16_t pframe = table_index*PAGETAB_LENGTH; pframe < (table_index+1)*PAGETAB_LENGTH; pframe++) {
                table[pframe] = 0 | (PFRAME_TAB_FLAG_PRESENT);
            }
            page_directory[table_index] = 0 | (PFRAME_DIR_FLAG_PRESENT);
        }
        for (uint16_t pframe = end_table_index*PAGETAB_LENGTH; pframe < end; pframe++) {
            start_table[pframe] = 0 | (PFRAME_TAB_FLAG_PRESENT);
        }
        if (end == (end_table_index+1)*PAGETAB_LENGTH) {
            page_directory[end_table_index] = 0 | (PFRAME_DIR_FLAG_PRESENT);
        }
    }
    
    
    
    
}