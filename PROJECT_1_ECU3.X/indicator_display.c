/*
 * File:   indicator_display.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:47 AM
 */


#include <xc.h>
#include "clcd_display.h"
#include "timer.h"

void display_indicator_data(uint8_t data)
{
    if (sec_flag) 
    {
        if (data == 1) 
        {
            clcd_print("<-", LINE2(12));
            PORTB = 0x01;
        } 
        else if (data == 2) 
        {
            clcd_print("<-->", LINE2(12));
            PORTB = 0x81;
        } 
        else if (data == 3) 
        {
            clcd_print("->", LINE2(14));
            PORTB = 0x80;
        } 
        else if (data == 4) 
        {
            clcd_print("_", LINE2(12));
            PORTB = 0x00;
        }
    } 
    else 
    {
        clcd_print(" ", LINE2(12));
        clcd_print(" ", LINE2(13));
        clcd_print(" ", LINE2(14));
        clcd_print(" ", LINE2(15));
        PORTB = 0x00;
    }
}