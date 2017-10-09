// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bits 0 and 6 of P1 as output
  P1DIR |= BIT0 + BIT6;
  
  // Initializes BIT0 and BIT6 to 0
  P1OUT = 0x00;

  // No parameters means it loops forever
  for (;;) {
      
    // toggle P1.6 at twice the rate of P1.0
	// __delay_cycles() is a handy way to pass timer
	// without having to create a loop with loop variable
    P1OUT ^= BIT0 + BIT6;
    __delay_cycles(700000);
	
    P1OUT ^= BIT6;
    __delay_cycles(700000);
    
  }
  
}
