#include "pico/stdlib.h"

#define LED_VERMELHO 13   // LED vermelho
#define LED_B_PIN 12  // LED azul
#define LED_GREEN 11 // LED verde


void allOn(){
    gpio_put(13, 1);
    gpio_put(12, 1);
    gpio_put(11, 1);
}