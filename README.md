# AC_Control_SIT210_Project
A project to control split A/C via smartphone or web browser using Raspberry Pi and Particle Argon

CONNECTIONS:

Raspberry Pi:
DHT22: 
  the first pin from the left  >>  3.5V
  the second pin from the left >>  GPIO 17 + 10K ohm resistor >> 3.5V 
  the third pin from the left  >>  N/A
  the forth pin from the left  >>  Gnd
  
  A digram example: https://ibb.co/sWFPrhX
  
IR Transimtter:
  long leged pin >> GPIO 4
  short leged pin >> 220 ohm resistor >> Gnd
  
  
Particl Argon:
 Photoresistor pin >> A5
 Photoresistor pin >> A0 + 10K ohm resistor >> Gnd
