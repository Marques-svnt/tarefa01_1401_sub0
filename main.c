#include "pico/stdlib.h"

#define LED_GREEN 11    
#define LED_B_PIN 12

//Função para ligar o led verde e desligar os demais 
void Lig_Led_Green(){
    gpio_put(LED_GREEN,1); // liga o led verde
    gpio_put(12,0);        //desliga o led azul
    gpio_put(13,0);        //desliga o led vermelho 
}

//Função para ligar led azul e desiga os demais 
void Lig_Led_B(){
    gpio_put(LED_B_PIN,1);
    gpio_put(11,0);//desliga led verde 
    gpio_put(13,0);//desliga led vermelhho 
}

int main()
{
    //configuração inicial Leds
    gpio_init(LED_GREEN);//inicia o pino 
    gpio_init(LED_B_PIN);//inicia o pino 
    pio_set_dir(LED_GREEN, GPIO_OUT);//define como saída
    gpio_set_dir(LED_B_PIN, GPIO_OUT);//define como saída 

    while(true){
        
    }
    return 0;
}

