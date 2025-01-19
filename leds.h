#include <pico/stdlib.h>

#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

// Inicializa LEDs
void init_leds_RGB() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}
// Liga LED
void turn_on_led(uint LED) {
  gpio_put(LED, true);
}

// Desliga LED
void turn_off_led(uint LED) {
  gpio_put(LED, false);
}