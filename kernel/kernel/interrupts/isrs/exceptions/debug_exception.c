#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(debug_exception) {
    KERNEL_PANIC("Debug Exception at 0x%X\n", sf->ret_addr);
    return;
}

EXCEPTION_ENTER_NOCODE(debug_exception);