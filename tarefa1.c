#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include "leds.h"
#include "buzzer.h"
#include "keyboard.h"

#define BUZZER_PIN 10
#define FREQUENCY 1000

int main()
{
    stdio_init_all();
    inicializa_teclado();
    init_leds_RGB();
    pwm_buzzer();
    char caracter = ' ';
    while (true)
    {
        caracter = teclado();
        if (caracter != ' ')
        {
            printf("Tecla pressionada: %c\n", caracter);
            sleep_ms(50);

            switch (caracter)
            {
            case '1':
                printf("Liga led vermelho\n");
                turn_on_led(LED_RED);
                break;
            case '2':
                printf("Desliga led vermelho\n");
                turn_off_led(LED_RED);
                break;
            case '3':
                printf("Liga led verde\n");
                turn_on_led(LED_GREEN);
                break;
            case '4':
                printf("Desliga led verde\n");
                turn_off_led(LED_GREEN);
                break;
            case '5':
                printf("Liga led azul\n");
                turn_on_led(LED_BLUE);
                break;
            case '6':
                printf("Desliga led azul\n");
                turn_off_led(LED_BLUE);
                break;
            case '#':
                printf("Ativando buzzer no pino %d\n", BUZZER_PIN_1);
                setup_buzzer(BUZZER_PIN, FREQUENCY);
                sleep_ms(500);
                stop_buzzer(BUZZER_PIN);
                break;
            case '*':
                printf("Tecla pressionada: %c\n", caracter);
                break;
            default:
                break;
            }
        }
        sleep_ms(100);
    }
}
