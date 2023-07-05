#ifndef _PANIC_H
#define _PANIC_H

void kernel_panic(char *err) __attribute__((noreturn));

void kernel_warning(char *warning);

#endif