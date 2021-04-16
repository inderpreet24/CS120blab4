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
 
	enum Button { Init, Begin, Increment, Decrement, Restart, Stop} button;
      
     void Start(){
      unsigned char A0 = PINA & 0x01;
      unsigned char A1 = PINA & 0x02;

      switch(button){
      case Init:
       button = Begin;
       break;
    
      case Begin:
     if( A0 && !A1){
        button = Increment;  
     } 
     else if ( !A0 && A1){
      button = Decrement;
     }
     else if (A0 && A1) {
      button = Restart;
     }
     else {
     button = Stop;
    }
    break;

     case Increment:
      button = Stop;
      break;
  
     case Decrement:
     button = Stop;
     break;
     
     case Stop:
     if( A1 && A0) {
      button = Restart;
     }
    else if(!A1 && !A0) {
     button = Begin;
     }
     else{
     button = Stop;
   }
     break;
     
      case Restart:
    if(A1 && A0){
      button = Restart;
    }
   else {
   button = Stop; 
     } 
   break;

  default:
  button = Init;
  break;
}

	switch(button){
	case Init:
        PORTC = 0x07;
 	break;
	case Begin:
        PORTC = 0x07;
 	break;
 	case Increment:
        if(PORTC < 0x09){
      	PORTC++;
 	}
        else{
        PORTC= 0x09;
 	}
 	break;
	case Decrement:
	if(PORTC > 0x00){
     	PORTC--;
        }
 	else{
	PORTC = 0x09;
        }
 	break;
	case Stop:
   	break;
	case Restart:
 	PORTC=0x00;
	break;
	default:
	PORTC = 0x07;
	break;
}
}








int main(void) {
    /* Insert DDR and PORT initializations */ 
    DDRA=0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    button = Init;   
    /* Insert your solution below */
    while (1) {
     Start();
    }
    return 1;
}
