#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

uint8_t linhas[4] = {16, 17, 28, 18};
uint8_t colunas[4] = {19, 20, 4, 9};
uint8_t n_lin = 4, n_col = 4;
char teclas[4][4] = {{'1', '2', '3', 'A'},
                     {'4', '5', '6', 'B'},
                     {'7', '8', '9', 'C'},
                     {'*', '0', '#', 'D'}};

#define BUZZER_PIN_1 10
#define BUZZER_PIN_2 21


void inicializa_teclado() {
  for (uint8_t i = 0; i < n_lin; i++) {
    gpio_init(linhas[i]);
    gpio_set_dir(linhas[i], GPIO_OUT);
    gpio_put(linhas[i], 1);
  }

  for (uint8_t i = 0; i < n_col; i++) {
    gpio_init(colunas[i]);
    gpio_set_dir(colunas[i], GPIO_IN);
    gpio_pull_up(colunas[i]);
  }

  gpio_set_function(BUZZER_PIN_1, GPIO_FUNC_PWM);
  gpio_set_function(BUZZER_PIN_2, GPIO_FUNC_PWM);

  uint slice1 = pwm_gpio_to_slice_num(BUZZER_PIN_1);
  uint slice2 = pwm_gpio_to_slice_num(BUZZER_PIN_2);

  pwm_set_wrap(slice1, 2500); 
  pwm_set_wrap(slice2, 2500);
  pwm_set_enabled(slice1, true);
  pwm_set_enabled(slice2, true);
}


char teclado() {
  char caractere = ' ';

  for (uint8_t i = 0; i < n_lin; i++) {
    gpio_put(linhas[i], 0);

    for (uint8_t j = 0; j < n_col; j++) {
      if (!gpio_get(colunas[j])) {
        caractere = teclas[i][j];

        while (!gpio_get(colunas[j])) {
          sleep_ms(10);
        }

        break;
      }
    }
    gpio_put(linhas[i], 1);
  }
  return caractere;
}


void buzzer_beep_high(uint buzzer_pin) {
  uint slice_num = pwm_gpio_to_slice_num(buzzer_pin);
  pwm_set_gpio_level(buzzer_pin, 1250); 
  sleep_ms(200); 
  pwm_set_gpio_level(buzzer_pin, 0);
}

int main() {
  stdio_init_all();
  inicializa_teclado();

  char caracter = ' ';

  while (1) {
    caracter = teclado();

    if (caracter == '#') {
      buzzer_beep_high(BUZZER_PIN_1);
      printf("\nBuzzer 1 ativado");

      buzzer_beep_high(BUZZER_PIN_2);
      printf("\nBuzzer 2 ativado");
    }

    if (caracter != ' ') {
      printf("\nCaractere digitado: %c", caracter);
    }

    sleep_ms(50);
  }

  return 0;
}