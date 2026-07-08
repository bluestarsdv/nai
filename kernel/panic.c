// kernel/panic.c
#include <stdint.h>

void kernel_panic(const char *mensagem_erro) {
    (void)mensagem_erro; // Evita aviso de variável não utilizada no compilador

    // Trava o processador em um loop infinito de segurança
    while (1) {
        // No futuro, quando tivermos um driver de vídeo/framebuffer configurado,
        // colocamos o código para pintar a tela de vermelho aqui.
    }
}
