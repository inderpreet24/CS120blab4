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
      
     void Origin(){

      switch(button){
      case Init:
       button = Begin;
       break;
    
      case Begin:
      button = Start;
      break;
      
      case Start:
      if(PINA == 0x03) {
       button = Restart;
     }
      else if (PINA ==0x02){
      button = Decrement;
     } 
     else if (PINA== 0x01){
       button = Increment;
     }
     else{
     button = Start;
      } 
     break;
     
     case Restart:
     button = Start;
    break;
    
   case Increment:
     if (PINA == 0x03){
      button = Restart;
     }
      else if(PINA == 0x00) {
    button = Restart;
     }
     else{
      button = Start;
      }
      
    break;
    
    case WaitI:
    if(PINA == 0x03){
     button = Restart;
      }
    else if(PINA == 0x02){
    button = Decrement;
   }
    else{
    button = Start;
      }
      
    break;
   
    case Decrement:
     if (PINA == 0x03){
       button = Restart;
     }
     else if(PINA == 0x00) {
     button = Start;     
      }
     else{
     button = WaitD;
      }    
     break;
 
     case WaitD:
      if(PINA == 0x03){
      button = Restart;
      }
      else if(PINA == 0x02){
      button = WaitD;
      } 
      else if(PINA== 0x01){
       button = Increment;
       }
       else{
       button = Start;
      }
    
     break;
    case Restart:
      button = Start;
      break;
    
      default:
      button = Init;
      break;

}
  	switch(button){
	case Init:
        break;
        case Begin:
        PORTC = 0x07;
        break;
        case Start:
        break;
        case Increment:
        if( PORTC < 0x09) {
        PORTC = PORTC + 1;
       }
        break;
        case Decrement:
	 if(PORTC > 0x00) {
       PORTC = PORTC - 1;
       }
        break;
        case WaitI:
       break;
       case WaitD:
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
    button = Init;
    PORTC = 0x07;
    while (1) {
     Origin();
    }
    return 1;
}
