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

/* Application Control Variables */
QueueHandle_t user_button_queue_handle = NULL;
bool can_user_button_interrupt = false;

void isr_sof_timer_Interrupt_InterruptCallback(void)
{
    // TODO: How do we handle ISR in face of the RTOS?
}

uint8_t queue_arg = (uint8_t)'U';
void isr_sound_start_button_Interrupt_InterruptCallback(void)
{
    BaseType_t xHigherPriorityTaskWaken = pdFALSE;
    
    if( can_user_button_interrupt )
    {
        can_user_button_interrupt = false;
        xQueueSendFromISR( user_button_queue_handle, &queue_arg, &xHigherPriorityTaskWaken );
    }

    switch_user_ClearInterrupt();
    portYIELD_FROM_ISR( xHigherPriorityTaskWaken );
}

/* User Button Utility Functions */
QueueHandle_t setUserButtonQueueHandle( QueueHandle_t handle )
{
    user_button_queue_handle = handle;
    return user_button_queue_handle;
}

bool setUserButtonCanInterrupt( bool can_interrupt )
{
    can_user_button_interrupt = can_interrupt;
    return can_user_button_interrupt;
}

/* [] END OF FILE */