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
#include "cyapicallbacks.h"

void isr_sof_timer_Interrupt_InterruptCallback(void)
{
    // TODO: How do we handle ISR in face of the RTOS?
}

uint8_t trigger_mode = 0;
void isr_sound_start_button_Interrupt_InterruptCallback(void)
{
    // TODO: Design code that handles button press
    if( !trigger_mode )
    {
        CyPins_ClearPin(led_user_0);
        trigger_mode = 1;
    }
    else 
    {
        CyPins_SetPin(led_user_0);
        trigger_mode = 0;
    }

    switch_user_ClearInterrupt();
}

/* [] END OF FILE */