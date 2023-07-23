#ifndef _TTY_H
#define _TTY_H

#include <stdint.h>
#include <stddef.h>

#define TBUFFER GBUFFER

#define GBUFFER_LEN (WIDTH*HEIGHT)

#define VGA_PORT_1 0x3d4
#define VGA_PORT_2 0x3d5

extern size_t current_off; 

int tty_write_char(char c);

void tty_newline(void);

void tty_change_col(uint8_t new_col);

void set_cursor(size_t new);

size_t get_cursor(void);

void enable_cursor(void);

void disable_cursor(void);

void scroll_down(void);

void scroll_up(void);

#endif