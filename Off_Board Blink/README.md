# Off Board Blink

The offboard blink used a simple delay cycle program to toggle 4 LEDs at different speeds.
The microcontroller was removed from its development board and placed in a breadboard.

MOSFETS were used to amplify the current to each LED from the 6 mA provided by the 
development board to the 20 mA needed.

## Power Method

The VCC and GND pins of the microcontroller on the breadboard were connected to their
corresponding pins on the development board which was plugged into a computer and fed
3.3 V. 

## Capacitors

A 10 uF bulk capacitor can be seen connected from VCC to GND, and four 0.1 uF capacitors
were sufficient for bypass capacitance. They were placed at the output pins of the four
LEDS at P1.0, P.1.6, P1.4, and P1.7 and each was connected to GND. 

# Reset and Test

The RST pin on the development board was wired to the corresponding pin on the
microcontroller with a current-limit resistor. This meant the board could be reset
still by pressing the RST button on the development board.

The TEST pin on the development board was wired to the corresponding microcontroller
test pin for use with programming the microcontroller directly from the breadboard.

## The setup and footage of the LEDs blinking can be seen in the video in this folder.

