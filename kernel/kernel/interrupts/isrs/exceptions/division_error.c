#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(division_error) {
    KERNEL_PANIC("Exception at 0x%X : Division Error\n", sf->ret_addr);
    return;
}

EXCEPTION_ENTER_NOCODE(division_error);