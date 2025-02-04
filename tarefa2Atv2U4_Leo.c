#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

// Definindo os pinos dos leds e do botão
#define GREEN_LED 11
#define RED_LED 12
#define BLUE_LED 13
#define BUTTON 5

// Função para inicializar os leds e o botão
void initialize_leds_and_button()
{
    gpio_init(BLUE_LED);
    gpio_init(RED_LED);
    gpio_init(GREEN_LED);
    gpio_init(BUTTON);

    gpio_set_dir(BLUE_LED, GPIO_OUT);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
}

int main()
{
    stdio_init_all();

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
