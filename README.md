# Make a Digital Timer!
 
## Overview
For this assignment, you are going to 

A) [Solder your LCD panel](#part-a-solder-your-lcd-panel)

B) [Write text to an LCD Panel](#part-b-writing-to-the-lcd) 

c) [Using a time-based digital sensor!](#part-c-using-a-time-based-digital-sensor)

D) [Make your Arduino sing!](#part-d-make-your-arduino-sing)

E) [Make your own timer](#part-e-make-your-own-timer) 
 
## In The Report
Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

## Part B. Writing to the LCD
 
**a. What voltage level do you need to power your display?**
The 5.5 Volt pin power the display. Thats because the 5.5V pin is connected to pins VSS to R on the board. 

**b. What voltage level do you need to power the display backlight?**
The backlight is powered by 3.3 V. If we use +5V we may burn the background light.

**c. What was one mistake you made when wiring up the display? How did you fix it?**
I did not supply the 3.3V source to any power line. So my display was working but not my backlight. Once I connected the 3.3V source to the other power line, I was able to get the backlight. 

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**
We have to change the line lcd.print("hello, world!");
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**
[link to video](https://www.youtube.com/watch?v=65VcKsw9V5s)

## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
In the code they define the int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};. We would need to double the values in this array
to double the speed. The noe duration is 1 divided by these numbers so increasing the values reduces the duration.
**b. What song is playing?**
It plays the star wars theme song!! The jedi will return!!! And destroy the sith lord!! 

## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
