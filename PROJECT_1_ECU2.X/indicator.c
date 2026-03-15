/*
 * File:   indicator.c
 * Author: PRANAV
 *
 * Created on February 28, 2026, 9:05 PM
 */

#include <xc.h>
#include "indicator.h"

void init_digital_keypad(void)
{
    TRISC = TRISC | INPUT_PINS;
}
unsigned char read_digital_keypad(unsigned char type)
{
    static unsigned char flag = 0;
    if(type == LEVEL)
    {
        return KEY_PORT & INPUT_PINS;
    }
    else if(type == EDGE)
    {
        if(((KEY_PORT & INPUT_PINS) != ALL_RELEASED) && flag)
        {
            flag = 0;
            return KEY_PORT & INPUT_PINS; // return the switch is pressed
        }
        else if((KEY_PORT & INPUT_PINS) == ALL_RELEASED)
        {
            flag = 1;
        }
        return ALL_RELEASED;
    }
    else
    {
        return 0x0F;  // no switch is pressed
    }
}