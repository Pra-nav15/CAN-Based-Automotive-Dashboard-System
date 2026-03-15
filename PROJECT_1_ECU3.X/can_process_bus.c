/*
 * File:   can_process_bus.c
 * Author: PRANAV
 *
 * Created on March 9, 2026, 3:41 PM
 */


#include <xc.h>
#include "message_id.h"
#include "clcd_display.h"
#include "can.h"

void can_process_bus(void)
{
    uint16_t msg_id;
    uint8_t data;
    uint8_t len;
    
    clcd_print("SPD",LINE1(0));
    clcd_print("GR",LINE1(4));
    clcd_print("RPM",LINE1(8));
    clcd_print("IND",LINE1(12));
    
    can_receive(&msg_id,&data,&len);
    
    if(msg_id == SPEED_MSG_ID)
    {
        display_speed_data(data);
    }
    else if(msg_id == GEAR_MSG_ID)
    {
        display_gear_data(data);
    }
    else if(msg_id == RPM_MSG_ID)
    {
        display_rpm_data(data);
    }
    else if(msg_id == INDICATOR_MSG_ID)
    {
        display_indicator_data(data);
    }
}
