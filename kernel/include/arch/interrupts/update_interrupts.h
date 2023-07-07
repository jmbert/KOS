#ifndef _UPDATE_INTERRUPTS_H
#define _UPDATE_INTERRUPTS_H

#if (HOST==i686-elf)
#include <arch/i386/idt.h>
#define UPDATE_INTERRUPTS __update_idt();
#else
#error Target architecture must implement interrupt updating
#endif

#endif