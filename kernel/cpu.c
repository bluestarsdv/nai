// kernel/cpu.c
#include <stdint.h>

// Estrutura para um ponteiro da IDT (Interrupt Descriptor Table)
struct idt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Estrutura para uma entrada na tabela de interrupções
struct idt_entry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t  always0;
    uint8_t  flags;
    uint16_t base_high;
} __attribute__((packed));

struct idt_entry idt[256];
struct idt_ptr idtp;

// Função para registrar um manipulador de interrupção (Interrupt Handler)
void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low = (base & 0xFFFF);
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].selector = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
}

// Inicializa os registradores críticos da CPU
void init_cpu() {
    idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
    idtp.base = (uint32_t)&idt;

    // Limpa a IDT preenchendo com zeros
    for(int i = 0; i < 256; i++) {
        idt_set_gate(i, 0, 0, 0);
    }

    // Carrega a tabela de interrupções na CPU
    // Nota: Em hardware real, usaríamos o comando Assembly 'lidt' aqui
}
