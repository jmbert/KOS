/**
 * \file tools.h
 * \author AUTHOR 
 * \brief 
 * \version VERSION
 * \date DATE
 * 
 * \copyright COPYRIGHT
 * 
 */

#ifndef __COMMON_TOOLS_H
#define __COMMON_TOOLS_H

#include <std/types.h>

void halt(void);

void enable_interrupts(void);

void disable_interrupts(void);

void write_8(uint8_t val, uintvaddr_t address);

void write_16(uint16_t val, uintvaddr_t address);

void write_32(uint32_t val, uintvaddr_t address);

void write_64(uint64_t val, uintvaddr_t address);

uint8_t read_8(uintvaddr_t address);

uint16_t read_16(uintvaddr_t address);

uint32_t read_32(uintvaddr_t address);

uint64_t read_64(uintvaddr_t address);

void memcpy(uintvaddr_t src, uintvaddr_t dest, uint64_t size);

#endif /* __COMMON_TOOLS_H */