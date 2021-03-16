# AC_Control_SIT210_Project
A project to control split A/C via smartphone or web browser using Raspberry Pi and Particle Argon

for the IR decoder you can decode using Arduino or Raspberry Pi, if you are using Arduino you will find the arduino sketch in the folder called 'IRrecord' and if you'r using Raspberry then you will find a file called 'LIRC installation and configuration' 




CONNECTIONS:


DHT22 >> Raspberry Pi
    the first pin from the left  >>  3.5V
    the second pin from the left >>  GPIO 17 + 10K ohm resistor >> 3.5V 
    the third pin from the left  >>  N/A
    the forth pin from the left  >>  Gnd
    A digram example:https://ibb.co/sWFPrhX
 -------------------------------- 
IR Transimtter >> Raspberry Pi
    long leged pin >> GPIO 4
    short leged pin >> 220 ohm resistor >> Gnd
    A digram example: 
  
Photoresistor >> Particl Argon
   Photoresistor pin >> A5
   Photoresistor pin >> A0 + 10K ohm resistor >> Gnd
   A digram example: https://ibb.co/Y0Gzd24

 
IR receiver >> Arduino 
   the first pin from the left >> D2
   the middle pin >> Gnd
   the last pin >> 3.5V
   A digram example: https://ibb.co/8NRwD9f
