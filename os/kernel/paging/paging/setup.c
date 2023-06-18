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


static void load_page_table(pagetable_entry_t page_tab[1024], pagedir_entry_t page_dir[1024], uint16_t index) {
    page_dir[index] |= (uintphysaddr_t)page_tab | (PFRAME_DIR_FLAG_PRESENT | PFRAME_DIR_FLAG_WRITEABLE);
}

extern load_page_dir(pagedir_entry_t page_directory[1024]);

extern enable_paging(void);

void init_paging(void) {

    setup_directory(page_directory);
    
    mmap(0, 0, KERNEL_SIZE + MiB); /* Identity maps first Megabyte and Kernel */

    mmap(KERNEL_START, 0xC0000000, KERNEL_SIZE); /* Map the kernel to 0xC0000000 */

    mmap(boot_info->framebuffer_addr, boot_info->framebuffer_addr, boot_info->framebuffer_width*boot_info->framebuffer_height*boot_info->framebuffer_bpp); /* Identity map the framebuffer */
    
    load_page_dir(page_directory);
}