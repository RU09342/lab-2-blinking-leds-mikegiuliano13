// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets bit 3 to read as input
  // and bits 0 and 6 of P1 as output
  P1DIR = 0x65;
  
  // Initializes LEDs off
  // Sets up P1.3 as pull-up resistor
  // as opposed to pull-down
  P1OUT = 0x08;
  
  // Connects the on-board resistor to P1.3
  P1REN |= BIT3;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i = 0;

  // No parameters means it loops forever
  for (;;) {
    
	//Runs when the value of the port input is not the same as the input
	//i.e. the button is pressed
	if ((P1IN & BIT3) == 0) {
		if (i == 1) 
			i = 0;
        if (i == 0)
			i = 1;
    }
	
	switch (i) {
		case 0:
			P1OUT ^= BIT0; // Toggle Red LED
			break;
		case 1:
			P1OUT ^= BIT6; // Toggle Green LED
			break;
	}
	
	__delay_cycles(100000);
	
  }
}
