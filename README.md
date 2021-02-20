# KitchenTimer
minimum kitchen timer with Arduino, Graphic LCD
<p></p>
Four preset timer and additional 1 minuteis presented.<br />
The sketch is written with Arduino IDE 1.8.13, run on ATmega328P with internal 8MHz clock, display to AQM1248A small graphic LCD.  I feel the output of piezoelectric sounder is too small, then I use a transformer recycled from security buzzer.
<p></p>
This repository include these file (& folder):<br />
<ol type="1">
  <li>KitchenTimer/KitchenTimer.ino : main sketch</li>
  <li>kt_EEPROMw/kt_EEPROMw.ino : write font data to EEPROM</li>
  <li>kt_rle.py : runlength encoder of font data</li>
  <li>KitchenTimer_sch.png : circuit schematics</li>
  <li>boards_int8MHz.txt : bootloader settings of ATmega328P with Arduino IDE</li>
</ol>
<p></p>
I plan to write a blog on this subject.　Wait for moment, please.
<p></p>
