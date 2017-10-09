// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Disables default high-impedance mode
  // Done by clearing the register PM5CTL0
  // and unlocking I/O pins  (~LOCKLPM5)
  PM5CTL0 &= ~LOCKLPM5;
  
  // Sets up bits 0 of P1 as output
  P1DIR |= BIT0;
  // Sets up bits 0 of P2 as output
  P2DIR |= BIT0;
  
  // Initializes BIT0 of P1 as 0
  P1OUT = 0x00;
  // Initializes BIT0 of P2 as 0
  P2OUT = 0x00;

  // No parameters means it loops forever
  for (;;) {
      
    // toggle P2.0 at twice the rate of P1.0
	// __delay_cycles() is a handy way to pass timer
	// without having to create a loop with loop variable
    P1OUT ^= BIT0;
	P2OUT ^= BIT0;
    __delay_cycles(700000);
	
    P2OUT ^= BIT0;
    __delay_cycles(700000);
    
  }
  
}