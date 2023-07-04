#include <pg/pg_map.h>
#include <pg/pg_defs.h>
#include <pg/pg_tools.h>
#include <pg/pframe.h>

extern uintptr_t __KERNEL_END;

void kmap_pages(uintptr_t to, uintptr_t from, size_t pages, uint8_t flags) {

    size_t table_index = to / (PG_TABLE_LEN_SMALL*PG_SIZE_SMALL);
    size_t end_table_index = table_index + pages/PG_TABLE_LEN_SMALL;

    size_t page_index = to / PG_SIZE_SMALL;
    size_t end_page_index = page_index + pages;

    for (;table_index <= end_table_index;table_index++) {
        pframe_t table = get_page_directory()[table_index];

        if (!(table & 0x1)) {
            table = kalloc_pframe();              /* Present and writeable directory */
            get_page_directory()[table_index] = table | 0x3;
        }
    
        size_t page_offset = page_index-(table_index*PG_TABLE_LEN_SMALL);

        for (;page_offset < PG_TABLE_LEN_SMALL && page_index < end_page_index;page_index++, page_offset++, from += PG_SIZE_SMALL) {
            ((pframe_t*)(table + PG_STRUCTS_START - 0x200000))[page_offset] = from | flags;
        }
    }
    
}