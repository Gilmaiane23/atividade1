#include <pico/stdlib.h>
#include "hardware/pwm.h"
#include "hardware/clocks.h"

//Definições buzzer
#define BUZZER_PIN 10
const uint FREQUENCIA_PADRAO_RASPBERRY_PICO = 125000000;


void config_buzzer(uint buzzer_pin, uint frequency, uint16_t level, bool enabled) {
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM); // Configura o pino como PWM
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);

    // Configura a frequência do PWM
    uint divider = FREQUENCIA_PADRAO_RASPBERRY_PICO / (frequency * 4096);
    if (divider < 1) divider = 1;
    pwm_set_clkdiv(slice_num, divider);

    pwm_set_wrap(slice_num, 4095);                // Resolução do PWM (12 bits)
    pwm_set_gpio_level(buzzer_pin, level);        // Define o duty cycle
    pwm_set_enabled(slice_num, enabled);
}

// Função PWM para buzzer
void setup_buzzer(uint buzzer_pin, uint frequency) {
    config_buzzer(buzzer_pin, frequency, 0, false);
}

//Função para ligar buzzer
void start_buzzer(uint buzzer_pin, uint frequency) {
    config_buzzer(buzzer_pin, frequency, 2048, true);
}

//Função para desligar buzzer
void stop_buzzer(uint buzzer_pin) {
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
    pwm_set_gpio_level(buzzer_pin, 0);           // Define o duty cycle como 0 (sem som)
    pwm_set_enabled(slice_num, false);   
}
