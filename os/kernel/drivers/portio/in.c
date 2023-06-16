/**
 * \file in.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <drivers/portio.h>

uint8_t port_in(uint16_t port) {
    uint8_t byte;
    __asm__("inb %1, %0;"
             : "=a"(byte)
             : "Nd"(port));
    return byte;
}