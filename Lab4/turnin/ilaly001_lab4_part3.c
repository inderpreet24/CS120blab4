/*	Author: ilaly001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum Button{Init, LOCKED, UNLOCKEDX, UNLOCKEDY } button;
void Lock(){
switch(button){

case Init:
button = LOCKED;
break;

case LOCKED:
if(PINA == 0x80){
button = LOCKED;
}
else if ((PINA == 0x04) && (PINA != 0x01) && (PINA != 0x02)){
  button = UNLOCKEDX;
}
else{
button = LOCKED;
}
break;

case UNLOCKEDX:
if(PINA == 0x80){
 button = LOCKED;
}
else if((PINA != 0x04) && (PINA != 0x1) && (PINA == 0x02)){
button = UNLOCKEDY;
}
else{
button = LOCKED;
}
break;

case UNLOCKEDY:
if(PINA == 0x80){
button = LOCKED;
}
else{
button = UNLOCKEDY;
}
break;

default:
button = Init;
break;
}
switch(button){
case Init:
break;

case LOCKED:
PORTB = 0x00;
break;

case UNLOCKEDX:
break;

case UNLOCKEDY:
PORTB = 0x01;
break;
default:
break;
}
}






int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PINA = 0xFF;
 	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    button = Init;
    while (1) {
    Lock();
    }
    return 1;
}
