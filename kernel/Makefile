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
WIDTH=80
HEIGHT=24
DEPTH=0

GBUFFER=0xFB000000
 
CFLAGS:=$(CFLAGS)
CPPFLAGS:=$(CPPFLAGS) -D__is_kernel -DMODE=$(MODE) -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT) -DDEPTH=$(DEPTH) -DGBUFFER=$(GBUFFER) $(GRAPHICS) -Iinclude -Iarch/$(HOSTARCH)/include
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc
 
ARCHDIR=arch/$(HOSTARCH)
 
include $(ARCHDIR)/make.config
 
CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)
 
KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel/kernel.o	\
tools/outb.o \
tools/inb.o \
tty/tty_write_char.o \
tty/tty_change_col.o \
tty/enable_cursor.o \
tty/disable_cursor.o \
tty/set_cursor.o \
tty/get_cursor.o \
isr/exceptions/exception_handler.o \
panic/kernel_panic.o
 
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
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot KOS.krnl
 
$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@
 
.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)
 
.S.o:
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