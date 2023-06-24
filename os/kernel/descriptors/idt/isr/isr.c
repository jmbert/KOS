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
#include <descriptors/idt/isr.h>
#include <common/values.h>

void interrupt_handler(uint8_t error, uint8_t irq) {

    switch (irq)
    {
    default:
        break;
    }

    if (error) {
        __asm__ volatile ("cli; hlt"); // Completely hangs the computer
    }
    
}