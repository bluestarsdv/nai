// drivers/touch.c
#include <stdint.h>

// Endereços fictícios de registradores do controlador de Touch (via I2C)
#define TOUCH_REG_STATUS 0x00
#define TOUCH_REG_X_MSB  0x01
#define TOUCH_REG_X_LSB  0x02
#define TOUCH_REG_Y_MSB  0x03
#define TOUCH_REG_Y_LSB  0x04

// Estrutura para armazenar o evento de toque
typedef struct {
    uint16_t x;
    uint16_t y;
    uint8_t pressionado;
} TouchEvent;

// Função para ler um registrador do barramento I2C (Simulação)
uint8_t i2c_ler_registrador(uint8_t reg) {
    // Em hardware real, aqui entraria o código de controle dos pinos I2C do processador ARM
    return 0; 
}

// Função principal do driver que será chamada pela interrupção do Touch
TouchEvent atualizar_touch() {
    TouchEvent evento;
    
    // Verifica se há um toque ativo na tela
    uint8_t status = i2c_ler_registrador(TOUCH_REG_STATUS);
    
    if (status & 0x01) { // Bit 0 indica toque detectado
        evento.pressionado = 1;
        
        // Reconstrói as coordenadas X e Y juntando os bits mais significativos (MSB) e menos significativos (LSB)
        evento.x = (i2c_ler_registrador(TOUCH_REG_X_MSB) << 8) | i2c_ler_registrador(TOUCH_REG_X_LSB);
        evento.y = (i2c_ler_registrador(TOUCH_REG_Y_MSB) << 8) | i2c_ler_registrador(TOUCH_REG_Y_LSB);
    } else {
        evento.pressionado = 0;
        evento.x = 0;
        evento.y = 0;
    }
    
    return evento;
}
