/*
 * File:   can_process_bus.c
 * Author: PRANAV
 *
 * Created on March 6, 2026, 8:26 AM
 */


#include <xc.h>
#include "clcd_display.h"
#include "can.h"
#include "message_id.h"

uint16_t message_id;
uint8_t data;
uint8_t len;

void can_process_bus(void)
{
    clcd_print("SPD",  LINE1(0));
    clcd_print("GR", LINE1(5));
    clcd_print("RPM", LINE1(8));
    clcd_print("IND", LINE1(11));
    can_receive(&message_id, &data, &len);
    if(message_id == SPEED_MSG_ID)
    {
        display_speed_data(data);
    }
    else if(message_id == GEAR_MSG_ID)
    {
        display_gear_data(data);
    }
    else if (message_id == RPM_MSG_ID) 
    {
        display_rpm_data(data);
    }
    else if (message_id == INDICATOR_MSG_ID) 
    {
        display_indicator_data(data);
    }
}

