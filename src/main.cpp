// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           24 January 2017
// Assignment:     Lab 0 part 2
//
// Description: This file contains a programmatic overall description of the
// program. It should never contain assignments to special function registers
// for the exception key one-line code such as checking the state of the pin.
//
// Requirements:
//----------------------------------------------------------------------//
#include <Arduino.h>
#include <avr/io.h>
#include "led.h"
#include "switch.h"

/*
 * Define a set of states that can be used in the state machine using an enum
 */
 typedef enum stateType_enum {
   led_on, led_off
 } stateType;

 stateType state = led_on;

int main(){

  /*
  * Implement a state machine in the while loop which achieves the assignment
  * requirements.

  */
  Serial.begin(9600);
  initSwitchPB3();

  //while(1){
    // testLED();
    // switch(state) {
    //   case led_off :
    //   Serial.println("In state: led off.\n");
    //     if(PINB & (1 << PINB3)) {
    //       Serial.println("Switch pressed.\n");
    //       state = led_on;
    //     }
    //     break;
    //   case led_on :
    //     Serial.println("In state: led on.\n");
    //     if(!(PINB & (1 << PINB3))) {
    //       Serial.println("Switch released.\n");
    //       state = led_off;
    //     }
    //     break;
    // }
    while(1){
    switch(state){
      case led_off:
        Serial.println("In state: led_off.");
        if((PINB & (1 << PINB6))){
          Serial.println("Pin pressed.");
          state = led_on;
        }
        PORTB &= ~(1 << PORTB7);
        break;
      case led_on:
        Serial.println("In state: led_on.");
        if(!(PINB & (1 << PINB6))){
          Serial.println("Pin released.");
          state = led_off;
        }
        PORTB |= (1 << PORTB7);
        break;
    }
  }
  //}

  return 0;
}
