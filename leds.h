#include <pico/stdlib.h>

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

void init_led(int led) {
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);
}

// Inicializa LEDs
void init_leds_RGB() {
    init_led(LED_RED);
    init_led(LED_GREEN);
    init_led(LED_BLUE);
}

// Liga LED
void turn_on_led(uint LED) {
  gpio_put(LED, true);
}

// Desliga LED
void turn_off_led(uint LED) {
  gpio_put(LED, false);
}