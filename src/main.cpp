#include<driver/gpio.h>
#include<iostream>
#include<chrono>
#include<thread>
//////////////////////////////////////////
constexpr gpio_num_t g_ledRed = GPIO_NUM_45;
constexpr gpio_num_t g_ledGreen = GPIO_NUM_17;
constexpr gpio_num_t g_ledBlue = GPIO_NUM_46;
constexpr gpio_num_t g_ledYellow = GPIO_NUM_15;
constexpr gpio_num_t g_Button1 = GPIO_NUM_18;
constexpr gpio_num_t g_Button2 = GPIO_NUM_16;
constexpr gpio_num_t g_Button3 = GPIO_NUM_46;


extern "C" void app_main(void) {
    using namespace std::chrono_literals;
    gpio_config_t io_conf = {
        .pin_bit_mask =  (1ULL << g_ledRed) | (1ULL << g_ledGreen)|(1ULL << g_ledBlue)|(1ULL << g_ledYellow),
        .mode = GPIO_MODE_OUTPUT,  
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,  
        };
    gpio_config_t but_conf = {
        .pin_bit_mask =  (1ULL << g_Button1) | (1ULL << g_Button2)|(1ULL << g_Button3),
        .mode = GPIO_MODE_INPUT,  
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,  
        };


gpio_config(&io_conf);
gpio_config(&but_conf);
while (true)
{
    // Check if any of the buttons are pressed
    
    if(gpio_get_level(g_Button1)==1){
        gpio_set_level(g_ledRed, 0);
    }
    if(gpio_get_level(g_Button2)==1){
        gpio_set_level(g_ledBlue, 0);
    }
    if(gpio_get_level(g_Button3)==0){
        gpio_set_level(g_ledYellow, 0);
    }
    else{
        gpio_set_level(g_ledYellow, 1);
        gpio_set_level(g_ledGreen, 1);
        gpio_set_level(g_ledBlue, 1);
    }
    
}



    }

