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
 
     enum Button { Init, Begin, Start,  Restart, Increment, Decrement, WaitI, WaitD} button;
      
     void Start(){

      switch(button){
      case Init:
       button = Begin;
       break;
    
      case Begin:
      button = Start;
      break;
      
      case Start:
      if((PINA & 0x03) == 0x03) {
       button = Restart;
     }
      else if ((PINA & 0x01)==0x01){
      button = WaitI;
     } 
     else if ((PINA & 0x02) == 0x02){
       button = WaitD;
     } 
     break;
     case Restart:
     if((PINA & 0x03) == 0x03) {
       button = Restart;
     }
    else {
    button = Start;
    }
    break;
    
   case Increment:
     if ((PINA & 0x01)==0x01){
      button = Increment;
     }
      else{
    button = Start;
     }
    break;
    
    case WaitI:
    button = Increment;
    break;
   
    case Decrement:
     if ((PINA & 0x02) == 0x02){
       button = Decrement;
     }
     else {
     button = Start;     

}    
     break;
 
     case WaitD:
      button = Decrement;
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
        case Start:
        break;
        case Increment:
        break;
        case Decrement:
        break;
        case WaitI:
        if( PORTC < 0x09) {
        PORTC = PORTC + 1;
       }
       break;
       case WaitD:
       if(PORTC > 0x00) {
       PORTC = PORTC - 1;
       }
       break;
       case Restart:
       PORTC = 0x00;
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
    /* Insert your solution below */
    while (1) {
     Start();
    }
    return 1;
}
