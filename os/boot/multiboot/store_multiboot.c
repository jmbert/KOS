/**
 * \file store_multiboot.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <gnu/multiboot.h>
#include <common/vars.h>
#include <common/tools.h>

void store_multiboot(multiboot_info_t *m2info) {
    *boot_info = *m2info;
}