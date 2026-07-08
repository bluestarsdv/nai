// kernel/kernel.c

void kernel_main() {
    // Apontador para a memória de vídeo VGA text-mode (endereço 0xB8000)
    char *video_memory = (char*) 0xB8000;
    
    // String de inicialização do sistema
    const char *str = "Nai Kernel Inicializado com Sucesso.";
    
    // Loop simples para imprimir na tela caractere por caractere
    for (int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];     // Caractere
        video_memory[i * 2 + 1] = 0x07; // Cor (Texto branco, fundo preto)
    }

    // O sistema fica em loop protegendo o estado
    while(1);
}
