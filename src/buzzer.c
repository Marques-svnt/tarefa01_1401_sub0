#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

#define BUZZER 21 // Pino do buzzer ligado na porta 21

void inicialize(uint pin, bool is_input){
    // Função que inicializa o pino
    gpio_init(pin);
    gpio_set_dir(pin, !is_input); // false = saída, true = entrada
}

void init_buzzer(){
    // Ativa o buzzer e configura o PWM no pino
    inicialize(BUZZER, false);
    gpio_put(BUZZER, 0); // Desliga o buzzer inicialmente
}

void control_buzzer_pwm(bool state, float freq){
    static uint slice_num = 0; // Armazena o slice do PWM
    static uint chan_num = 0;  // Armazena o canal do PWM

    if (state){
        // Inicializa o PWM (se ainda não foi inicializado)
        if (slice_num == 0){
            slice_num = pwm_gpio_to_slice_num(BUZZER);
            chan_num = pwm_gpio_to_channel(BUZZER);
            gpio_set_function(BUZZER, GPIO_FUNC_PWM); // Configura o pino para função PWM
        }

        // Calcula o valor de TOP com base na frequência desejada
        uint32_t clk_div = 4; // Divisor de clock padrão
        uint32_t top = (125000000 / (clk_div * freq)) - 1;

        pwm_set_wrap(slice_num, top);   // Configura o valor de TOP para o PWM
        pwm_set_clkdiv(slice_num, (float)clk_div); // Ajusta o divisor de clock
        pwm_set_gpio_level(BUZZER, top / 2); // Define o ciclo de trabalho (50%)
        pwm_set_enabled(slice_num, true);  // Liga o PWM
    }
    else{
        pwm_set_enabled(slice_num, false); // Desliga o PWM
    }
}

void buzzer(){
    stdio_init_all();
    init_buzzer(); // Inicia o buzzer
            control_buzzer_pwm(true, 1000.0f); // Liga o buzzer com frequência de 1000 Hz
            sleep_ms(2500);
            control_buzzer_pwm(false, 1000.0f);
        }
