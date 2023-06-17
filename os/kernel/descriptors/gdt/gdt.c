/**
 * \file gdt.c
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#include <descriptors/gdt/gdt.h>

void init_gdt(void) {

    gdt_entry_t null_entry = (gdt_entry_t){0, 0, 0, 0, 0, 0, 0};
    
    gdt_entry_t kernel_code_entry = (gdt_entry_t){0xFFFFF, 0, 0, 0x9A, (0xC << 4) | (0xFFFFF >> 16), 0};

    gdt_entry_t kernel_data_entry = (gdt_entry_t){0xFFFFF, 0, 0, 0x92, (0xC << 4) | (0xFFFFF >> 16), 0};

    gdt_entry_t user_code_entry = (gdt_entry_t){0xFFFFF, 0, 0, 0xFA, (0xC << 4) | (0xFFFFF >> 16), 0};

    gdt_entry_t user_data_entry = (gdt_entry_t){0xFFFFF, 0, 0, 0xF2, (0xC << 4) | (0xFFFFF >> 16), 0};

    gdt[0] = null_entry;
    gdt[1] = kernel_code_entry;
    gdt[2] = kernel_data_entry;
    gdt[3] = user_code_entry;
    gdt[4] = user_data_entry;

    setGdt(sizeof(gdt_entry_t)*5, gdt);
}