# Arduino MEGA TTL IC Tester
Integrated Circuit Testers are devices that are used to test logic integrated circuits by sending pulses to their pins according to the truth table associated with the chip under test.

In general, the way it works is that the identification number of the chip that you want to test, for example 74LS00, is transmitted to the IC Tester and a comparison test is performed with the truth table of that chip. This is called manual test mode.

There is also the automatic or smart test mode. This involves the operation of identifying an unknown chip or one that has the marking text erased, which means that we have to perform all possible combinations for controlling the chip's pins.

## Electrical constraints
The maximum input-output current that can be used by a pin in the case of the ATmega 2560 microcontroller is 40 mA, so in order not to damage this microcontroller we must limit the maximum test current to this value. There is also a limit of 200 mA of the maximum total current that can be used by this microcontroller

Because testing a chip that is defective and has a pin that is shorted to the ground pin or any other pin, can cause a very high test current for that pin which can cause the microcontroller to fail if we do not limit the value of this current.

For this purpose, we must limit the maximum current that can pass through any pin under test.

The simplest method for limiting current is to use a resistor.

Since the maximum current that is allowed through a pin of the Atmel 2560 microcontroller is 40 mA, we can determine the value of the limiting resistor:

R = 5V / 40 mA = 5V / 0.04A = 125 Ohms




