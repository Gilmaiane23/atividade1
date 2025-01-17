#include "pico/stdlib.h"
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

  gpio_init(BUZZER_PIN_1);
  gpio_set_dir(BUZZER_PIN_1, GPIO_OUT);
  gpio_put(BUZZER_PIN_1, 0); 
  gpio_init(BUZZER_PIN_2);
  gpio_set_dir(BUZZER_PIN_2, GPIO_OUT);
  gpio_put(BUZZER_PIN_2, 0); 
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

int main() {
  stdio_init_all();
  inicializa_teclado();

  char caracter = ' ';

  while (1) {
    caracter = teclado();
    
    if (caracter == '#') {
      gpio_put(BUZZER_PIN_1, 1);
      printf("\nBuzzer 1 ativado");
    } else {
      gpio_put(BUZZER_PIN_1, 0);
    }
    if (caracter == '#'){
    gpio_put(BUZZER_PIN_2, 1);
      printf("\nBuzzer 2 ativado");
    } else {
      gpio_put(BUZZER_PIN_2, 0);
    }

    if (caracter != ' ') {
      printf("\nCaractere digitado: %c", caracter);
    }

    sleep_ms(50);
  }

  return 0;
}