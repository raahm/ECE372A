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
  testLED();
}

/*
 * Turns on a specified LED and turns off other LEDS using PORTB registers
 * and bit operations. This function should also not affect other bits in
 * PORTB while turning on an off LEDs. You can choose which number corresponsds
 * to which LED, but this mapping should be matching the testLED function.
 */
void turnOnLED(int led){

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
