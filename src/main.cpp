#include<driver/gpio.h>
#include<iostream>
constexpr gpio_num_t g_ledRed = GPIO_NUM_45;
constexpr gpio_num_t g_ledGreen = GPIO_NUM_17;
constexpr gpio_num_t g_ledBlue = GPIO_NUM_46;
constexpr gpio_num_t g_ledYellow = GPIO_NUM_15;

extern "C" void app_main(void) {
    // Initialize the LED pin as a output
    gpio_config_t io_conf = {
        .pin_bit_mask =  (1ULL << g_ledRed) | (1ULL << g_ledGreen)|(1ULL << g_ledBlue)|(1ULL << g_ledYellow),
        .mode = GPIO_MODE_OUTPUT,  
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,  
        };


gpio_config(&io_conf);
gpio_num_t ledPins[] = {g_ledRed, g_ledGreen, g_ledBlue, g_ledYellow};
for (int i = 0; i < sizeof(ledPins)/sizeof(ledPins[0]); i++) {
    gpio_set_level(ledPins[i], 1);
}

std::cout<<"Hello World!"<<std::endl;

    }

