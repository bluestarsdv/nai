// recovery/recovery.c
#include <stdint.h>

// Definições de cores simples para a tela de recuperação
#define COR_FUNDO_PRETO    0x00
#define COR_TEXTO_ALERTA   0x0C // Vermelho/Laranja para indicar modo de segurança
#define COR_TEXTO_NORMAL   0x0F // Branco

// Simulando funções de exibição na tela do celular
void limpar_tela_recovery() {
    // No hardware real, isso limpa o buffer de vídeo do display
}

void desenhar_texto_recovery(const char *txt, int linha, uint32_t cor) {
    // Escreve o texto na linha indicada com a cor selecionada
}

// Menu de opções do Recovery
void exibir_menu_recovery() {
    desenhar_texto_recovery("--------------------------------------", 1, COR_TEXTO_ALERTA);
    desenhar_texto_recovery("        NAI RECOVERY SYSTEM           ", 2, COR_TEXTO_ALERTA);
    desenhar_texto_recovery("--------------------------------------", 3, COR_TEXTO_ALERTA);
    
    desenhar_texto_recovery("[1] Reiniciar Sistema (Reboot)", 5, COR_TEXTO_NORMAL);
    desenhar_texto_recovery("[2] Limpar Dados (Wipe Data / Factory Reset)", 6, COR_TEXTO_NORMAL);
    desenhar_texto_recovery("[3] Instalar Atualizacao via ADB", 7, COR_TEXTO_NORMAL);
    desenhar_texto_recovery("[4] Desligar Aparelho", 8, COR_TEXTO_NORMAL);
}

// Ponto de entrada que o vinculador (Linker) vai chamar ao iniciar o modo recovery
void recovery_main() {
    limpar_tela_recovery();
    exibir_menu_recovery();

    // Loop infinito do modo de recuperação aguardando comandos do usuário
    while (1) {
        // No futuro, aqui leremos os botões físicos de volume (para navegar)
        // e o botão de energia (para selecionar), ou usaremos o atualizar_touch()
    }
}
