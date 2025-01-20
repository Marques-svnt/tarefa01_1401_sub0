#ifndef BUZZER_H
#define BUZZER_H

//Declaração das funções de buzzer
void buzzer();
void inicialize(uint pin, bool is_input);
void init_buzzer();
void control_buzzer_pwm(bool state, float freq);

#endif