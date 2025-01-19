#include <stdio.h>

#include "pico/stdlib.h"

// Definição do GPIO do LED vermelho
#define LED_VERMELHO 13

void Lig_Led_R() {
    gpio_put(LED_VERMELHO, 1);  // Liga o LED vermelho
    gpio_put(11, 0);         // Desliga o LED verde
    gpio_put(12, 0);         // Desliga o LED azul
}
int main()
{

    //configuração inicial Leds
    gpio_init(LED_VERMELHO);//inicia o pino 
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);//define como saída 

    while(true){
       
    }
    return 0;
}

