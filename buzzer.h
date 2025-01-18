#include <pico/stdlib.h>
#include "hardware/pwm.h"
#include "hardware/clocks.h"


#define BUZZER_PIN_1 10
#define BUZZER_PIN_2 21


  void pwm_buzzer(){
  gpio_set_function(BUZZER_PIN_1, GPIO_FUNC_PWM);
  gpio_set_function(BUZZER_PIN_2, GPIO_FUNC_PWM);

  uint slice1 = pwm_gpio_to_slice_num(BUZZER_PIN_1);
  uint slice2 = pwm_gpio_to_slice_num(BUZZER_PIN_2);

  pwm_set_wrap(slice1, 2500); 
  pwm_set_wrap(slice2, 2500);
  pwm_set_enabled(slice1, true);
  pwm_set_enabled(slice2, true);
  }

  void setup_buzzer(uint buzzer_pin, uint frequency) {
    // Configura o pino do buzzer para PWM
    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
    
    // Obtém o slice do pino
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);

    // Calcula o divisor de clock
    uint clock = 125000000;  // Clock padrão do Raspberry Pi Pico em Hz
    uint divider = clock / (frequency * 4096);
    if (divider < 1) divider = 1;  // Garante que o divisor seja válido
    pwm_set_clkdiv(slice_num, divider);

    // Configura o período do PWM
    pwm_set_wrap(slice_num, 4095);

    // Define o nível inicial (duty cycle em 50%)
    pwm_set_gpio_level(buzzer_pin, 2048);  // 50% duty cycle

    // Ativa o PWM no slice
    pwm_set_enabled(slice_num, true);
}

 void buzzer_beep_high(uint buzzer_pin) {    //liga buzzer
  uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
  pwm_set_gpio_level(buzzer_pin, 1500); 
  sleep_ms(200); 
  pwm_set_gpio_level(buzzer_pin, 0);
}

void stop_buzzer(uint buzzer_pin) {  //desliga buzzer
    uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
    pwm_set_enabled(slice_num, false);  // Desativa o PWM
    gpio_set_function(buzzer_pin, GPIO_FUNC_SIO);  // Define o pino como GPIO
    gpio_put(buzzer_pin, 0);  // Garante que o nível do pino seja baixo
}