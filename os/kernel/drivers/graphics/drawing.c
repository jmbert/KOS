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

void draw_rect(colour_t colour, rect_t rect) {
    for (int x = 0; x < rect.width; x++) {
        for (int y = 0; y < rect.height; y++) {
            putpixel(colour, rect.x_off+x, rect.y_off+y);
        }
    }
}