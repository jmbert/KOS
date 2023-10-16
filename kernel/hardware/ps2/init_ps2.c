
#include <hardware/ps2/ps2-f.h>

#include <kernel/tools.h>

void init_ps2(void) {
    outb(PS2_CMD_DISABLE_1, PS2_COMMAND_REG);
    outb(PS2_CMD_DISABLE_2, PS2_COMMAND_REG);

    inb(PS2_DATA_PORT);

    outb(PS2_CMD_ENABLE_1, PS2_COMMAND_REG);
    outb(PS2_CMD_ENABLE_2, PS2_COMMAND_REG);
}