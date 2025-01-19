#include "pico/stdlib.h"

#define LED_GREEN 11    // Pino para o LED verde
#define LED_BLUE 12     // Pino para o LED azul
#define LED_RED 13      // Pino para o LED vermelho
#define BUZZER_PIN 21   // Pino para o Buzzer

// Funções para controlar os LEDs
void Lig_Led_Green() {
    gpio_put(LED_GREEN, 1);  // Liga o LED verde
    gpio_put(LED_BLUE, 0);   // Desliga o LED azul
    gpio_put(LED_RED, 0);    // Desliga o LED vermelho
}

void Lig_Led_Blue() {
    gpio_put(LED_BLUE, 1);   // Liga o LED azul
    gpio_put(LED_GREEN, 0);  // Desliga o LED verde
    gpio_put(LED_RED, 0);    // Desliga o LED vermelho
}

void Lig_Led_Red() {
    gpio_put(LED_RED, 1);    // Liga o LED vermelho
    gpio_put(LED_GREEN, 0);  // Desliga o LED verde
    gpio_put(LED_BLUE, 0);   // Desliga o LED azul
}

// Função para ligar o buzzer
void Acionar_Buzzer() {
    gpio_put(BUZZER_PIN, 1); // Aciona o buzzer
    sleep_ms(2000);           // Espera 2 segundos
    gpio_put(BUZZER_PIN, 0); // Desliga o buzzer
}

// Função para reiniciar o microcontrolador
void Reboot() {
    // Reinicia o microcontrolador
    reset_usb_boot(0, 0);
}

int main() {
    // Inicialização dos pinos dos LEDs e do buzzer
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(BUZZER_PIN);

    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // Configuração para o terminal serial (UART)
    stdio_init_all();  // Inicializa a UART (comunicação serial)

    char comando;  // Variável para armazenar o comando recebido

    while (true) {
        if (uart_is_readable(UART0)) {  // Verifica se há dados para ler na UART
            comando = getchar();  // Recebe um comando do terminal serial

            // Executa a ação dependendo do comando recebido
            switch (comando) {
                case 'G':  // Comando para ligar o LED verde
                    Lig_Led_Green();
                    break;
                case 'B':  // Comando para ligar o LED azul
                    Lig_Led_Blue();
                    break;
                case 'R':  // Comando para ligar o LED vermelho
                    Lig_Led_Red();
                    break;
                case 'W':  // Comando para ligar todos os LEDs
                    gpio_put(LED_GREEN, 1);
                    gpio_put(LED_BLUE, 1);
                    gpio_put(LED_RED, 1);
                    break;
                case 'O':  // Comando para desligar todos os LEDs
                    gpio_put(LED_GREEN, 0);
                    gpio_put(LED_BLUE, 0);
                    gpio_put(LED_RED, 0);
                    break;
                case 'Z':  // Comando para acionar o buzzer
                    Acionar_Buzzer();
                    break;
                case 'H':  // Comando para exibir a lista de comandos
                    printf("Comandos disponíveis:\n");
                    printf("G - Ligar LED verde\n");
                    printf("B - Ligar LED azul\n");
                    printf("R - Ligar LED vermelho\n");
                    printf("W - Ligar todos os LEDs\n");
                    printf("O - Desligar todos os LEDs\n");
                    printf("Z - Acionar buzzer\n");
                    printf("H - Exibir esta ajuda\n");
                    printf("Q - Reiniciar o microcontrolador\n");
                    break;
                case 'Q':  // Comando para reiniciar o microcontrolador
                    Reboot();
                    break;
                default:
                    printf("Comando não reconhecido. Use 'H' para ajuda.\n");
            }
        }
    }

    return 0;
}
