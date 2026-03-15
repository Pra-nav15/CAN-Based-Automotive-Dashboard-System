/*
 * File:   timer0.c
 * Author: PRANAV
 *
 * Created on February 28, 2026, 8:59 PM
 */

#include <xc.h>

void init_timer0(void)
{
    TMR0 = 6;              // Load initial timer value
    T0CONbits.T08BIT = 1;  // Set 8-bit mode
    T0CONbits.T0CS = 0;    // Use internal clock
    T0CONbits.PSA = 0;     // Assign prescaler to Timer0
    INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    T0CONbits.TMR0ON = 1;  // Start Timer0
}
