# IoT-Based Smart Vending Machine Using KiwisIoT

## Project Overview
This project demonstrates an automated vending machine using a NodeMCU ESP8266, servo motor, push button, and IR sensor. Users can select a product using the push button, and the servo motor operates the dispensing mechanism. The IR sensor detects product dispensing, while the KiwisIoT platform enables remote monitoring of vending activity.

## Hardware Components
- NodeMCU ESP8266
- SG90 Servo Motor
- IR Obstacle Detection Sensor
- Push Button
- External 5V Power Supply
- Jumper Wires

## Software Requirements
- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library
- Servo Library

## Circuit Connections

| Component | ESP8266 Pin |
|---|---|
| Push Button | D1 |
| IR Sensor Digital Output | D2 |
| Servo Signal | D5 |
| IR Sensor VCC | 3.3V (if supported) |
| IR Sensor GND | GND |
| Servo VCC | External regulated 5V |
| Servo GND | Common GND |

Connect the push button between D1 and GND. Connect the external servo power supply ground to the ESP8266 GND.

## Working Principle
When a user presses the selection button, the ESP8266 activates the servo motor to operate the dispensing mechanism. The IR sensor checks whether a product passes through the outlet.

If a product is detected, the successful dispensing count increases. The product count and vending status are then transmitted to the KiwisIoT platform.

## KiwisIoT Dashboard

| Channel | Data |
|---|---|
| Channel 0 | Successful Dispensing Count |
| Channel 1 | Vending Machine Status |

Possible status values include `DISPENSED` and `DISPENSE_FAILED`.

## Configuration
Update your Wi-Fi credentials and KiwisIoT Topic ID in the Arduino code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor vending machine activity through the KiwisIoT dashboard.

## Applications
- Automated snack vending
- Smart retail systems
- Stationery dispensing machines
- Automated product distribution
- IoT-based vending machine monitoring

## Project Blog
[Read the full project on Hackster.io](https://www.hackster.io/kirusokumar/iot-based-smart-vending-machine-using-kiwisiot-52de4b)

## Recommended Platform
[KiwisIoT – IoT Monitoring Platform](https://www.kiwisiot.in/)

**Arduino Library:** https://github.com/Kiwistron/KiwisIoT

**Example Projects:** https://github.com/Kiwistron/KiwisIoT-Projects/tree/main

---
**Author:** Kirusokumar