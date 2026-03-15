/*
 * File:   speed_display.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:39 AM
 */


#include <xc.h>
#include "clcd_display.h"

void display_speed_data(uint8_t data)
{
   uint8_t speed;
    
   speed = data; 
    
    if(speed > 99)
    {
        clcd_print("100", LINE2(0));
    }
    else
    {
        clcd_putch('0'+ (speed/10)%10, LINE2(0));
        clcd_putch('0'+ (speed%10), LINE2(1));
        clcd_putch(' ', LINE2(2));
    }
}
