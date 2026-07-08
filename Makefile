# Makefile - Nai Kernel para ARM64

CC = aarch64-linux-gnu-gcc
LD = aarch64-linux-gnu-ld

# Flags para ARM64 (sem bibliotecas padrão de PC, focado em kernel puro)
CFLAGS = -ffreestanding -nostdlib -nostdinc -Wall -Wextra -O2 -c
LDFLAGS = -nostdlib -Ttext 0x80000  # Endereço de carregamento padrão comum em ARM

OBJETOS = kernel.o cpu.o touch.o setupwizard.o

all: nai-kernel.img

nai-kernel.img: $(OBJETOS)
	$(LD) $(LDFLAGS) -o nai-kernel.img $(OBJETOS)

kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) kernel/kernel.c -o kernel.o

cpu.o: kernel/cpu.c
	$(CC) $(CFLAGS) kernel/cpu.c -o cpu.o

touch.o: drivers/touch.c
	$(CC) $(CFLAGS) drivers/touch.c -o touch.o

setupwizard.o: kernel/setupwizard.c
	$(CC) $(CFLAGS) kernel/setupwizard.c -o setupwizard.o

clean:
	rm -f *.o nai-kernel.img
