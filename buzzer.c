#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

#define BUZZER 21 // Pino do buzzer ligado na porta 21

// Estrutura do teclado matricial
#define ROW_NUM 4    // Qtd de linhas
#define COLUMN_NUM 4 // Qtd de colunas

uint columns_pinos[4] = {4, 3, 2, 28}; // Os pinos das colunas
uint rows_pinos[4] = {8, 7, 6, 5};     // Os pinos das linhas

char keys_teclado[4][4] = { // Layout do teclado matricial
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

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

void init_keypad(){
    // Configuração inicial do teclado matricial
    for (int i = 0; i < COLUMN_NUM; i++){
        inicialize(columns_pinos[i], false); // Estabelece as colunas como saída
        gpio_put(columns_pinos[i], 1);       // Define o HIGH como padrão
    }
    for (int i = 0; i < ROW_NUM; i++){
        inicialize(rows_pinos[i], true); // Estabelece as linhas como entrada
        gpio_pull_up(rows_pinos[i]);     // As entradas ficam com pull-up ativado
    }
}

char get_key(){
    // A função lê a tecla pressionada pelo usuário
    for (int col = 0; col < COLUMN_NUM; col++){
        gpio_put(columns_pinos[col], 0); // Ativa a coluna
        sleep_ms(1);

        for (int row = 0; row < ROW_NUM; row++){
            if (gpio_get(rows_pinos[row]) == 0){ // Faz uma verificação se a linha está LOW
                sleep_ms(10);
                gpio_put(columns_pinos[col], 1); // Desliga a coluna
                return keys_teclado[row][col];   // Retorna a tecla que foi pressionada
            }
        }

        gpio_put(columns_pinos[col], 1); // Desliga a coluna
    }
    return '\0'; // Retorna valor nulo, quando nenhuma tecla é pressionada
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

int main(){
    stdio_init_all();
    init_buzzer(); // Inicia o buzzer
    init_keypad(); // Inicia o teclado matricial
    printf("Controle do buzzer com PWM inicializado\n");

    while (1){
        char key = get_key(); // Lê a tecla que foi pressionada no teclado

        if (key == '#'){
            control_buzzer_pwm(true, 1000.0f); // Liga o buzzer com frequência de 1000 Hz
            printf("Buzzer ligado com frequência de 1000 Hz\n");
        }
       
        else if (key == '\0'){
            control_buzzer_pwm(false, 0.0f); // Desliga o buzzer
            printf("Buzzer desligado\n");
        }
        sleep_ms(3000);
    }
    return 0;
}