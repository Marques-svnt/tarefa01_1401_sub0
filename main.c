#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED1_PIN 11
#define LED2_PIN 12
#define LED3_PIN 13
#define BUZZER_PIN 21

int main() {
    // Inicialização do sistema
    stdio_init_all();
    
    // Configuração dos pinos como saída
    gpio_init(LED1_PIN);
    gpio_set_dir(LED1_PIN, GPIO_OUT);

    gpio_init(LED2_PIN);
    gpio_set_dir(LED2_PIN, GPIO_OUT);

    gpio_init(LED3_PIN);
    gpio_set_dir(LED3_PIN, GPIO_OUT);

    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    printf("Sistema iniciado.\n");

    while (true) {
        // Liga o LED 1 e o buzzer por 500ms
        gpio_put(LED1_PIN, 1);
        gpio_put(BUZZER_PIN, 1);
        sleep_ms(500);

        // Desliga o LED 1 e o buzzer
        gpio_put(LED1_PIN, 0);
        gpio_put(BUZZER_PIN, 0);
        sleep_ms(500);

        // Liga o LED 2 por 500ms
        gpio_put(LED2_PIN, 1);
        sleep_ms(500);
        gpio_put(LED2_PIN, 0);

        // Liga o LED 3 por 500ms
        gpio_put(LED3_PIN, 1);
        sleep_ms(500);
        gpio_put(LED3_PIN, 0);
    }
}
