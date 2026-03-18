/*
  SIMULINO UNO - Arduino UNO project (Proteus simulation-friendly)
  LCD: LM016L (16x2) - compatible with HD44780 instruction set

  File: sketch_mar17a.ino
  Purpose: Simple demo that prints a static message on line 1 and
           updates a seconds counter on line 2 so the simulation
           shows activity.

  Wiring (LCD -> Arduino UNO):
    LCD RS  -> Arduino D13
    LCD EN  -> Arduino D12
    LCD D4  -> Arduino D11
    LCD D5  -> Arduino D10
    LCD D6  -> Arduino D9
    LCD D7  -> Arduino D8
    LCD VSS -> GND
    LCD VDD -> +5V
    LCD VO  -> Pot wiper (10K) between +5V and GND (contrast)
    LCD A   -> +5V through 220R (backlight +, if present)
    LCD K   -> GND (backlight -)

  Notes:
  - LM016L is typically HD44780-compatible. In Proteus use a generic
    16x2 LCD (HD44780 driver) if LM016L is not available.
  - This sketch is safe for both simulation and real hardware.
  - To run on real hardware: use Arduino UNO board in Arduino IDE.

*/

#include <LiquidCrystal.h>

// Initialize the library with the interface pins (RS, EN, D4, D5, D6, D7)
const int rs = 13;
const int en = 12;
const int d4 = 11;
const int d5 = 10;
const int d6 = 9;
const int d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Line 1: static welcome message
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  // Line 2: initial counter label
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  // Update a simple seconds counter on the second line so the
  // display visibly changes during simulation.
  static unsigned long lastMillis = 0;
  static int counter = 0;

  if (millis() - lastMillis >= 1000) {
    lastMillis = millis();
    counter++;

    // Move cursor to where the number should appear and print it.
    lcd.setCursor(7, 1); // position right after "Count: "
    // clear previous number area (covers up to 4 digits)
    lcd.print("    ");
    lcd.setCursor(7, 1);
    lcd.print(counter);
  }
}