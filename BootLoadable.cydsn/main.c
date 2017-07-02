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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Wifi Module Enabler
    CyPins_SetPin(wifi_enable_0);
    CyDelay(150);
    CyPins_SetPin(wifi_reset_0);

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
