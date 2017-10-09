# Lab 2: Button Blink

Each board contains a blink.c file that blinks an LED toggled by an onboard button.

The LED initially starts off and when the button is pressed the LED is on for the
duration the button is held down. When the button is released it turns off.

## General Structure

All five boards follow the same general format for achieving a button-toggled LED.
This is: stopping the watchdog timer, setting up the I/O direction and their initial
states, configuring the pull-up resistor, and checking when the button is pressed to
determine when to toggle the LED.

## Important Distinctions

The boards differed only in the afforementioned GPIO high impedance mode as well as
the pinouts for th pull-up resistor.

The MSP430FR2311, MSP430F5529, and MSP430FR6989 use the same pinouts while the
MSP430G2553 and MSP430FR5994 each use different ones.

### MSP430G2553

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 (LED) to 0
  // Sets up P1.3 as pull-up resistor
  // as opposed to pull-down
  P1OUT = BIT3;
  
  // Connects the on-board resistor to P1.3
  P1REN |= BIT3;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
    
	//Runs when the value of the port input is the same as the input
	//i.e. the button is not pressed
	while(P1IN & BIT3)
        {
            // Output is set to the opposite of what the LED is
			// since button press is low, release is high
			P1OUT &= ~BIT0;
        }
    P1OUT |= 0x01;	// Toggles the LED
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
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 (LED) to 0
  // Sets up P1.1 as pull-up resistor
  // as opposed to pull-down
  P1OUT = BIT1;
  
  // Connects the on-board resistor to P1.1
  P1REN |= BIT1;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
    
	//Runs when the value of the port input is the same as the input
	//i.e. the button is not pressed
	while(P1IN & BIT1)
        {
            // Output is set to the opposite of what the LED is
			// since button press is low, release is high
			P1OUT &= ~BIT0;
        }
    P1OUT |= 0x01;	// Toggles the LED
  }
  
}

### MSP430F5529

// Loads configurations for all MSP430 boards
#include <msp430.h>
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 (LED) to 0
  // Sets up P1.1 as pull-up resistor
  // as opposed to pull-down
  P1OUT = BIT1;
  
  // Connects the on-board resistor to P1.1
  P1REN |= BIT1;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
    
    //Runs when the value of the port input is the same as the input
	//i.e. the button is not pressed
	while(P1IN & BIT1)
        {
            // Output is set to the opposite of what the LED is
			// since button press is low, release is high
			P1OUT &= ~BIT0;
        }
    P1OUT |= 0x01;	// Toggles the LED
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
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 (LED) to 0
  // Sets up P1.6 as pull-up resistor
  // as opposed to pull-down
  P1OUT = BIT6;
  
  // Connects the on-board resistor to P5.6
  P5REN |= BIT6;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
    
	//Runs when the value of the port input is the same as the input
	//i.e. the button is not pressed
	while(P5IN & BIT6)
        {
            // Output is set to the opposite of what the LED is
			// since button press is low, release is high
			P1OUT &= ~BIT0;
        }
    P1OUT |= 0x01;	// Toggles the LED
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
  
  // Sets up bit 0 of P1 as output
  P1DIR |= BIT0;
  
  // Initializes BIT0 (LED) to 0
  // Sets up P1.1 as pull-up resistor
  // as opposed to pull-down
  P1OUT = BIT1;
  
  // Connects the on-board resistor to P1.1
  P1REN |= BIT1;
  
  // Declares loop variable as volatile
  // This prevents compiler from removing it for being "stuck" in a loop
  // when in fact it is working as intended
  volatile unsigned int i;

  // No parameters means it loops forever
  for (;;) {
    
	//Runs when the value of the port input is the same as the input
	//i.e. the button is not pressed
	while(P1IN & BIT1)
        {
            // Output is set to the opposite of what the LED is
			// since button press is low, release is high
			P1OUT &= ~BIT0;
        }
    P1OUT |= 0x01;	// Toggles the LED
  }
  
}

## Extra Work Blink Speed Program MSP430G2553

A three blink-speed toggle program was developed for the MSP430G2553. It starts out 
with both LEDs off, then when the button is pressed, they begin to blink slowly.
Pressing again further icreases the speed to medium, and another press to fast speed.

A further press will stop the LEDs from blinking to restart the cycle again. 
However, it only ensures that they are not blinking, NOT that they are OFF. 
If this happens, the user can reset the program by hitting the RESET button
so that they are in fact off. As a design decision, it was chosen to leave this
behavior in due to the ease of the reset button being readily available.

The program makes use of interrupts and a case statement to accomplish this.

#include <msp430g2553.h>
 
volatile unsigned int i, delay, mode;
 
int main(void) {
    
  // Stops the watchdog timer
  WDTCTL = WDTPW + WDTHOLD;
  
  // Sets up bits 0 and 6 of P1 as output
  P1DIR |= BIT0 + BIT6;
  
  // Initializes BIT0 and BIT6 to 0
  // Also sets P1.3 (button) as output
  P1OUT = BIT3;
  
  P1IE |= BIT3; // Interrupt Enabled on P1.3 (the button)
  P1IFG &= ~BIT3; // CLears interrupt flag once button P1.3 is pressed
  
  P1REN |= BIT3; // Enable Pull Up on (P1.3)
  P1IES |= BIT3; // P1.3 Hi/lo edge
 
__bis_SR_register(GIE); // Enables all integrupts (Global)

  // Initializes the amount of delay between LED changes
  delay = 0x6000;
  
  // Used in case statement to set speed of LED, initially set to slowest
  mode = 0;

  // No parameters means it loops forever
  for (;;) {
    
    if (mode != 0) {  
    // toggle bit 0 of P1
    P1OUT ^= BIT0 + BIT6;
    
    // delay for a while
    for (i = 0; i < delay; i++);
    }
  }
  
}

// Interrupt subroutine
// Called whenever button is pressed
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    mode++; // Increase mode
    switch (mode) {
    case 0:
        break;
    case 1:
        delay = 0x6000; // Slow timing
        break;
    case 2:
        delay = 0x3500; // Medium timing
        break;
    case 3:
        delay = 0x1000; // Fast timing
        break;
    default:
		// Catchall in case of error (should not end up here)
		// Resets mode and sets to slow timing
        delay = 0x6000;
        mode = 0;
	}
    
    P1IFG &= ~BIT3; // P1.3 interrupt flag cleared
}	