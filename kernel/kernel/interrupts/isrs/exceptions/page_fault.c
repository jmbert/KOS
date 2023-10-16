#include <kernel/interrupts/exceptions.h>
#include <kernel/panic.h>
#include <kernel/tools.h>

#include <arch/paging.h>

EXCEPTION_DECL_CODE(page_fault) {
	uword_t invalid_addr = get_ctrl_reg_2();

	if (invalid_addr%PG_SIZE == 0) {
		invalid_addr += PG_SIZE;
	}

	kprintf("Page fault at address 0x%X accessing 0x%X, Error code 0x%X\n", sf->ret_addr, invalid_addr, error_code);

	if (!(error_code & 0x1)) {
		pframe_t new_page =	KALLOC_FRAME();
		uint8_t flags = 0x3;
		MAP_PAGES(invalid_addr, new_page, 1, flags);
		kprintf("Successfully mapped 1 page from 0x%X to 0x%X with flags 0x%X\n", invalid_addr, new_page, flags);
	} else {
		KERNEL_PANIC("Failed to recover from page fault at 0x%X", sf->ret_addr);
	}
}

EXCEPTION_ENTER_CODE(page_fault);