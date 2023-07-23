#ifndef _ARCH_STDINT_H
#define _ARCH_STDINT_H

#include <macros.h>
#include <stdint.h>

#define WORDSIZE \
#error Target Architecture must implement a word size

#if (HOST==i386-elf)
#undef WORDSIZE
#define WORDSIZE 32
#elif (HOST==x86_64)
#undef WORDSIZE
#define WORDSIZE 64
#endif

typedef CONCAT(CONCAT(uint, WORDSIZE), _t)  uword_t;
typedef CONCAT(CONCAT(int, WORDSIZE), _t)   word_t;

#endif