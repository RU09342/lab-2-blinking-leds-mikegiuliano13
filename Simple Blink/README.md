# Lab 2: Simple Blink

Each board contains a blink.c file that blinks a single LED using a loop structure.

## General Structure

All five boards follow the same general format for achieving a blinking LED. This is:
stopping the watchdog timer, setting up the output pin, initializing it to 0, then
running an infinite loop to turn off and on the LED at an even interval.

## Important Distinctions

### MSP430G2553, MSP430F5529

These boards require no modification of the general structure for them to work.
Therefore, the same code is used for all three.

### MSP430FR6989, MSP430FR5994, MSP430FR2311

These boards require that the GPIO default high impedance mode that runs on startup
is DISABLED. This mode locks I/O pin states but loses configuration of all register
settings such as PxDIR, PxREN, and PxOUT. Thus, it is disabled for this code.

## blink.c for MSP430G2553, MSP430F5529

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 to 0
  P1OUT = 0x00;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
      
    // Toggle bit 0 of P1 using XOR
    P1OUT ^= BIT0;
    
    // Delay for a while
    for (i = 0; i < 0x6000; i++); //note to self: can also use __delay_cycles(10000);
  }
  
}

## blink.c for MSP430FR6989, MSP430FR5994, MSP430FR2311

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Disables default high-impedance mode
  // Done by clearing the register PM5CTL0
  // and unlocking I/O pins  (~LOCKLPM5)
  PM5CTL0 &= ~LOCKLPM5;
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 to 0
  P1OUT = 0x00;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
      
    // Toggle bit 0 of P1 using XOR
    P1OUT ^= BIT0;
    
    // Delay for a while
    for (i = 0; i < 0x6000; i++); //note to self: can also use __delay_cycles(10000);
  }
  
}