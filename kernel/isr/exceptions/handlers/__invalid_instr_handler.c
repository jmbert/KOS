#include "../__exception_isr.h"

#include <panic.h>

void __invalid_instr_handler(void) {
    kernel_panic("Exception #6: Invalid Instruction");
}