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
    
   enum LED{ Init, LED_ON, LED_OFF} led;
    void Button(){
       switch(led){
       case Init:
       led = LED_OFF;
       
       break;
      
       case LED_OFF:
       if(PINA == 0x01){
        led = LED_ON;
       }
       else{
       led = LED_OFF;
     } 
     
     break;
       
      case LED_ON:
      if(PINA == 0x01){
      led = LED_OFF;
     }
     else{
     led = LED_ON;
    }   
    break;
     
     default:{
      break;
    }
}
    switch(led){
    case Init:
    { 
    break;
    }
    case LED_OFF:
    PORTB = 0x01;
    break;
    case LED_ON:
    PORTB = 0x02;
    break;
    default:
   {
    break;
    }
}
}
int main(void) {   
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    led = Init;
    while (1) {
   Button();          
    }
    return 1;
}
