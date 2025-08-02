#include <Wire.h>
#include <TM1637Display.h>
#include <RTClib.h>

// TM1637 display pins
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

// RTC
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  // Start RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Uncomment this line ONLY the first time to set the time
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // Start Display
  display.setBrightness(0x0f); // Max brightness
  
}

void loop() {

  DateTime now = rtc.now();

  int hour = now.hour();
  int minute = now.minute();

  // Display time in HH:MM
  int displayTime = hour * 100 + minute;
  display.showNumberDecEx(displayTime, 0b11100000, true); // 0b11100000 enables colon

  delay(1000);

}