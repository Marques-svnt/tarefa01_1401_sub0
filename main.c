#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

// Definições de pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER_PIN 21

// Funções para controle dos LEDs
void Lig_Led_Green() {
    gpio_put(LED_GREEN, 1);  // Liga LED verde
    gpio_put(LED_BLUE, 0);   // Desliga LED azul
    gpio_put(LED_RED, 0);    // Desliga LED vermelho
}

void Lig_Led_Blue() {
    gpio_put(LED_GREEN, 0);  // Desliga LED verde
    gpio_put(LED_BLUE, 1);   // Liga LED azul
    gpio_put(LED_RED, 0);    // Desliga LED vermelho
}

void Lig_Led_Red() {
    gpio_put(LED_GREEN, 0);  // Desliga LED verde
    gpio_put(LED_BLUE, 0);   // Desliga LED azul
    gpio_put(LED_RED, 1);    // Liga LED vermelho
}

// Função para tocar o buzzer
void Tocar_Buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(200);             // Espera 200ms
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}

// Função para configurar os pinos dos LEDs e do buzzer
void Configurar_Pinos() {
    // Inicializa os pinos como saída
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(BUZZER_PIN);

    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

int main() {
    // Configuração inicial dos pinos
    Configurar_Pinos();

    // Inicia a comunicação UART para monitoramento serial
    stdio_init_all();

    // Exibe uma mensagem inicial no terminal
    printf("Projeto de controle de LEDs e buzzer - Iniciado!\n");

    // Loop principal
    while (true) {
        char comando;
        printf("Pressione uma tecla para controlar os LEDs:\n");
        printf("1 - LED Verde\n");
        printf("2 - LED Azul\n");
        printf("3 - LED Vermelho\n");
        printf("4 - Desligar todos os LEDs\n");
        printf("5 - Tocar Buzzer\n");

        comando = getchar();  // Lê o comando do terminal (tecla pressionada)

        switch (comando) {
            case '1':
                Lig_Led_Green();   // Liga o LED verde
                printf("LED verde ligado.\n");
                break;
            case '2':
                Lig_Led_Blue();    // Liga o LED azul
                printf("LED azul ligado.\n");
                break;
            case '3':
                Lig_Led_Red();     // Liga o LED vermelho
                printf("LED vermelho ligado.\n");
                break;
            case '4':
                gpio_put(LED_GREEN, 0);  // Desliga todos os LEDs
                gpio_put(LED_BLUE, 0);
                gpio_put(LED_RED, 0);
                printf("Todos os LEDs desligados.\n");
                break;
            case '5':
                Tocar_Buzzer();    // Toca o buzzer
                printf("Buzzer tocando.\n");
                break;
            default:
                printf("Comando inválido! Tente novamente.\n");
                break;
        }

        sleep_ms(1000);  // Aguarda 1 segundo antes de pedir o próximo comando
    }

    return 0;
}
