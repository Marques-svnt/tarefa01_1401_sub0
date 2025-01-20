#include "pico/stdlib.h"

#define LED_B_PIN 12


//Função para ligar led azul e desiga os demais 
void Lig_Led_B(){
    gpio_put(LED_B_PIN,1);
    gpio_put(11,0);//desliga led verde 
    gpio_put(13,0);//desliga led vermelhho 
}


