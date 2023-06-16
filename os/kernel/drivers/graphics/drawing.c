/**
 * \file drawing.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <graphics/graphics.h>

void putpixel(colour_t colour, uint64_t x, uint64_t y) {
    if (x > framebuffer.width || y > framebuffer.height) {
        return;
    }
    framebuffer.addr[y*framebuffer.width + x] = colour;
}