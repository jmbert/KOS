#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(debug_exception) {
    KERNEL_PANIC("Debug Exception at 0x%X", sf->ret_addr);
}

EXCEPTION_ENTER_NOCODE(debug_exception);