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

void init_graphics(void) {
    set_framebuffer();
}

void set_framebuffer(void) {
    framebuffer.addr = boot_info->framebuffer_addr;
    framebuffer.height = boot_info->framebuffer_height;
    framebuffer.width = boot_info->framebuffer_width;
    framebuffer.bpp = boot_info->framebuffer_bpp;
}