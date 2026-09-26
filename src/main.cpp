#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

// HiLetGo NodeMCU-32S / ESP-WROOM-32 to HUB75E input connector.
// These are GPIO numbers printed on the board's pinout, not header positions.
constexpr int R1_PIN = 25;
constexpr int G1_PIN = 26;
constexpr int B1_PIN = 27;
constexpr int R2_PIN = 14;
constexpr int G2_PIN = 12;
constexpr int B2_PIN = 13;
constexpr int A_PIN = 23;
constexpr int B_PIN = 19;
constexpr int C_PIN = 5;
constexpr int D_PIN = 17;
constexpr int E_PIN = 32;  // Required by this 64x64, 1/32-scan panel.
constexpr int LAT_PIN = 4;
constexpr int OE_PIN = 15;
constexpr int CLK_PIN = 16;

HUB75_I2S_CFG::i2s_pins pins = {
    R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN,
    A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};

HUB75_I2S_CFG matrixConfig(
    64,  // panel width
    64,  // panel height
    1,   // one panel
    pins);

MatrixPanel_I2S_DMA *matrix = nullptr;

void showColor(uint8_t red, uint8_t green, uint8_t blue, const char *name) {
  matrix->fillScreen(matrix->color565(red, green, blue));
  matrix->setTextWrap(false);
  matrix->setCursor(2, 28);
  matrix->setTextColor(matrix->color565(255, 255, 255));
  matrix->print(name);
  delay(1500);
}

void setup() {
  Serial.begin(115200);

  // Conservative settings make the first power-on test kinder to a USB source.
  matrixConfig.setPixelColorDepthBits(4);
  matrixConfig.clkphase = false;
  matrix = new MatrixPanel_I2S_DMA(matrixConfig);
  matrix->begin();
  matrix->setBrightness8(20);  // 0-255; start dim until the power supply is proven.
  matrix->clearScreen();
}

void loop() {
  showColor(96, 0, 0, "RED");
  showColor(0, 96, 0, "GREEN");
  showColor(0, 0, 96, "BLUE");
  matrix->clearScreen();
  delay(500);
}
