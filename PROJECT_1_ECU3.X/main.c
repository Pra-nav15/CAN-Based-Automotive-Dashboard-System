/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on March 2, 2026, 10:01 AM
 */


#include <xc.h>
#include "clcd_display.h"
#include "can.h"
#include "timer.h"

void init_config(void)
{
	init_clcd();
	init_can();
    init_timer0();
    GIE = 1;
    PEIE = 1;
    TRISBbits.RB0 = 0x00;
    TRISBbits.RB7 = 0x00;
    PORTBbits.RB0 = 0x00;
    PORTBbits.RB7 = 0x00;
}

void main(void)
{    
	init_config();
	while (1)
	{
        can_process_bus();
	}
}