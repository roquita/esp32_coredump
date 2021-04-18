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

void mytask(void *arg)
{
    printf("Restarting now.\n");
    int *a = 0;
    *a = 0x25;
    printf("a:%i\n", *a);
    esp_restart();
    while (true)
    {

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
void app_main(void)
{
    vTaskDelay(pdMS_TO_TICKS(3000));
    xTaskCreatePinnedToCore(mytask, "mytask", 2 * 1024, NULL, 2, NULL, 1);
}
