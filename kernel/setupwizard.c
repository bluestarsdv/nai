// kernel/setupwizard.c
#include <stdint.h>

// Função fictícia para simular a limpeza da tela VGA
void limpar_tela() {
    char *video_memory = (char*) 0xB8000;
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        video_memory[i] = ' ';     // Espaço em branco
        video_memory[i + 1] = 0x07; // Atributo padrão (Cinza no preto)
    }
}

// Função auxiliar para escrever texto em uma linha específica
void escrever_linha(const char *str, int linha, uint8_t cor) {
    char *video_memory = (char*) 0xB8000;
    int offset = linha * 80 * 2;
    
    for (int i = 0; str[i] != '\0'; i++) {
        video_memory[offset + (i * 2)] = str[i];
        video_memory[offset + (i * 2) + 1] = cor;
    }
}

// O assistente de configuração inicial do Nai
void iniciar_setup_wizard() {
    limpar_tela();

    // Tela de Boas-Vindas (Cores: 0x0F = Branco brilhante, 0x0A = Verde)
    escrever_linha("==================================================", 2, 0x0A);
    escrever_linha("             BEM-VINDO AO SISTEMA NAI             ", 3, 0x0F);
    escrever_linha("==================================================", 4, 0x0A);
    
    escrever_linha("Iniciando o assistente de configuracao...", 6, 0x07);
    
    // Passo 1: Configuração de Segurança Interna
    escrever_linha("[PASSO 1] Ativando aneis de protecao (Ring 0 - Ring 5)...", 8, 0x07);
    escrever_linha("-> Modulo Miniter USB: Isolado com sucesso.", 9, 0x0A);
    
    // Passo 2: Verificação do circuito de sacrifício
    escrever_linha("[PASSO 2] Verificando filtros do conector fisico...", 11, 0x07);
    escrever_linha("-> Sistema anti-USB Killer: Pronto para agir.", 12, 0x0A);

    // Conclusão
    escrever_linha("Configuracao concluida! O Nai esta pronto para uso.", 15, 0x0F);
    escrever_linha("Pressione qualquer tecla para entrar no Shell...", 17, 0x08);
}
