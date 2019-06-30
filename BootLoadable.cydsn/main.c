/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "FreeRTOS_inc.h"
#include "os_resource.h"

portTASK_FUNCTION_PROTO(ledTask, pvParameters);

int main(void)
{
    CySysTickStart();
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //uart_wifi_Start();
    
    xTaskCreate(ledTask, 
                "Led",
                configMINIMAL_STACK_SIZE,
                NULL,
                3,
                NULL);
    
    /* Start Scheduler */
    prvHardwareSetup();

    CyPins_ClearPin(led_user_0);
    isr_sound_start_button_Start();
    
    vTaskStartScheduler();
}

portTASK_FUNCTION(ledTask, pvParameters) 
{
    uint8_t led_state = 0;
    for (;;) 
    {
        if (led_state > 0) 
        {
            led_state = 0;
            //CyPins_ClearPin(led_user_0);
        } 
        else 
        {
            led_state = 1;
            //CyPins_SetPin(led_user_0);
        }
        vTaskDelay(1000);
    }
}

/* [] END OF FILE */
