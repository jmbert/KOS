/**
 * \file setup.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <paging/paging.h>
#include <common/values.h>
#include <common/tools.h>
#include <common/vars.h>


static void load_page_table(pagetable_entry_t *page_tab, pagedir_entry_t *page_dir, uint16_t index) {
    page_dir[index] |= (uintpaddr_t)page_tab | (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE);
}

extern load_page_dir(pagedir_entry_t *page_directory);

extern enable_paging(void);

void init_paging(void) {
    page_directory = kalloc_pframe();
    setup_directory(page_directory);
    
    
    mmap(0, 0, PAGETAB_SIZE); /* Identity maps first Megabyte and Kernel (undone later) */

    mmap(4* MiB, 4 * MiB, PAGETAB_SIZE); /* Identity maps the second page table to itself for use to store the page directory and tables */

    mmap(KERNEL_START, 0xC0000000, PAGETAB_SIZE); /* Map the kernel to 0xC0000000 */

    mmap(boot_info->framebuffer_addr, boot_info->framebuffer_addr, boot_info->framebuffer_width*boot_info->framebuffer_height*boot_info->framebuffer_bpp); /* Identity map the framebuffer */

    load_page_dir(page_directory);
}