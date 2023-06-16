/**
 * \file tools.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <graphics/graphics.h>
#include <std/maths.h>

colour_t rgb(uint16_t r, uint16_t g, uint16_t b) {
    return (r%exp(2, framebuffer.bpp) << 10 | g%exp(2, framebuffer.bpp) << 5 | b%exp(2, framebuffer.bpp));
}