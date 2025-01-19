#include "pico/stdlib.h"

#define LED_GREEN 11    // led verde ligado na porta 11

//Função para ligar led verde e desligar os demais 
void Lig_Led_Green(){
    gpio_put(LED_GREEN,1); // liga o led verde
    gpio_put(12,0);//desliga led azul
    gpio_put(13,0);//desliga led vermelho 
}

int main()
{
    //configuração inicial Leds
    gpio_init(LED_GREEN);//inicia o pino 
    gpio_set_dir(LED_GREEN, GPIO_OUT);//define como saída 

    while(true){
        
    }
    return 0;
}