; boot/boot.asm
bits 32                         ; O kernel roda em Modo Protegido de 32 bits
section .text
        align 4
        dd 0x1BADB002           ; Número mágico do padrão Multiboot
        dd 0x00                 ; Flags
        dd - (0x1BADB002 + 0x00); Checksum para o validador do bootloader

global _start
extern kernel_main              ; Aponta para a nossa função em C

_start:
        cli                     ; Desabilita interrupções iniciais
        call kernel_main        ; Pula para o código em C
        hlt                     ; Se o C fechar, para o processador
        
