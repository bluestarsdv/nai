# Makefile

CC = gcc
ASM = nasm
LD = ld

CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -O -c
LDFLAGS = -m elf_i386 -Ttext 0x100000

all: nai-kernel.bin

nai-kernel.bin: boot.o kernel.o
	$(LD) $(LDFLAGS) -o nai-kernel.bin boot.o kernel.o

boot.o: boot/boot.asm
	$(ASM) -f elf32 boot/boot.asm -o boot.o

kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) kernel/kernel.c -o kernel.o

clean:
	rm -f *.o nai-kernel.bin
