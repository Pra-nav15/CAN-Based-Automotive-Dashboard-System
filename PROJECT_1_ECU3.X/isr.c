/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:23 AM
 */


#include <xc.h>

volatile unsigned int idle_count = 0;
extern volatile unsigned char sec_flag = 0;
void __interrupt() isr(void)
{
    // Check if TMR0 interrupt flag is set
    if (TMR0IF == 1)
    {
        TMR0IF = 0;   // Clear the interrupt flag
        idle_count++; // Increment idle counter
        // Toggle sec_flag every 500 interrupts
        if (idle_count == 5000)
        {
            idle_count = 0;       // Reset counter
            sec_flag = !sec_flag; // Toggle flag
        }
        TMR0 = TMR0 + 8; // Reload timer
    }
}
