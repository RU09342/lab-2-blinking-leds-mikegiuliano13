# Lab 2: Multiple Blink

Each board contains a blink.c file that blinks 2 LED using a loop structure.

## General Structure

All five boards follow the same general format for achieving 2 blinking LEDs. This is:
stopping the watchdog timer, setting up the output pin, initializing it to 0, then
running an infinite loop to turn off and on each LED at their desired rates.

## Important Distinctions

The boards differed only in th pinout for the second LED.

### MSP430G2553

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

### MSP430FR2311

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

### MSP430F5529

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bits 0 of P1 as output
  P1DIR |= BIT0;
  // Sets up bits 0 of P2 as output
  P4DIR |= BIT7;
  
  // Initializes BIT0 of P1 as 0
  P1OUT = 0x00;
  // Initializes BIT0 of P2 as 0
  P4OUT = 0x00;

  // No parameters means it loops forever
  for (;;) {
      
    // toggle P4.7 at twice the rate of P1.0
	// __delay_cycles() is a handy way to pass timer
	// without having to create a loop with loop variable
    P1OUT ^= BIT0;
	P4OUT ^= BIT7;
    __delay_cycles(700000);
	
    P4OUT ^= BIT7;
    __delay_cycles(700000);
    
  }
  
}

### MSP430FR5994

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Disables default high-impedance mode
  // Done by clearing the register PM5CTL0
  // and unlocking I/O pins  (~LOCKLPM5)
  PM5CTL0 &= ~LOCKLPM5;
  
  // Sets up bits 0 and 1 of P1 as output
  P1DIR |= BIT0 + BIT1;
  
  // Initializes BIT0 and BIT1 of P1 as 0
  P1OUT = 0x00;

  // No parameters means it loops forever
  for (;;) {
      
    // toggle P1.1 at twice the rate of P1.0
	// __delay_cycles() is a handy way to pass timer
	// without having to create a loop with loop variable
    P1OUT ^= BIT0 + BIT1;
    __delay_cycles(700000);
	
    P1OUT ^= BIT1;
    __delay_cycles(700000);
    
  }
  
}

### MSP430FR6989

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
  // Sets up bits 7 of P9 as output
  P9DIR |= BIT7;
  
  // Initializes BIT0 of P1 as 0
  P1OUT = 0x00;
  // Initializes BIT7 of P9 as 0
  P9OUT = 0x00;

  // No parameters means it loops forever
  for (;;) {
      
    // toggle P9.7 at twice the rate of P1.0
	// __delay_cycles() is a handy way to pass timer
	// without having to create a loop with loop variable
    P1OUT ^= BIT0;
	P9OUT ^= BIT7;
    __delay_cycles(700000);
	
    P9OUT ^= BIT7;
    __delay_cycles(700000);
    
  }
  
}

## Extra Work Different LED Colors MSP430G2553

This program switches the color of the LED being used by the toggle of a button.
If a press is detected, the color is changed and blinks until the button is pressed.

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