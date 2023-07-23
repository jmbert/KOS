#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(division_error) {
    KERNEL_PANIC("Exception at 0x%X : Division Error", sf->ret_addr);
}

EXCEPTION_ENTER_NOCODE(division_error);