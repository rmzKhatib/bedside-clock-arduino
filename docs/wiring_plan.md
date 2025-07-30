## Wiring Overview (Breadboard Setup)

This wiring plan shows how all components are connected on a full-sized breadboard for prototyping 

## Arduino to Breadboard
    - Arduino 5V to red power rail
    - Connect Arduino GND to blue ground rail

### RTC
    - SDA --> A4 on Arduino
    - SCL --> A5 on Arduino
    - VCC --> 5V rail
    - GND --> GND rail

### TM1637 Display
    - VCC --> 5V rail
    - GND --> GND rail
    - DIO --> D2 on Arduino
    - CLK --> D3 on Arduino

### Active Buzzer
    - + --> Arduino Pin D4
    - - --> GND rail

**Add references to screenshots later**