/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 26, 2026, 8:37 PM
 */


#include <xc.h>
#include "clcd_display.h"
#include "adc.h"
#include "gear.h"
#include "message_id.h"
#include "can.h"

#define _XTAL_FREQ 20000000

static void init_config(void)
{
    init_digital_keypad();
    init_adc();  
    init_can();
}
void main(void) 
{
    init_config();
    unsigned short adc_reg_value;
    unsigned char speed;
    unsigned char key;
	unsigned char i= 0;
    unsigned char collision_flag = 0;
    while(1)
    {
	    key = read_digital_keypad(EDGE);
        if (key != ALL_RELEASED)
        {
            if(key == SWITCH1)
            {
                if(i<6)
                {
                  i++;
                }
            }
            else if(key == SWITCH2)
            {
                if(i>0)
                {
                  i--;
                }
            }
            else if(key == SWITCH3)
            {
                collision_flag = 1;
                i=7;
            }
            if(collision_flag)
            {
                if(key == SWITCH1 || key == SWITCH2)
                {
                    i = 0;
                    collision_flag=0;
                }
            }
        }
        adc_reg_value = read_adc(CHANNEL4);
        speed =  adc_reg_value/10.23; 
        can_transmit(SPEED_MSG_ID,&speed, sizeof(char));
        __delay_ms(80);
        can_transmit(GEAR_MSG_ID,&i,sizeof(char));
        __delay_ms(80);
    }
}
