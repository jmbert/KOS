#ifndef _PANIC_H
#define _PANIC_H

#include <stdint.h>
#include <stdio.h>

#if (MODE==0)
#include <kernel/tty.h>

#define PANIC_SCHEME 0x4f
#define WARN_SCHEME 0xdf
#define KERNEL_PANIC(ERR_FMT, ...)  tty_change_col(PANIC_SCHEME); \
									printf("PANIC: "#ERR_FMT"\n", __VA_ARGS__); \
									asm("cli;hlt"); \
									for (;;);               /* So any noreturn functions will recognise a panic as noreturn */
#define KERNEL_WARN(WARN_FMT, ...)  tty_change_col(WARN_SCHEME); \
									printf("WARNING: "#WARN_FMT"\n", __VA_ARGS__); 
#else
#error Graphics mode unimplemented
#endif

#endif