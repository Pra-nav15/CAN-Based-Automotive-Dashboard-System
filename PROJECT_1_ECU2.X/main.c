/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on February 28, 2026, 8:58 PM
 */

#include <xc.h>
#include "indicator.h"
#include "adc.h"
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
    unsigned char rpm = 0;
    unsigned char ecu2_key;
    unsigned char mode = 0;
    unsigned short adc_reg_value;
    uint16_t msg_id;
    uint8_t data;
    uint8_t len;
    while (1) 
    {
        ecu2_key = read_digital_keypad(EDGE);
        if (ecu2_key != ALL_RELEASED) 
        {
            if (ecu2_key == SWITCH1) 
            {
                mode = 1;
            } 
            else if (ecu2_key == SWITCH2) 
            {
                mode = 2;
            } 
            else if (ecu2_key == SWITCH3) 
            {
                mode = 3;
            }
            else if (ecu2_key == SWITCH4) 
            {
                mode = 4;
            }
        }
        adc_reg_value = read_adc(CHANNEL4);
        rpm = (adc_reg_value)/10.23;
        can_transmit(RPM_MSG_ID, &rpm, sizeof (char));
        __delay_ms(80);
        can_transmit(INDICATOR_MSG_ID, &mode, sizeof (char));
        __delay_ms(80);
    }
}