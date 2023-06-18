/**
 * \file memtools.c
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

void write_8(uint8_t val, uintvaddr_t address) {
    *(uint8_t*)address = val;
}

void write_16(uint16_t val, uintvaddr_t address) {
    *(uint16_t*)address = val;
}

void write_32(uint32_t val, uintvaddr_t address) {
    *(uint32_t*)address = val;
}

void write_64(uint64_t val, uintvaddr_t address) {
    *(uint64_t*)address = val;
}

uint8_t read_8(uintvaddr_t address) {
    uint8_t val;
    val = *(uint8_t*)address;
    return val;
}

uint16_t read_16(uintvaddr_t address) {
    uint16_t val;
    val = *(uint16_t*)address;
    return val;
}

uint32_t read_32(uintvaddr_t address) {
    uint32_t val;
    val = *(uint32_t*)address;
    return val;
}

uint64_t read_64(uintvaddr_t address) {
    uint64_t val;
    val = *(uint64_t*)address;
    return val;
}

void memcpy(uintvaddr_t src, uintvaddr_t dest, uint64_t size) {
    uint64_t *src_ptr = (uint64_t*)src;
    uint64_t *dest_ptr = (uint64_t*)dest;
    for (int i = 0; i < size; i++) {
        dest_ptr[i] = src_ptr[i];
    }
}