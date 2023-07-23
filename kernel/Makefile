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

GRAPHICS=
MODE=0
WIDTH=160
HEIGHT=25
DEPTH=0

GBUFFER=0xFB000000
 
ARCHDIR=arch/$(HOSTARCH)
CFLAGS:=$(CFLAGS)
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel -DMODE=$(MODE) -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT) -DDEPTH=$(DEPTH) -DGBUFFER=$(GBUFFER) $(GRAPHICS)
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
hardware/pic/pic_send_eoi.o

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
	@echo $(KERNEL_SRCOBJS)

KOS.krnl: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot KOS.krnl
 
$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@
 
../kernel_obj/%.o: %.c
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)
 
../kernel_obj/%.o: %.S
	$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
 
clean:
	rm -f KOS.krnl
	rm -f $(OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
 
install: install-headers install-kernel
 
install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
 
install-kernel: KOS.krnl
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp KOS.krnl $(DESTDIR)$(BOOTDIR)
 
-include $(OBJS:.o=.d)