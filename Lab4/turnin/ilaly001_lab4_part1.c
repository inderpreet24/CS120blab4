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
    
   enum LED{ Init, LED_ONP,LED_ONR, LED_OFFP, LED_OFFR} led;
    void Button(){
       switch(led){
       case Init:
       led = LED_ONP;
       
       break;
      
       case LED_ONP:
       if((PINA & 0x01)==0x01){
        led = LED_ONP;
       }
       else{
       led = LED_ONR;
     } 
     
     break;
       
      case LED_ONR:
      PORTB = 0x01;
      if((PINA & 0x01)== 0x01){
      led = LED_OFFP;
     }
     else{
     led = LED_ONR;
    }   
    break;
     case LED_OFFP:
     if((PINA & 0x01) == 0x01){
     led = LED_OFFP;
    }
    else {
     led = LED_OFFR;
    } 
    break;
     
     case LED_OFFR:
     if((PINA & 0x01) == 0x01){
      led = LED_ONR;
     }
     else {
     led = LED_OFFR;
    }
     break;
       
     default:
     led = Init;
      break;
    
}
    switch(led){
    case Init:
    PORTB = 0x01; 
    break;
    
    case LED_ONP:
    PORTB = 0x01;
    break;
    
    case LED_ONR:
    break;
    
    case LED_OFFP:
    PORTB = 0x02;
    break;
    
    case LED_OFFR:
    break;
     
    default:
   
   PORTB = 0x01;
    break;
   
}
}
int main(void) {   
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    
    while (1) {
   Button();          
    }
    return 1;
}
