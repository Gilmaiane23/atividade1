#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include "leds.h"
#include "buzzer.h"
#include "keyboard.h"

#define BUZZER_PIN 10
#define FREQUENCY 1000  

int main() {
    stdio_init_all(); // Inicializa a saída padrão para depuração (UART)
    inicializa_teclado(); // Configura o teclado matricial
    init_leds_RGB();
    setup_buzzer(BUZZER_PIN, FREQUENCY);
    menu();

    //char caracter=' ';
    while (true) {
        char tecla = teclado();
        if (tecla != ' ') {
            printf("Tecla pressionada: %c\n", tecla);
        }

        switch (tecla) {
            case '1':
                printf("Liga LED vermelho\n");
                turn_on_led(LED_RED);
                break;
            case '2':
                printf("Desliga LED vermelho\n");
                turn_off_led(LED_RED);
                break;
            case '3':
                printf("Liga LED verde\n");
                turn_on_led(LED_GREEN);
                break;
            case '4':
                printf("Desliga LED verde\n");
                turn_off_led(LED_GREEN);
                break;
            case '5':
                printf("Liga LED azul\n");
                turn_on_led(LED_BLUE);
                break;
            case '6':
                printf("Desliga LED azul\n");
                turn_off_led(LED_BLUE);
                break;
            case '#':
                printf("Ativando buzzer...\n");
                start_buzzer(BUZZER_PIN, FREQUENCY); // Liga o buzzer com a frequência definida
                sleep_ms(500);                      // Mantém por 500ms
                stop_buzzer(BUZZER_PIN);            // Desliga o buzzer
                printf("Buzzer desligado.\n");
                break;
            default:
                break;
        }
        sleep_ms(100);
    }
}
