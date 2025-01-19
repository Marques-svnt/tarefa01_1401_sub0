#include "pico/stdlib.h"

#define LED_VERMELHO 13   // LED vermelho
#define LED_BLUE_PIN 12  // LED azul
#define LED_GREEN 11 // LED verde


void allOff(){
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_BLUE_PIN, 0);
    gpio_put(LED_GREEN, 0);
}