# Makefile - Nai Kernel e Recovery para ARM64

CC = aarch64-linux-gnu-gcc
LD = aarch64-linux-gnu-ld
OBJCOPY = aarch64-linux-gnu-objcopy

# REMOVIDO O -nostdinc DAQUI PARA CORRIGIR O ERRO DO STDINT.H
CFLAGS = -ffreestanding -nostdlib -Wall -Wextra -O2 -c
LDFLAGS = -nostdlib -Ttext 0x80000

# Objetos do Sistema Principal
OBJ_SYSTEM = kernel.o cpu.o touch.o setupwizard.o panic.o

# Objetos do Modo de Recuperação
OBJ_RECOVERY = recovery.o

all: payload.bin payload_recovery.bin

# Regra para o Sistema Principal
payload.bin: nai-system.elf
	$(OBJCOPY) -O binary nai-system.elf payload.bin

nai-system.elf: $(OBJ_SYSTEM)
	$(LD) $(LDFLAGS) -o nai-system.elf $(OBJ_SYSTEM)

# Regra para o Modo de Recuperação
payload_recovery.bin: nai-recovery.elf
	$(OBJCOPY) -O binary nai-recovery.elf payload_recovery.bin

nai-recovery.elf: $(OBJ_RECOVERY)
	$(LD) $(LDFLAGS) -o nai-recovery.elf $(OBJ_RECOVERY)

# Compilação dos arquivos individuais
kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) kernel/kernel.c -o kernel.o

cpu.o: kernel/cpu.c
	$(CC) $(CFLAGS) kernel/cpu.c -o cpu.o

touch.o: drivers/touch.c
	$(CC) $(CFLAGS) drivers/touch.c -o touch.o

setupwizard.o: kernel/setupwizard.c
	$(CC) $(CFLAGS) kernel/setupwizard.c -o setupwizard.o

panic.o: kernel/panic.c
	$(CC) $(CFLAGS) kernel/panic.c -o panic.o

# Procura o código principal da pasta recovery
recovery.o: recovery/recovery.c
	$(CC) $(CFLAGS) recovery/recovery.c -o recovery.o

clean:
	rm -f *.o *.elf payload.bin payload_recovery.bin
