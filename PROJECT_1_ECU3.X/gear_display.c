/*
 * File:   gear_display.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:41 AM
 */


#include <xc.h>
#include "clcd_display.h"

unsigned char gear[] = {'N', '1', '2', '3', '4', '5', 'R', 'C'};

void display_gear_data(uint8_t data)
{
    if(data > 7)
    {
       data = 0;
    }
    if(data == 7)
    {
        clcd_putch('_',LINE2(4));
        clcd_putch(gear[data],LINE2(5));
    }
    else
    {
        clcd_putch(gear[data],LINE2(4));
        clcd_putch(' ',LINE2(5));
    }
}