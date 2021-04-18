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
enum Button{Init, Door, LOCKED,  UNLOCKEDX, UNLOCKEDY, UNLOCKEDDoor, RELEASEP, PRESSY } button;
void Lock(){
switch(button){

case Init:
button = Door;
break;

case Door:
if(PINA == 0x80){
button = LOCKED;
}
else if ((PINA == 0x04) && (PINA != 0x01) && (PINA != 0x02)){
  button = RELEASEP;
}
else{
button = Door;
}
break;

case LOCKED:
button = Init;
break;


case UNLOCKEDX:
if(PINA == 0x80){
 button = LOCKED;
}
else if((PINA != 0x04) && (PINA != 0x01) && (PINA == 0x02)){
button = UNLOCKEDY;
}
else{
button = Door;
}
break;

case UNLOCKEDY:
if(PINA == 0x80){
button = LOCKED;
}
else if ((PINA == 0x04) && (PINA != 0x01) && (PINA == 0x02)){
button = UNLOCKEDDoor;
}
else{
button = Init;
}
break;

case UNLOCKEDDoor:
button = Init;
break;





case PRESSY:
if(PINA == 0x02){
button = PRESSY;
}
else if(PINA == 0x00){
button = UNLOCKEDDoor;
}
else{
button = Init;
}
break;




case RELEASEP:
if(PINA == 0x04){
button = RELEASEP;
}
else if(PINA == 0x00) {
button = PRESSY;
}
else{
button = Init;
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

case UNLOCKEDDoor:
PORTB = 0x01;
break;

case PRESSY:

break;

case RELEASEP:
break;

case Door:
break;

case UNLOCKEDY:
//PORTB = 0x01;
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
    PORTB = 0x00;
    while (1) {
    Lock();
    }
    return 1;
}
