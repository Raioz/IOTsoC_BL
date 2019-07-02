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
#ifndef CYAPICALLBACKS_H
#define CYAPICALLBACKS_H
    
#include "FreeRTOS.h"
#include "queue.h"
#include "stdbool.h"

    /*Define your macro callbacks here */
    /*For more information, refer to the Writing Code topic in the PSoC Creator Help.*/
#define isr_sof_timer_INTERRUPT_INTERRUPT_CALLBACK
#define isr_sound_start_button_INTERRUPT_INTERRUPT_CALLBACK

void isr_sof_timer_Interrupt_InterruptCallback(void);
void isr_sound_start_button_Interrupt_InterruptCallback(void);

/* Utility Functions */
QueueHandle_t setUserButtonQueueHandle( QueueHandle_t handle );
bool setUserButtonCanInterrupt( bool can_interrupt );
    
#endif /* CYAPICALLBACKS_H */   
/* [] */
