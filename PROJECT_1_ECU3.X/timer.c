/*
 * File:   timer.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:18 AM
 */


#include <xc.h>

void init_timer0(void)
{
    TMR0 = 6;              // Load initial value into Timer0 register
    T0CONbits.T08BIT = 1;  // Set Timer0 to 8-bit mode
    T0CONbits.T0CS = 0;    // Select internal clock source
    T0CONbits.PSA = 1;     // Disable prescaler
    INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    T0CONbits.TMR0ON = 1;  // Start Timer0
}