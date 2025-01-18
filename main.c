#include <stdio.h>

#include "pico/stdlib.h"


#include "pico/stdlib.h"

// Definição do GPIO do LED vermelho
#define LED_VERMELHO 13

int main() {
    // Inicializa o GPIO do LED vermelho
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    // Liga o LED vermelho
    gpio_put(LED_VERMELHO, 1);

    while (true) {
        // Mantém o LED ligado indefinidamente
        tight_loop_contents();
    }

    return 0;
}
