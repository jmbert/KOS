/**
 * \file graphics.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __GRAPHICS_H
#define __GRAPHICS_H

#include <std/types.h>

#define COLOUR_BASE uint16_t
#define COLOUR_MAX 32768

typedef COLOUR_BASE colour_t;

typedef struct __FRAMEBUFFER {
    colour_t *addr;
    uint64_t height;
    uint64_t width;
    uint8_t bpp;
}framebuffer_t;

extern framebuffer_t framebuffer;

void set_framebuffer(void);

void init_graphics(void);

void putpixel(colour_t colour, uint64_t x, uint64_t y);

colour_t rgb(uint16_t r, uint16_t g, uint16_t b);

#endif /* __GRAPHICS_H */