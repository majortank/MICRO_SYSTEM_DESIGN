# Hardware Reference — SIMULINO UNO

Quick reference for wiring and parts.

Pin mapping (LCD -> Arduino UNO)

- `RS`  -> `D13`
- `EN`  -> `D12`
- `D4`  -> `D11`
- `D5`  -> `D10`
- `D6`  -> `D9`
- `D7`  -> `D8`
- `VSS` -> `GND`
- `VDD` -> `+5V`
- `V0`  -> Pot wiper (10K) between +5V and GND
- `A`   -> +5V through 220Ω (optional, backlight +)
- `K`   -> GND (backlight -)

BOM (suggested parts)
- Arduino UNO R3 (or equivalent)
- 16x2 character LCD (LM016L / HD44780)
- 10 kΩ potentiometer (for contrast)
- 220 Ω resistor (for backlight LED)
- Wires, breadboard, power supply

Assembly notes
- Always power the LCD with +5V and GND before connecting signal lines.
- Set the potentiometer midpoint initially, then adjust while running the
  sketch to get readable characters.
- Tie RW to GND for write-only operation (common setup).

Safety
- Double-check power rails before inserting the LCD to avoid damage.
