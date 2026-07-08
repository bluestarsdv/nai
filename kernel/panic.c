// kernel/panic.c
#include <stdint.h>

// Função auxiliar fictícia para desenhar texto de erro na tela
extern void desenhar_texto_recovery(const char *txt, int linha, uint32_t cor);

// Função do Kernel Panic
void kernel_panic(const char *mensagem_erro) {
    // No futuro, desabilita todas as interrupções de hardware locais da CPU ARM64
    // __asm__ volatile("msr daifset, #2"); 

    // Define uma cor de destaque para erro (ex: vermelho brilhante)
    uint32_t cor_erro = 0x0C;

    // Exibe a tela de Kernel Panic
    desenhar_texto_recovery("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 5, cor_erro);
    desenhar_texto_recovery("          KERNEL PANIC OCORREU        ", 6, cor_erro);
    desenhar_texto_recovery("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 7, cor_erro);
    
    desenhar_texto_recovery("O Nai Kernel encontrou um erro critico.", 9, 0x0F);
    desenhar_texto_recovery("Motivo do erro:", 11, 0x0F);
    desenhar_texto_recovery(mensagem_erro, 12, cor_erro);
    
    desenhar_texto_recovery("O sistema foi interrompido para protecao.", 14, 0x0F);

    // Trava o processador em um loop infinito seguro
    while (1) {
        // Mantém a CPU em estado de espera de baixo consumo
        // __asm__ volatile("wfi");
    }
}
