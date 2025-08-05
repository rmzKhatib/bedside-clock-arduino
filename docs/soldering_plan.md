# Arduino Bedside Alarm Clock - Soldering Plan

## Project Overview
This document outlines the complete soldering layout for converting the breadboard prototype into a permanent perfboard circuit.

## Components List
- Arduino Uno R3 (remains removable, connected via jumper wires)
- DS3231 RTC module (mounted on pin headers)
- TM1637 4-digit display (mounted on pin headers)
- Active buzzer (direct soldered)
- LED lights with 220Ω current limiting resistors (direct soldered)
- Perfboard (standard 2.54mm pitch)
- Solid core wire (22 AWG, various colors)
- Male pin headers for removable modules

## Complete Wiring Schematic

### Power Distribution
Arduino 5V  → Perfboard power rail (RED wire)
Arduino GND → Perfboard ground rail (BLACK wire)

### DS3231 Real Time Clock Module
VCC → Power rail (RED wire)
GND → Ground rail (BLACK wire)
SDA → Arduino A4 (YELLOW wire)
SCL → Arduino A5 (GREEN wire)

### TM1637 4-Digit Display Module
VCC → Power rail (RED wire)
GND → Ground rail (BLACK wire)
CLK → Arduino D2 (GREEN wire)
DIO → Arduino D3 (YELLOW wire)

### Active Buzzer
Positive (+) → Arduino D4 (BLUE wire)
Negative (-) → Ground rail (BLACK wire)

### LED Lighting Circuit
For each LED (pins D5, D6, D7, etc.):
LED Anode (+) → Arduino Digital Pin (D5, D6, D7...)
LED Cathode (-) → 220Ω Resistor → Ground rail

## Physical Layout Strategy

### Perfboard Layout (Top-Down View)
┌─────────────────────────────────────┐
│  [RTC Module]      [TM1637 Display] │  ← Top Section
│     (Headers)         (Headers)     │
├─────────────────────────────────────┤
│  ═══ POWER RAIL (5V) ═══════════    │  ← Middle Section
│  ═══ GROUND RAIL (GND) ════════════ │    (Main wiring area)
├─────────────────────────────────────┤
│ [LED1]       [LED2]     [BUZZER]    │  ← Bottom Section
│  [R1]         [R2]                  │    (R = 220Ω resistors)
└─────────────────────────────────────┘

## Soldering Sequence

1. **Install pin headers** for RTC and TM1637 modules
2. **Create power and ground rails** using solid core wire
3. **Solder 220Ω resistors** in designated positions
4. **Solder LEDs** with correct polarity (long leg = anode/positive)
5. **Solder active buzzer** with correct polarity marking
6. **Run all connection wires** following color coding scheme
7. **Test all connections** with multimeter before powering up

## Pre-Power Testing Checklist

- [ ] All solder joints are clean and solid
- [ ] Power rail has continuity along entire length
- [ ] Ground rail has continuity along entire length
- [ ] No short circuits between power and ground rails
- [ ] LED polarity verified (use multimeter diode test mode)
- [ ] Buzzer polarity verified against markings
- [ ] All pin connections match the wiring diagram
- [ ] Module headers are properly aligned and seated

## Assembly Notes

- Keep LED leads long enough for desired final positioning
- Place current limiting resistors as close to LEDs as possible
- Use heat shrink tubing on any exposed wire splices
- Consider adding a 100µF electrolytic capacitor across power rails for stability
- Label connection points if the board will be enclosed in a case
- Take photos during assembly for future reference/troubleshooting