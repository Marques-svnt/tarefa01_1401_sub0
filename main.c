#include <stdio.h>
#include "pico/stdlib.h"

//configurar  leds
gpio_init(LED_B_PIN);
gpio_set_dir(LED_B_PIN, GPIO_OUT);

void Lig_Led_Azul(){
    gpio_put(LED_B_PIN,1);
}
//função para desligar Led Azul 
void Des_Led_Azul(){
    gpio_put(LED_B_PIN,0);
}

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
