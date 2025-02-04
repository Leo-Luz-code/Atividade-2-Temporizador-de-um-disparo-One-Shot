#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"

// Definindo os pinos dos leds e do botão
#define GREEN_LED 11
#define RED_LED 12
#define BLUE_LED 13
#define BUTTON 5

volatile bool timer_active = false;
volatile bool debounce_active = false; // Flag para debounce

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

// Função para desligar o último LED e liberar o botão
int64_t turn_off_last_led_callback(alarm_id_t id, void *user_data)
{
    gpio_put(GREEN_LED, 0);
    timer_active = false;
    printf("Led Verde Apagado.\n");
    return 0;
}

// Função para desligar o segundo LED e programar o próximo callback
int64_t turn_off_second_led_callback(alarm_id_t id, void *user_data)
{
    gpio_put(RED_LED, 0);
    add_alarm_in_ms(3000, turn_off_last_led_callback, NULL, false);
    printf("Led Vermelho Apagado.\n");
    return 0;
}

// Função para desligar o primeiro LED e programar o próximo callback
int64_t turn_off_first_led_callback(alarm_id_t id, void *user_data)
{
    gpio_put(BLUE_LED, 0);
    add_alarm_in_ms(3000, turn_off_second_led_callback, NULL, false);
    printf("Led Azul Apagado.\n");
    return 0;
}

int64_t debounce_callback(alarm_id_t id, void *user_data)
{
    if (gpio_get(BUTTON) == 0) // Verifica se ainda está pressionado
    {
        if (!timer_active)
        {
            timer_active = true;

            gpio_put(BLUE_LED, 1);
            gpio_put(GREEN_LED, 1);
            gpio_put(RED_LED, 1);
            printf("Todos os LEDs acesos.\n");

            add_alarm_in_ms(3000, turn_off_first_led_callback, NULL, false);
        }
    }
    debounce_active = false; // Libera para nova detecção
    return 0;
}

void button_callback(uint gpio, uint32_t events)
{
    if (gpio == BUTTON && !debounce_active)
    {
        debounce_active = true;
        add_alarm_in_ms(50, debounce_callback, NULL, false); // Tempo de debounce
    }
}

int main()
{
    stdio_init_all();
    initialize_leds_and_button();

    // Interrupção do botão
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, button_callback);

    while (true)
    {
        sleep_ms(1000);
    }
}
