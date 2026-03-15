/*
 * File:   isr.c
 * Author: PRANAV
 *
 * Created on February 28, 2026, 8:58 PM
 */

#include <xc.h>

volatile unsigned int idle_count = 0;
volatile unsigned char sec_flag = 0;

void __interrupt() isr(void)
{
    // Check if TMR0 interrupt flag is set
    if (TMR0IF == 1)
    {
        TMR0IF = 0;   // Clear the interrupt flag
        idle_count++; // Increment idle counter
        // Toggle sec_flag every 500 interrupts
        if (idle_count == 100)
        {
            idle_count = 0;       // Reset counter
            sec_flag = 1; // Toggle flag
        }
        TMR0 = TMR0 + 8; // Reload timer
    }
}