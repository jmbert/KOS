#ifndef _PS2_F_H
#define _PS2_F_H

#include <hardware/ps2/ps2-defs.h>

#include <stdint.h>

uint8_t read_byte(void);

void write_byte(uint8_t byte);

void init_ps2(void);

#endif