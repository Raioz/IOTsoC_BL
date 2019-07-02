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
#include "cyapicallbacks.h"

portTASK_FUNCTION_PROTO(dataFrameTask, pvParameters);

int main(void)
{
    CySysTickStart();
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //uart_wifi_Start();
    
    xTaskCreate(dataFrameTask, 
                "Data",
                configMINIMAL_STACK_SIZE * 2,
                NULL,
                3,
                NULL);
    
    /* Start Scheduler */
    prvHardwareSetup();

    CyPins_ClearPin(led_user_0);
    isr_sound_start_button_Start();
    
    vTaskStartScheduler();
}

QueueHandle_t dataFrameQueue = NULL;
portTASK_FUNCTION(dataFrameTask, pvParameters) 
{
    uint8_t queueItem;
    dataFrameQueue = xQueueCreate(2, sizeof(uint8_t));
    setUserButtonCanInterrupt( true );
    setUserButtonQueueHandle( dataFrameQueue );

    for (;;) 
    {
        if( xQueueReceive( dataFrameQueue, &queueItem, portMAX_DELAY ) )
        {
            vTaskDelay(50);

            if( !CyPins_ReadPin( switch_user_0 ) )
            {
                CyPins_ClearPin( led_user_0 );
            }

            setUserButtonCanInterrupt( true );
        }
    }
}

/* [] END OF FILE */
