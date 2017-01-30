// Description: This file implements turnOnLED and initLED to control
// the LEDs.
//----------------------------------------------------------------------//


#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

/*
 * Initializes pins B6, B5, and B4 to be in output mode using the DDR register
 * and bit operations. Other bits in DDRB must not be affected by this
 * assignment.
 */
void initLED(){
  DDRB |= (1 << DDB4);
  DDRB |= (1 << DDB5);
  DDRB |= (1 << DDB6);
  testLED();
}

/*
 * Turns on a specified LED and turns off other LEDS using PORTB registers
 * and bit operations. This function should also not affect other bits in
 * PORTB while turning on an off LEDs. You can choose which number corresponsds
 * to which LED, but this mapping should be matching the testLED function.
 */
void turnOnLED(int led){
  PORTB &= (0 << PORTB4);
  PORTB &= (0 << PORTB5);
  PORTB &= (0 << PORTB6);

  // if(led == 0)
  //   PORTB |= (1 << PORTB6);
  // else if (led == 1)
  //   PORTB |= (1 << PORTB5);
  // else
  //   PORTB |= (1 << PORTB4);
  switch(led) {
    case 0:
      PORTB |= (1 << PORTB6);
      break;
    case 1:
      PORTB |= (1 << PORTB5);
      break;
    case 2:
      PORTB |= (1 << PORTB4);
      break;
  }

}

/*
 * Tests initLEDs and turnOnLED by turning on each LED in succession.
 */
void testLED(){
  turnOnLED(0);
  _delay_ms(250.0);
  turnOnLED(1);
  _delay_ms(250.0);
  turnOnLED(2);
  _delay_ms(250.0);
}
