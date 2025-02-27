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

In practice, the value of 125 Ohms is not manufactured and we must choose a standard value immediately above 125 Ohms, taking into account the tolerance, from the standard series as follows:

In the E6 series we have the values: 1.0, 1.5, 2.2, 3.3, 4.7, 6.8. To obtain the values ​​of hundreds of Ohms we will multiply the given values ​​by 100 thus we obtain: 100, 150, 220, 330, 470, 680 Ohms.

So apparently we can choose the value of 150 Ohms because the value of 100 Ohms is less than 125 Ohms.

For the E6 series the tolerance is 20 percent, which is 30 Ohms. So for a resistor marked 150 Ohms, the actual value of its resistance can vary between 120 Ohms and 180 Ohms.

If in the worst case scenario one of the resistors used is practically 120 Ohms, the maximum current through the microcontroller pin will be:

Ipin = 5V / 120 = 0.0416A = 41.6mA

If in the worst case scenario one of the resistors used is practically 120 Ohms, the maximum current through the microcontroller pin will be:

So from the E6 series I choose 220 Ohms, from the E12 series I choose 180 Ohms, from the E24 series I choose 150 Ohms, from the E48 series I choose 133 Ohms, from the E96 series I choose 130 Ohms, from the E192 series I choose 127 Ohms.

Next I will consider a value of 220 Ohms which is a more common value, easier to find and cheaper.

In this situation, when we use a current limiting resistor of 220 Ohms, the maximum current will be:

Ipin = 5V / 220 = 0.0227A = 22.7 mA

The power dissipated by these resistors can be a maximum of:

P = R*I*I = 220 * 0.0227 * 0.0227 = 0.113 W

The standard values ​​for powers are 0.125W, 0.25W, 0.5W, 1W for trough hole resistors and 0.05W for SMD 0201, 0.062W for SMD 0402, 0.10W for SMD 0603, 0.125W for SMD 0805, 0.25W for SMD 1206, 0.5W for SMD 1210, 0.75W for SMD 1210, 1W for SMD 1218, 1W for SMD 2512.

So for our application we will use 0.125W resistors

## Power supply of the tested integrated circuit
Since all pins of the integrated circuit under test are connected to the microcontroller pins through current limiting resistors, it involves connecting the power pins through 220 Ohm resistors and the power pins are also connected through resistors as can be seen in Figure 1.

![ Figure 1 ](/Pictures/Figure1.png)

We assume the present situation where all control pins are connected to ground and only power pin 14 is connected to 5 Volts.

Through the pins of the chip under test we will have a greater or lesser current flowing to ground through the limiting resistors. The current that will enter the chip through the power pin will be the sum of these currents.

This implies the occurrence of a voltage drop across resistor R14 dependent on the current flowing through pin 14 of the tested chip.

If the current is 10 mA this voltage drop will be:

VR14 = IR14 * R14 = 10mA * 220 = 0.01A * 220 = 2.2V

Because this voltage will reduce the supply voltage of the chip under test to:

Vdd = Vcc - VR14 = 5V – 2.2V = 2.8V

For a supply voltage of 2.8 Volts, the operation of the tested chip is no longer guaranteed, so the accuracy of the test is no longer guaranteed.

The same situation can be if all pins are connected to +5V but only pin 7 is connected to ground. The voltage across resistor R1 is subtracted from the supply voltage of the chip under test.

To eliminate this non-compliant situation, I propose connecting the power pins via two transistors as in figure 2.

![ Figure 2 ](/Pictures/Figure2.png)

I removed the resistor R 1 so pin 7 is connected directly to ground via transistor Q1.


