# ESP32 + RGB Matrix P3.0 64x64

Starter PlatformIO project for a HiLetGo NodeMCU-32S / ESP-WROOM-32 and the Seengreat P3.0 64x64 RGB matrix.

## Wire the HUB75 **input** connector

| Panel signal | ESP32 GPIO |
|---|---:|
| R1 | 25 |
| G1 | 26 |
| B1 | 27 |
| R2 | 14 |
| G2 | 12 |
| B2 | 13 |
| A | 23 |
| B | 19 |
| C | 5 |
| D | 17 |
| E | 32 |
| CLK | 16 |
| LAT | 4 |
| OE | 15 |
| GND | GND |

`E` is required because this panel is 64x64 and uses 1/32 scan. Connect one of the HUB75 GND pins to ESP32 GND.

## Power

The panel vendor specifies **5V/4A**. Connect that supply directly to the matrix power harness. Do not run matrix power through the ESP32, breadboard, or thin signal wires. The ESP32 may be powered from USB while testing; its ground must still connect to the matrix ground.

Use a short ribbon cable in the matrix's connector labeled **INPUT**, not OUTPUT. The ESP32's 3.3V signals may work directly with some panels; add a 74AHCT245/HUB75 level-shifter board if the display is unstable or shows wrong colors.

## Build and upload

1. Install [PlatformIO](https://platformio.org/install/ide?install=vscode) in VS Code.
2. Open this folder in VS Code.
3. Connect the ESP32 by USB.
4. Run **PlatformIO: Upload**.

The initial program cycles dim red, green, and blue screens. Keep the brightness at 20 until your 5V supply has been verified.

## Source

The panel specs are from [Seengreat's repository](https://github.com/seengreat/RGB-Matrix-P3.0-64x64): HUB75, 64x64, 1/32 scan, 5V/4A.
