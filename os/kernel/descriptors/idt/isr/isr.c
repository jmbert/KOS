/**
 * \file isr.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <descriptors/idt/idt.h>

extern void exception_handler(uint8_t irq) {
    *(uint32_t*)0x70000 = irq;
    __asm__ volatile ("cli; hlt"); // Completely hangs the computer
}