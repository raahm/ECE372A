// Description: This file implements the initialization of an external
// switch.
//----------------------------------------------------------------------//

#include "switch.h"
#include <avr/io.h>

/*
 * Initializes pull-up resistor on PB3 and sets it into input mode
 */
void initSwitchPB3(){
  PORTB |= (1 << PORTB3); // set PB3 as a pull-up when DDRB is set to zero.
  DDRB &= ~(1 << DDB3); // set PB3 as input
}
