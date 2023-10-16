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
INCLUDEDIR?=$(PREFIX)/include
LIBDIR?=$(EXEC_PREFIX)/lib
 
CFLAGS:=$(CFLAGS)
CPPFLAGS:=$(CPPFLAGS) -D__is_libc -Iinclude
LIBK_CFLAGS:=$(CFLAGS)
LIBK_CPPFLAGS:=$(CPPFLAGS) -D__is_libk
 
ARCHDIR=arch/$(HOSTARCH)
 
include $(ARCHDIR)/make.config
 
CFLAGS:=$(CFLAGS) $(ARCH_CFLAGS)
CPPFLAGS:=$(CPPFLAGS) $(ARCH_CPPFLAGS)
LIBK_CFLAGS:=$(LIBK_CFLAGS) $(KERNEL_ARCH_CFLAGS)
LIBK_CPPFLAGS:=$(LIBK_CPPFLAGS) $(KERNEL_ARCH_CPPFLAGS)
 
FREEOBJS_SRC=\
$(ARCH_FREEOBJS) \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/strlen.o \
stdio/putchar.o \
stdio/puts.o \
stdio/printf.o \
stdio/sprintf.o \
stdlib/malloc.o \
 
FREEOBJS=$(addprefix ../libc_obj/,$(FREEOBJS_SRC))

HOSTEDOBJS_SRC=\
$(ARCH_HOSTEDOBJS) \

HOSTEDOBJS=$(addprefix ../libc_obj/,$(HOSTEDOBJS_SRC))
 
OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \
 
LIBK_OBJS=$(FREEOBJS:.o=.libk.o)
 
#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a

.PHONY: all clean install install-headers install-libs
.SUFFIXES: .o .libk.o .c .S
 
all: $(BINARIES)
 
libc.a: $(OBJS)
	@printf "\e[1;32mBuilding Libk\e\n[m"
	@$(AR) -v rcs $@ $(OBJS)
	@printf "\e[1;32mFinished Building Libk\e\n[m"
 
libk.a: $(LIBK_OBJS)
	@printf "\e[1;32mBuilding Libk\e\n[m"
	@$(AR) -v rcs $@ $(LIBK_OBJS)
	@printf "\e[1;32mFinished Building Libk\e\n[m"
 
../libc_obj/%.o: %.c
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
../libc_obj/%.o: %.S
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ $(CFLAGS) $(CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
../libc_obj/%.libk.o: %.c
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
../libc_obj/%.libk.o: %.S
	@printf "\e[1;32mBuilding \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
	@$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CPPFLAGS)
	@printf "\e[1;32mFinished building \e[0;33m $@ \e[1;32m from \e[0;33m $<\e\n[m"
 
clean:
	rm -f $(BINARIES) *.a
	rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d
 
install: install-headers install-libs
 
install-headers:
	@printf "\e[1;32mInstalling libc header files to \e[0;33m $(DESTDIR)$(INCLUDEDIR) \e\n[m"
	@mkdir -p $(DESTDIR)$(INCLUDEDIR)
	@cp -Rv --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.
	@printf "\e[1;32mFinished installing libc header files to \e[0;33m $(DESTDIR)$(INCLUDEDIR)\e\n[m"
 
install-libs: $(BINARIES)
	@printf "\e[1;32mInstalling binaries to \e[0;33m $(DESTDIR)$(LIBDIR)\e\n[m"
	@mkdir -p $(DESTDIR)$(LIBDIR)
	@cp -v $(BINARIES) $(DESTDIR)$(LIBDIR)
	@printf "\e[1;32mFinished installing binaries to \e[0;33m $(DESTDIR)$(LIBDIR)\e\n[m"
 
-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)