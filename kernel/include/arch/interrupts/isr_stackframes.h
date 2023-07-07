#ifndef _ISR_STACKFRAMES_H
#define _ISR_STACKFRAMES_H

#include <arch/wordsize.h>

#if (WORDSIZE==32)
typedef struct __EXCEPTION_STACKFRAME {
    uword_t     ret_addr;
    uword_t     cs;
    uword_t     eflags;
}except_sf_t;
#elif (WORDSIZE==64)
typedef struct __EXCEPTION_STACKFRAME {
    /*
        64-bit interrupt stackframe
    */
}except_sf_t;
#endif

#endif