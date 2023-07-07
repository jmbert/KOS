#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(no_handler) {
    KERNEL_PANIC("Unhandled Exception at 0x%X", sf->ret_addr);
}

EXCEPTION_ENTER_NOCODE(no_handler);