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
    
   enum LED{LED_ON, LED_OFF} led;
    void State(){
       switch(led){
         case LED_OFF:
         if(PINA){
         led = LED_OFF;
        
       }
       break;
       case LED_ON:
       if(!PINA){
        led = LED_ON;
       
      }
      break;
      else{
      led = LED_OFF;
     }
    break;
     default:
      led = LED;
      break;
}
    switch(led){
    case LED_OFF 
    PORTB = 0x01;
    break;
    case LED_ON:
    PORTB = 0x02;
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
   State();          
    }
    return 1;
}
