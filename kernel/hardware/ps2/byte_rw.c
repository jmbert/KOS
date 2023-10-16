
#include <hardware/ps2/ps2-f.h>

#include <stddef.h>
#include <kernel/tools.h>
#include <kernel/panic.h>

uint8_t read_byte(void) {
    return inb(PS2_DATA_PORT);
}

void write_byte(uint8_t byte) {
    size_t timer = PS2_RW_TIMEOUT_LOOPS;
    for (;timer > 0 && (inb(PS2_STATUS_REG) & 1);timer--);
    if (!timer) {
        KERNEL_PANIC("PS2 write loop took longer than %d iterations", PS2_RW_TIMEOUT_LOOPS);
    }
    outb(byte, PS2_DATA_PORT);
}