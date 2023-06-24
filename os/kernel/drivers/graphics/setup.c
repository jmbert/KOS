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

#include <graphics/graphics.h>
#include <common/vars.h>
#include <common/tools.h>
#include <paging/paging.h>

void init_graphics(void) {
    set_framebuffer();
    
    mmap(framebuffer.addr, FRAMEBUFFER_START, framebuffer.width*framebuffer.height*framebuffer.bpp);
    
}

void set_framebuffer(void) {
    framebuffer.addr = FRAMEBUFFER_START;
    framebuffer.height = boot_info->framebuffer_height;
    framebuffer.width = boot_info->framebuffer_width;
    framebuffer.bpp = boot_info->framebuffer_bpp;
}