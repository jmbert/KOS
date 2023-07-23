#ifndef _TOOLS_H
#define _TOOLS_H

#include <stdint.h>
#include <stddef.h>

#include <arch/wordsize.h>
#include <macros.h>

#define LEN(A) sizeof(A)/sizeof(A[0])

void    write(uint8_t *buf, uint8_t *where, size_t n);
void    read(uint8_t *buf, uint8_t *from, size_t n);

void    outb(uint8_t val, uint16_t port); 

uint8_t inb(uint16_t port); 

#define FGET_REGISTER_DECL(reg) uword_t CONCAT(get_reg_, reg)(void);

#define FGET_REGISTER(reg) uword_t CONCAT(get_reg_, reg)(void) {   \
            uword_t out;                                            \
            asm("mov %%" #reg ", %0" : "=m"(out));                   \
            return out;                                             \
}

FGET_REGISTER_DECL(eax);
FGET_REGISTER_DECL(ebx);
FGET_REGISTER_DECL(ecx);
FGET_REGISTER_DECL(edx);

FGET_REGISTER_DECL(esp);
FGET_REGISTER_DECL(ebp);

FGET_REGISTER_DECL(esi);
FGET_REGISTER_DECL(edi);

#undef FGET_REGISTER_DECL

#if (HOST==i386-elf)

#define FGET_CTRL_REGISTER_DECL(reg_n) uword_t CONCAT(get_ctrl_reg_, reg_n)(void);

#define FGET_CTRL_REGISTER(reg_n) uword_t CONCAT(get_ctrl_reg_, reg_n)(void) {   \
            uword_t out;                                            \
            asm("mov %%cr" #reg_n ", %%eax\n"   \
                "mov %%eax, %0\n" \
                :   \
                "=m"(out));                   \
            return out;                                             \
}

FGET_CTRL_REGISTER_DECL(0)
FGET_CTRL_REGISTER_DECL(2)
FGET_CTRL_REGISTER_DECL(3)
FGET_CTRL_REGISTER_DECL(4)

#undef FGET_CTRL_REGISTER_DECL

#else

#define FGET_CTRL_REGISTER(reg_n) #define CONCAT(get_ctrl_reg_, reg_n) #error \
Target Architecture does not support control registers, consider changing this code to add relevant support.

#endif

#endif