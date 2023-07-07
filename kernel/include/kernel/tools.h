#ifndef _TOOLS_H
#define _TOOLS_H

#include <stdint.h>
#include <stddef.h>

#define LEN(A) sizeof(A)/sizeof(A[0])

void    write(uint8_t *buf, uint8_t *where, size_t n);
void    read(uint8_t *buf, uint8_t *from, size_t n);

void    outb(uint8_t val, uint16_t port); 

uint8_t inb(uint16_t port); 

#endif