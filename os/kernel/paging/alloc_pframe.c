/**
 * \file alloc_pframe.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <paging/paging.h>
#include <common/tools.h>
#include <common/vars.h>

uint8_t framemap[];

uintpaddr_t preframes[];

uintpaddr_t startframe;

uintpaddr_t kalloc_pframe(void) {
    
    startframe = 4 * MiB + 0x4000;
    
    int i = 0;
    for (;framemap[i] != PAGE_UNUSED; i++);

    framemap[i] = PAGE_USED;

    return startframe + (i * 4 * KiB);
}