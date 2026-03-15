/* 
 * File:   gear.h
 * Author: PRANAV
 *
 * Created on February 26, 2026, 8:29 PM
 */

#ifndef GEAR_H
#define	GEAR_H

#define KEY_PORT          PORTC

#define EDGE              0
#define LEVEL             1

#define SWITCH1           0x0E
#define SWITCH2           0x0D
#define SWITCH3           0x0B
#define SWITCH4           0x07

#define ALL_RELEASED      0x0F
#define INPUT_PINS        0x0F

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char type);

#endif	/* GEAR_H */

