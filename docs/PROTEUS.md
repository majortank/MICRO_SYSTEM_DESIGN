# Proteus Simulation Guide — SIMULINO UNO

This guide explains how to simulate the `sketch_mar17a.ino` Arduino sketch
with Proteus (ISIS). Two common methods are described: using the Arduino UNO
model or using a discrete ATmega328P and loading the compiled firmware.

Method A — Use the Arduino UNO model (simpler)
1. Open Proteus and create a new project.
2. Place the `Arduino UNO` component (search for "Arduino UNO" in components).
3. Place a `LCD 16x2` (HD44780) component and a 10k potentiometer for contrast.
4. Wire LCD pins RS, EN, D4..D7 to UNO digital pins `13,12,11,10,9,8` respectively.
5. Wire VSS/GND and VDD/+5V. Wire VO to pot wiper, pot ends to +5V and GND.
6. Connect LCD backlight A to +5V (through 220Ω) and K to GND if present.
7. Select the UNO component and in the "Program File" property load the
   compiled HEX from the Arduino IDE (see below how to produce it).
8. Run the simulation — the LCD will show the welcome message and counter.

Method B — Use ATmega328P (load HEX directly)
1. Place `ATmega328P` (with crystal oscillator if needed) and power it with
   a +5V source and GND.
2. Make sure the ATmega has the Arduino bootloader fuses/settings for UNO if
   you rely on bootloader behavior; otherwise load the compiled HEX directly.
3. Connect the LCD to the ATmega pins matching the sketch (D13..D8).
4. Load your compiled HEX into the ATmega's program file property.
5. Run the simulation.

How to obtain the compiled HEX from Arduino IDE
1. Open `sketch_mar17a.ino` in Arduino IDE.
2. Select `Tools > Board > Arduino/Genuino UNO`.
3. Use `Sketch > Export compiled Binary`.
4. Note the location of the generated `.hex` (shown in the IDE console) and
   load that file into Proteus as the Program File.

Tips
- If Proteus' LCD shows nothing, toggle the contrast pot in the simulation.
- Use the Arduino UNO model when possible; it handles bootloader and pins
  more conveniently.
- If the LCD displays weird characters, ensure RW is tied to GND.
