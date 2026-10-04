#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LDR_PIN 34

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("LDR");
  display.display();

  delay(1000);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);

  Serial.print("LDR Reading: ");
  Serial.println(ldrValue);

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("LDR");

  display.setTextSize(2);
  display.setCursor(0, 30);
  display.print(ldrValue);

  display.display();

  delay(500);
}
