#include <kernel/interrupts/irqs.h>
#include <kernel/panic.h>

#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

#include <hardware/ps2/ps2-f.h>

#include <kernel/keyboard.h>

IRQ_DECL(keyboard_irq) {
    uint8_t key = read_byte();
    unsigned char key_char = decode_key(key);
    if (key_char != 0xFF) {
        kputchar(key_char);
    }
    pic_send_eoi(KEY_IRQ);
}

IRQ_ENTER(keyboard_irq);