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

#include <common/tools.h>
#include <std/types.h>

void halt(void) {
    __asm__ volatile ("cli;hlt");
}

void enable_interrupts(void) {
    __asm__ volatile ("sti");
}

void disable_interrupts(void) {
    __asm__ volatile ("cli");
}