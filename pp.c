#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"

// Define the GPIO pins for the RGB LED and joystick
#define LED_PIN_R 11
#define LED_PIN_G 12
#define LED_PIN_B 13
#define JOYSTICK_PIN_X 26

void setup_pwm(uint slice_num, uint channel, uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    pwm_set_wrap(slice_num, 255);
    pwm_set_chan_level(slice_num, channel, 0);
    pwm_set_enabled(slice_num, true);
}

int main() {
    stdio_init_all();

    // Initialize the RGB LED pins for PWM
    uint slice_num_r = pwm_gpio_to_slice_num(LED_PIN_R);
    uint channel_r = pwm_gpio_to_channel(LED_PIN_R);
    setup_pwm(slice_num_r, channel_r, LED_PIN_R);

    uint slice_num_g = pwm_gpio_to_slice_num(LED_PIN_G);
    uint channel_g = pwm_gpio_to_channel(LED_PIN_G);
    setup_pwm(slice_num_g, channel_g, LED_PIN_G);

    uint slice_num_b = pwm_gpio_to_slice_num(LED_PIN_B);
    uint channel_b = pwm_gpio_to_channel(LED_PIN_B);
    setup_pwm(slice_num_b, channel_b, LED_PIN_B);

    // Initialize the joystick pin
    adc_init();
    adc_gpio_init(JOYSTICK_PIN_X);
    adc_select_input(0);

    while (true) {
        // Read the joystick value (0-4095)
        uint16_t joystick_value = adc_read();

        // Map the joystick value to PWM duty cycle (0-255)
        uint8_t duty_cycle = joystick_value / 16;

        // Set the PWM duty cycle for all three LEDs
        pwm_set_chan_level(slice_num_r, channel_r, duty_cycle);
        pwm_set_chan_level(slice_num_g, channel_g, duty_cycle);
        pwm_set_chan_level(slice_num_b, channel_b, duty_cycle);

        // Print the joystick value and duty cycle for debugging
        printf("Joystick: %d, Duty Cycle: %d\n", joystick_value, duty_cycle);

        sleep_ms(100);
    }
}