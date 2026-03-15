/*
 * File:   rpm_display.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:44 AM
 */


#include <xc.h>
#include "clcd_display.h"

unsigned int tx_rpm = 0;

void display_rpm_data(uint8_t data)
{
    tx_rpm = data * 60;
    if (tx_rpm <= 6000) 
    {
        clcd_putch('0' + (tx_rpm / 1000) % 10, LINE2(7));
        clcd_putch('0' + (tx_rpm / 100) % 10, LINE2(8));
        clcd_putch('0' + (tx_rpm / 10) % 10, LINE2(9));
        clcd_putch('0' + (tx_rpm % 10), LINE2(10));
    }
}