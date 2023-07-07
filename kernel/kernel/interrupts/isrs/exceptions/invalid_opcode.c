#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>

EXCEPTION_DECL_NOCODE(invalid_opcode) {
    KERNEL_PANIC("Exception at 0x%X : Invalid Opcode\n", sf->ret_addr);
}

EXCEPTION_ENTER_NOCODE(invalid_opcode);