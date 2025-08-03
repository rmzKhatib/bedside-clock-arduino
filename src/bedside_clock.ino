#include <Wire.h>
#include <TM1637Display.h>
#include <RTClib.h>

// Pin definitions for hardware connections
#define CLK 2     // TM1637 Clock pin
#define DIO 3     // TM1637 Data pin
#define BUZZER 4  // Active Buzzer Pin
#define LED_1 5   // LED_1 pin
#define LED_2 6   // LED_2 pin

// Initialize TM1637 display
TM1637Display display(CLK, DIO);

// Initialize DS3231 RTC module
RTC_DS3231 rtc;

// Alarm configuration - set desired alarm time here
const int alarmHour = 7;    // Alarm hour in 24-hour format (0-23)
const int alarmMinute = 0;  // Alarm minute (0-59)
bool alarmTriggered = false; // Flag to prevent buzzer from repeating within the same minute

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure buzzer pin as output and ensure it starts OFF
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Configure led pins as output and ensure they start OFF
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);

  // Set display brightness to maximum (0x00 = dim, 0x0f = brightest)
  display.setBrightness(0x0f); //Max brightness

  // Initialize the RTC module
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1); // Halt program if RTC is not found
  }

  // Uncomment this line ONLY the first time to set the time
  // This will set the RTC to the compile time of this sketch
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
}

void loop() {

  // Get current date and time from RTC
  DateTime now = rtc.now();

  // Convert 24-hour format to 12-hour format for display
  int hour = now.hour();
  if (hour == 0) {
    // Midnight (0:xx) becomes 12:xx AM
    hour = 12;
  } else if (hour > 12) {
    // PM hours: subtract 12 to get 12-hour format
    hour -= 12;
  }

  // Get current minute
  int minute = now.minute();
  
  // Format time as 4-digit number (HHMM) for display
  // Example: 9:05 becomes 905, 12:30 becomes 1230
  int displayTime = hour * 100 + minute;

  // Create blinking colon effect - colon blinks every second
  bool colon = now.second() % 2 == 0;

  // Display the time with optional colon
  // 0b11100000 turns on colon, 0b00000000 turns it off
  // 'true' parameter adds leading zeros (e.g., shows "01:05" instead of "1:5")
  display.showNumberDecEx(displayTime, colon ? 0b11100000 : 0b00000000, true);

  // Alarm Logic - check if current time matches alarm time
  if(now.hour() == alarmHour && now.minute() == alarmMinute && !alarmTriggered) {
    // Turn on buzzer and led lights
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    delay(5000); // Buzz for 5 seconds
    digitalWrite(BUZZER, LOW); // Turn off buzzer
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    alarmTriggered = true; // Set flag to prevent repeating alarm in same minute
  }

  // Reset alarm trigger flag when minute changes
  // This allows the alarm to trigger again the next day
  if (now.minute() != alarmMinute) {
    alarmTriggered = false;
  }

  // Wait 1 second before next loop iteration
  // This creates a 1Hz update rate for the display
  delay(1000);

}