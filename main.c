#include "pico/stdlib.h"
#include <stdio.h>

#define BUZZER 21 //Pino do buzzer ligado na porta 21

// Configuração do teclado matricial
#define ROW_NUM 4 //Número de linhas
#define COLUMN_NUM 4 //Número de colunas

uint columns_pinos[4] = {4, 3, 2, 28}; //Pinos das colunas
uint rows_pinos[4] = {8, 7, 6, 5}; // Pinos das linhas

//Mapeamento do teclado
char keys_teclado[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

//Função para inicializar um pino
void inicialize(uint pin, bool is_input) {
    gpio_init(pin);
    gpio_set_dir(pin, !is_input); //false -> saída, true -> entrada
}

//Inicializar o periférico do buzzer
void init_buzzer() {
    inicialize(BUZZER, false);
    gpio_put(BUZZER, 0); //Desliga o buzzer inicialmente
}

//Configuração inicial do teclado matricial
void init_keypad() {
    for (int i = 0; i < COLUMN_NUM; i++) {
        inicialize(columns_pinos[i], false); //Colunas como saída
        gpio_put(columns_pinos[i], 1); //Mantém em HIGH por padrão
    }
    for (int i = 0; i < ROW_NUM; i++) {
        inicialize(rows_pinos[i], true); //Linhas como entrada
        gpio_pull_up(rows_pinos[i]); //Ativa pull-up nas entradas
    }
}

//Função para obter a tecla pressionada
char get_key() {
    for (int col = 0; col < COLUMN_NUM; col++) {
        gpio_put(columns_pinos[col], 0); // Ativa a coluna
        sleep_ms(1); // Pequeno atraso para estabilização

        for (int row = 0; row < ROW_NUM; row++) {
            if (gpio_get(rows_pinos[row]) == 0) { //Verifica se a linha está LOW
                sleep_ms(10);  // Debounce
                gpio_put(columns_pinos[col], 1); //Desativa a coluna
                return keys_teclado[row][col]; //Retorna a tecla pressionada
            }
        }

        gpio_put(columns_pinos[col], 1); //Desativa a coluna
    }
    return '\0'; //Nenhuma tecla pressionada
}

// Controlar o buzzer
void control_buzzer(bool state) {
    gpio_put(BUZZER, state ? 1 : 0); //Liga ou desliga o buzzer
}

int main() {
    stdio_init_all();
    init_buzzer(); //Inicializa o buzzer
    init_keypad(); //Inicializa o teclado matricial
    printf("Controle do buzzer inicializado\n");

    while (1) {
        char key = get_key(); //Obtém a tecla pressionada do teclado matricial

        if (key == '#') { 
            control_buzzer(true); //Liga o buzzer
            printf("Buzzer ligado\n");
        } else if (key == '\0') { 
            control_buzzer(false); //Desliga o buzzer se nenhuma tecla for pressionada
            printf("Buzzer desligado\n");
        }

        sleep_ms(50); //Delay para evitar leituras excessivas
    }

    return 0;
}