#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



#define GPIO_OUT *((volatile __uint32_t *) 0x3FF44004)
#define GPIO_EN  *((volatile __uint32_t *) 0x3FF44020)

#define GPIO_PIN 2

void app_main(void)
{

    GPIO_EN |= (1 << GPIO_PIN);


    while (1) {
        
        GPIO_OUT |= (1 << GPIO_PIN);
        vTaskDelay(1000 / portTICK_PERIOD_MS);  

        GPIO_OUT &= ~(1 << GPIO_PIN);
        vTaskDelay(1000 / portTICK_PERIOD_MS); 
    }

}
