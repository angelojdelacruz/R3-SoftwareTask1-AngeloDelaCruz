# R3-SoftwareTask1-FirstLast

Tinkercad project link: https://www.tinkercad.com/things/i6u4J03wBM8

How it works: 
The Arduino Uno first reads the output or position and stores it as a float, valued from 0 to 1023. That float is then converted into a percentage value by dividing it by 1023, the maximum value the potentiometer can output. 
This percentage value is stored as another float, valued somewhere between 0% or 100%. If the value is detected to be 100%, it is rounded down to 99%, as that is the maximum integer that can be displayed on two 7-segment displays. The percentage is then rounded to a whole two digit number, which is then seperated into a ones digit and tens digit. 
A loop is then run for both digits, manually converting each into a series of HIGH and LOW outputs for the output pins, effectively converting the single digit base-10 number into a 4 digit binary number. (For example, a 6 would be converted into LOW, HIGH, HIGH, LOW, or 0110 which is the binary equivalent to 6.) 
The binary output for both of these digits are then sent to two 7-segment decoders, which convert the series of HIGH and LOW outputs back into a number in base-10 for their respective 7-segment display, the ones digit being shown on right display and the tens digit being shown on the left display. 
Turning the potentiometer will automatically adjust the 2-digit number being shown on the displays.

While this design does account for every number possible from 0-99, Tinkercad does not allow for turning the potentiometer to an exact position, making it automatically snap to preset positions. This makes it so that it isn't possible to display every number from 0-99. However, if it were possible to set specific outputs from the potentiometer, the project should accept those values and display them correctly.