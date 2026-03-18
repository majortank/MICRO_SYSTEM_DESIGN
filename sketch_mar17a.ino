#include <LiquidCrystal.h>

// Initialize the library with the interface pins
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);      // Set up the LCD's number of columns and rows
  lcd.print("Hello, World!");  // Print message to the LCD
}

void loop() {
  // Nothing needed here for static text
  lcd.setCursor(0,1);
}