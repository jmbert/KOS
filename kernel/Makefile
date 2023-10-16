DEFAULT_HOST!=../default-host
HOST?=DEFAULT_HOST
HOSTARCH!=../target-triplet-to-arch $(HOST)
 
CFLAGS?=-O2 -g
CPPFLAGS?=
LDFLAGS?=
LIBS?=
 
DESTDIR?=
PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include
 
ARCHDIR=arch/$(HOSTARCH)
CFLAGS:=$(CFLAGS)
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel 
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc
 
 
include $(ARCHDIR)/make.cfg
 
CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)
 
include kernel/interrupts/isrs/make.isr.cfg

KERNEL_SRC_OBJS=\
$(KERNEL_ARCH_OBJS) \
$(ISR_OBJS) \
kernel/kernel.o	\
tools/outb.o \
tools/inb.o \
tools/get_registers.o \
tty/tty_write_char.o \
tty/tty_change_col.o \
tty/enable_cursor.o \
tty/disable_cursor.o \
tty/set_cursor.o \
tty/get_cursor.o \
tty/tty_newline.o \
tty/scroll.o \
kernel/interrupts/isr_table/register_isr.o \
hardware/pic/remap_pics.o \
hardware/pic/set_mask.o \
hardware/pic/pic_send_eoi.o\
hardware/ps2/init_ps2.o\
hardware/ps2/byte_rw.o\
kernel/keyboard.o

KERNEL_OBJS=$(addprefix ../kernel_obj/,$(KERNEL_SRC_OBJS))

OBJS=\
$(KERNEL_OBJS) \

LINK_LIST=\
$(LDFLAGS) \
$(KERNEL_OBJS) \
$(LIBS) \
 
.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S
 
all: KOS.krnl

KOS.krnl: $(OBJS) $(ARCHDIR)/linker.ld
	@printf "\e[1;32mBuilding Kernel\e\n[m"
	@$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	@grub-file --is-x86-multiboot KOS.krnl
	@printf "\e[1;32mFinished Building Kernel\e\n[m"
 
../kernel_obj/%.o: %.c
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
../kernel_obj/%.o: %.S
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
clean:
	rm -f KOS.krnl
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
 
install: install-headers install-kernel
 
install-headers:
	@printf "\e[1;32mInstalling kernel header files to \e[0;33m $(DESTDIR)$(INCLUDEDIR) \e\n[m"
	@mkdir -p $(DESTDIR)$(INCLUDEDIR)
	@cp -Rv --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
	@printf "\e[1;32mFinished installing kernel header files to \e[0;33m $(DESTDIR)$(INCLUDEDIR)\e\n[m"
 
install-kernel: KOS.krnl
	@printf "\e[1;32mInstalling kernel to \e[0;33m $(DESTDIR)$(BOOTDIR)\e\n[m"
	@mkdir -p $(DESTDIR)$(BOOTDIR)
	@cp -v KOS.krnl $(DESTDIR)$(BOOTDIR)
	@printf "\e[1;32mFinished installing kernel to \e[0;33m $(DESTDIR)$(BOOTDIR)\e\n[m"
 
-include $(OBJS:.o=.d)
