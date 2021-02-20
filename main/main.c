/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"

void app_main(void)
{
    printf("Lチカ!!!\n");
    gpio_config_t PINA;
    PINA.pin_bit_mask = (1ULL << 2);
    PINA.mode = GPIO_MODE_OUTPUT;
    PINA.pull_up_en = false;
    PINA.pull_down_en = false;
    PINA.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&PINA);

    /* Print chip information */
    for (int i = 100; i >= 0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
        if (i % 2)
            gpio_set_level(GPIO_NUM_2, 1);
        else
            gpio_set_level(GPIO_NUM_2, 0);

        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
