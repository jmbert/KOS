/**
 * \file main.c
 * \author AUTHOR 
 * \brief Program control passed to by boot.s
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <std/types.h>
#include <common/vars.h>
#include <graphics/graphics.h>
#include <descriptors/gdt/gdt.h>
#include <descriptors/idt/idt.h>

/**
 * \fn kinit 
 * 
 * \brief Initialises the kernel, called by boot.s. Passes control to \ref kmain after.
 * 
*/
void kinit() {

    init_gdt();

    init_idt();

    init_graphics();

    kmain();
    return;
}

/**
 * \fn kmain
 * 
 * \brief Contains the main program flow. Called at the end of \ref kinit
 */
void kmain(void) {
    

    draw_rect(rgb(31, 16, 31), (rect_t){0, 0, 100, 100});

    return;
}