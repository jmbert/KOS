#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <stdint.h>

extern unsigned char keymap_normal[90];

unsigned char decode_key(uint8_t scancode);

#endif