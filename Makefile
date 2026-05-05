CC      := x86_64-elf-gcc
LD      := x86_64-elf-ld
OBJCOPY := x86_64-elf-objcopy

# Fall back to system toolchain if cross-compiler is missing
ifeq (, $(shell which $(CC) 2>/dev/null))
  CC := gcc
  LD := ld
endif

CFLAGS := \
    -std=c11 \
    -ffreestanding \
    -fno-stack-protector \
    -fno-pic \
    -mno-red-zone \
    -Wall -Wextra -O2 \
    -Iinclude \
    -I../libs/zirvlibc/include

LDFLAGS := \
    -nostdlib \
    -static \
    -no-pie \
    -z max-page-size=0x1000

# MOSIX init must be statically linked against zirvlibc
# We assume zirvlibc objects are available in ../build/libs/zirvlibc/src/
LIBC_OBJS := \
    ../build/libs/zirvlibc/src/string.o \
    ../build/libs/zirvlibc/src/stdio.o \
    ../build/libs/zirvlibc/src/ctype.o

SRCS := src/main.c
OBJS := $(SRCS:.c=.o)

TARGET := zirvinit.elf

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBC_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
