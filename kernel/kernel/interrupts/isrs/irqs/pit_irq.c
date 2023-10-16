#include <kernel/interrupts/irqs.h>
#include <kernel/panic.h>

#include <hardware/pic/pic_f.h>
#include <hardware/pic/pic-defs.h>

IRQ_DECL(pit_irq) {
    KERNEL_WARN("Timer Incremented", sf->ret_addr);
    pic_send_eoi(PIT_IRQ);
}

IRQ_ENTER(pit_irq);