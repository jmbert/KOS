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

/**
 * \fn kinit 
 * 
 * \brief Initialises the kernel, called by boot.s. Passes control to \ref kmain after.
 * 
*/
void kinit() {

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

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            putpixel(rgb(31, 31, 31), x, y);
        }
    }
    

    return;
}