// kernel/panic.c
#include <stdint.h>

// Mudamos para a função que realmente existe no sistema principal
extern void escrever_linha(const char *str, int linha, uint8_t cor);

void kernel_panic(const char *mensagem_erro) {
    // Código de cor para o modo texto (0x4F = Fundo Vermelho, Texto Branco)
    uint8_t cor_erro = 0x4F;

    // Exibe a tela de Kernel Panic usando a função do sistema principal
    escrever_linha("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 5, cor_erro);
    escrever_linha("              KERNEL PANIC OCORREU                ", 6, cor_erro);
    escrever_linha("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 7, cor_erro);
    
    escrever_linha("O Nai Kernel encontrou um erro critico.", 9, 0x0F);
    escrever_linha("Motivo do erro:", 11, 0x0F);
    escrever_linha(mensagem_erro, 12, cor_erro);
    
    escrever_linha("O sistema foi interrompido para protecao.", 14, 0x0F);

    // Trava o processador em um loop infinito seguro
    while (1) {
        // Loop de espera
    }
}
