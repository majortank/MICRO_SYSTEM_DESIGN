# SIMULINO UNO — Arduino UNO + LCD (LM016L) — Proteus

Brief documentation for the project that demonstrates an Arduino UNO driving
a 16x2 character LCD (LM016L / HD44780-compatible). The sketch prints a static
message on the first line and a seconds counter on the second line so the
display visibly updates during simulation.

Files
- `sketch_mar17a.ino` — Arduino sketch used by the project.

Bill of Materials (BOM)
- Arduino UNO (or ATmega328P on breadboard)
- LCD 16x2 (LM016L or any HD44780-compatible)
- 10 kΩ potentiometer (contrast)
- 220 Ω resistor (optional backlight current limit)
- Jumper wires, breadboard, +5V power source

Wiring (LCD pins to Arduino pins)

- LCD RS  -> Arduino D13
- LCD EN  -> Arduino D12
- LCD D4  -> Arduino D11
- LCD D5  -> Arduino D10
- LCD D6  -> Arduino D9
- LCD D7  -> Arduino D8
- LCD VSS -> GND
- LCD VDD -> +5V
- LCD VO  -> Pot wiper (10K) between +5V and GND
- LCD A   -> +5V through 220Ω (backlight +)
- LCD K   -> GND (backlight -)

Proteus / Simulation Notes
- Use a generic 16x2 LCD component (HD44780) if LM016L is not listed.
- See `docs/PROTEUS.md` for step-by-step instructions to run the sketch in
  Proteus (loading the compiled `.hex` into the ATmega328P or using the
  Arduino UNO model).

How to use (real hardware)
1. Wire the LCD as shown above.
2. Open `sketch_mar17a.ino` in the Arduino IDE.
3. Select `Tools > Board > Arduino/Genuino UNO` and correct COM port.
4. Upload the sketch. The LCD should show "Hello, World!" and an increasing
   seconds counter on the second line.

Troubleshooting
- Blank display: check contrast pot wiring (VO). Try adjusting the pot.
- Garbage characters: confirm RW pin on LCD is tied to GND.
- Backlight off: ensure A/K pins and resistor are wired correctly.
- In Proteus, if the LCD doesn't show text, try using a different LCD
  device (HD44780) and confirm the program `.hex`/`.elf` is loaded.

License
- MIT — feel free to reuse and modify. Attribution appreciated.
