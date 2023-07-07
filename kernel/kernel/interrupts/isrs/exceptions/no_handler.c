#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(no_handler) {
    KERNEL_WARN("Unhandler Exception at 0x%X");
    return;
}

EXCEPTION_ENTER_NOCODE(no_handler);