/**
 * \file out.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <std/types.h>

void port_out(uint8_t byte, uint16_t port) {
    __asm__("outb %0, %1;"
             :: "a"(byte), "dN"(port));
}