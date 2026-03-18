# SIMULINO UNO — Arduino UNO + LCD (LM016L)

![SIMULINO UNO Diagram](assets/Graphic.SVG)

Overview

This repository demonstrates an Arduino UNO driving a 16x2 character LCD
(LM016L / HD44780-compatible). The included sketch prints a static message on
the first line and a seconds counter on the second line so the display updates
during simulation or on real hardware.

Files

- `sketch_mar17a.ino` — Arduino sketch (use in Arduino IDE or export HEX for
  Proteus).
- `assets/Graphic.SVG` — placeholder diagram; replace with your diagram later.

Bill of Materials (BOM)

- Arduino UNO R3 (or ATmega328P-based board)
- LCD 16x2 (LM016L or any HD44780-compatible)
- 10 kΩ potentiometer (contrast)
- 220 Ω resistor (optional, backlight current limit)
- Jumper wires, breadboard, +5V power supply

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

Hardware placeholders

The repository intentionally keeps component placeholders so you can swap
parts or footprints later. Replace or augment these placeholders with your
actual images/diagrams when ready.

- LCD module: LM016L (label as "LCD 16x2 — placeholder")
- Potentiometer: 10 kΩ (label as "Contrast Pot — placeholder")
- Backlight resistor: 220 Ω (label as "R_led — placeholder")
- Connector headers and jumpers: generic placeholders

Proteus (simulation)

Use Proteus to simulate either the full `Arduino UNO` model or a discrete
`ATmega328P` with the compiled firmware loaded.

Quick Proteus steps (UNO model)
1. Place `Arduino UNO` and `LCD 16x2 (HD44780)` components.
2. Wire RS, EN, D4..D7 to pins `13,12,11,10,9,8` respectively.
3. Wire power, GND, VO to a 10k pot, and backlight A/K accordingly.
4. In the UNO component properties, load the compiled `.hex` produced by the
   Arduino IDE (`Sketch > Export compiled Binary`).
5. Run simulation.

Using ATmega328P directly
1. Place `ATmega328P` and necessary clock circuitry/power rails.
2. Wire I/O pins to the LCD matching the sketch pinout.
3. Load the `.hex` in the ATmega's Program File property.
4. Run simulation.

Arduino IDE — usage and export

1. Open `sketch_mar17a.ino` in Arduino IDE.
2. Select `Tools > Board > Arduino/Genuino UNO`.
3. Select the correct `Port` when uploading to real hardware.
4. To obtain the firmware for Proteus, use `Sketch > Export compiled Binary`.
   The IDE will save a `.hex` in the sketch folder; use that in Proteus.

Optional project helpers

- If you'd like, I can add a `.vscode/` folder with a basic `arduino.json`
  configuration for building with the VS Code Arduino extension.
- I can also export the compiled `.hex` here and place it in the repo if you
  want a ready-to-load firmware file.

Images

- You said you'll add images later — keep using `assets/Graphic.SVG` as the
  filename so the README continues to render the diagram automatically when
  you replace it.

Troubleshooting

- Blank LCD: adjust VO (contrast pot) and ensure RW is tied to GND.
- Garbled text: check wiring and ensure 4-bit mode pins match the sketch.

License

- MIT — feel free to reuse and modify. Attribution appreciated.
