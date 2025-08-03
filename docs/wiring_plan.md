## Wiring Overview (Breadboard Setup)

This wiring plan shows how all components are connected on a full-sized breadboard for prototyping 

## Arduino to Breadboard
- Arduino 5V to red power rail (red wire)
- Connect Arduino GND to blue ground rail (black wire)

### RTC
- VCC --> Breadboard red power rail (red wire)
- GND --> Breadboard blue power rail (black wire)
- SDA --> Arduino A4 (yellow wire)
- SCL --> Arduino A5 (green wire)

### TM1637 Display
- VCC --> Breadboard red power rail (red wire)
- GND --> Breadboard blue power rail (black wire)
- CLK --> Arduino Pin 2 (green wire)
- DIO --> Arduino Pin 3 (yellow wire)

### Active Buzzer
    - +ve --> Arduino Pin D4 (blue wire)
    - -ve --> blue power rail (black wire)

### LED Lights (for each led light)
    - Anode(+) --> Arduino pin (D5, D6, etc.)
    - Cathode(-) --> One side of resistor
    - Other side of Resistor (220ohms) --> GND (blue rail)