# Directories
ROOTDIR = ..
PROJAME = KOS
SRCDIRS = boot kernel common std

BUILD = $(ROOTDIR)/build
BIN = $(ROOTDIR)/bin

# Files
LPATH = $(ROOTDIR)/linker/linker.ld

SSRCS = $(shell find $(SRCDIRS) | grep "\.s")
CSRCS = $(shell find $(SRCDIRS) | grep "\.c")

SRCS = $(SSRCS) $(CSRCS)

OBJS = $(patsubst %,$(BUILD)/%.o,$(SRCS))

SUBSTRUCT = $(shell dirname $(OBJS))

LIB =  #$(ROOTDIR)/lib/share/lib.so

BINARY = $(BIN)/$(PROJAME)

# ISO
ISODIR = $(ROOTDIR)/isodir
ISO = $(ISODIR)/$(PROJAME).iso
BOOTDIR = $(ISODIR)/boot
GRUBDIR = $(BOOTDIR)/grub
BINCOPY = $(BOOTDIR)/$(notdir $(BINARY))
GRUBCFG = $(ROOTDIR)/grub.cfg
GRUBCFGCOPY = $(GRUBDIR)/$(notdir $(GRUBCFG))

# Tools
CC = /usr/local/i386elfgcc/bin/i386-elf-gcc
CFLAGS = -ffreestanding -m32 -w -g -L$(LIB) -I$(ROOTDIR)/include -Iinclude
CPPFLAGS =

AS = nasm
ASFLAGS = -felf32
ASPFLAGS =

LD = /usr/local/i386elfgcc/bin/i386-elf-gcc
LDFLAGS = -T$(LPATH)
LDOFLAGS = -ffreestanding -O2 -nostdlib
LDPFLAGS = -lgcc

# Targets
.PHONY: all clean init compile

all: init compile

clean:
	rm -rf $(BUILD) $(BIN) $(ISODIR)

init: | $(BUILD) $(BIN) $(SUBSTRUCT) $(ISODIR) $(BOOTDIR) $(GRUBDIR)

%:
ifneq ($@,.)
	$(MAKE) $(shell dirname $@)
endif
	mkdir $@

compile: $(OBJS) $(BINARY) $(ISO)

$(BUILD)/%.c.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CPPFLAGS)

$(BUILD)/%.s.o:%.s
	$(AS) $(ASFLAGS) $< -o $@ $(ASPFLAGS)


$(BINARY): $(OBJS) $(LIB)
	$(LD) $(LDFLAGS) -o $@ $(LDOFLAGS) $^ $(LIB) $(LDPFLAGS)


$(ISO): $(BIN) $(OBJS)
	rm -rf $(ISODIR)
	mkdir $(ISODIR)
	mkdir $(BOOTDIR)
	mkdir $(GRUBDIR)
	cp $(BINARY) $(BINCOPY)
	cp $(GRUBCFG) $(GRUBCFGCOPY)
	grub-mkrescue -o $(ISO) $(ISODIR)