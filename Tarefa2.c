#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include "buzzer.h"

#define FREQUENCY 1000  

uint8_t leds_rgb[3] = {11, 12, 13};
uint8_t buzzer_pin = 21;


void inicializa_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_init(leds_rgb[i]);
        gpio_set_dir(leds_rgb[i], GPIO_OUT);
        gpio_put(leds_rgb[i], 0); 
    }
}


void liga_led(uint8_t led) {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], leds_rgb[i] == led ? 1 : 0);
    }
}


void liga_todos_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], 1);
    }
}


void desliga_todos_leds() {
    for (uint8_t i = 0; i < 3; i++) {
        gpio_put(leds_rgb[i], 0);
    }
}


int main() {
    stdio_init_all();
    inicializa_leds();
    setup_buzzer(buzzer_pin, FREQUENCY);

    char comando;

    while (1) {
        comando = getchar();
        printf("Comando recebido: %c\n", comando);
        

        if (comando == 'r') {
            liga_led(13);
            printf("ON: RED\n");

        } else if (comando == 'g') {
            liga_led(11);
            printf("ON: GREEN\n");

        } else if (comando == 'b') {
            liga_led(12);
            printf("ON: BLUE\n");

        } else if (comando == 'w') {
            liga_todos_leds();
            printf("ON: WHITE\n");

        } else if (comando == '0') {
            desliga_todos_leds();
            printf("ON: --\n");

        } else if (comando == 'z') {
            start_buzzer(buzzer_pin, FREQUENCY); // Liga o buzzer com a frequência definida
            sleep_ms(2000);                      // Mantém por 500ms
            stop_buzzer(buzzer_pin);
            printf("ON: BUZZER\n");

        } else {
            printf("Invalid Input.\n");
        }
    }
    sleep_ms(100);
}
