#include <Wire.h>
#include <TM1637Display.h>
#include <RTClib.h>

// Pins
#define CLK 2     // TM1637 Clock
#define DIO 3     // TM1637 Data
#define BUZZER 4  // Active Buzzer Pin

TM1637Display display(CLK, DIO);

// RTC
RTC_DS3231 rtc;

// Alarm Time
const int alarmHour = 7;
const int alarmMinute = 0;
bool alarmTriggered = false; // To avoid buzzing multiple times in one minute

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  display.setBrightness(0x0f); //Max brightness

  // Start RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // Uncomment this line ONLY the first time to set the time
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
}

void loop() {

  DateTime now = rtc.now();

  int hour = now.hour();
  if (hour == 0) {

    hour = 12;

  } else if (hour > 12) {

    hour -= 12;

  }

  int minute = now.minute();
  int displayTime = hour * 100 + minute;

  bool colon = now.second() % 2 == 0;

  display.showNumberDecEx(displayTime, colon ? 0b11100000 : 0b00000000, true);

  // Alarm Logic
  if(now.hour() == alarmHour && now.minute() == alarmMinute && !alarmTriggered) {

    digitalWrite(BUZZER, HIGH);
    delay(5000); // buzz for 5 seconds
    digitalWrite(BUZZER, LOW);
    alarmTriggered = true; // Prevent repeating alarm in same minute

  }

  if (now.minute() != alarmMinute) {

    alarmTriggered = false;

  }

  delay(1000);

}