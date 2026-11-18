#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Servo.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Pin Configuration
#define BUTTON_PIN D1
#define SERVO_PIN D5
#define IR_PIN D2

// Servo positions
#define SERVO_HOME 0
#define SERVO_DISPENSE 90

// Sensor and motor
Servo vendingServo;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

// Variables
unsigned long previousMillis = 0;

int productCount = 0;

bool lastButtonState = HIGH;

void setup() {

  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(IR_PIN, INPUT);

  vendingServo.attach(SERVO_PIN);
  vendingServo.write(SERVO_HOME);

  kiwisiot.begin();

  Serial.println("Smart Vending Machine Started");
}

void loop() {

  kiwisiot.run();

  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect button press
  if (lastButtonState == HIGH &&
      buttonState == LOW) {

    Serial.println("\nProduct Selected");

    // Start dispensing mechanism
    vendingServo.write(SERVO_DISPENSE);
    delay(700);

    vendingServo.write(SERVO_HOME);
    delay(500);

    // Check product detection
    int irReading = digitalRead(IR_PIN);

    String machineStatus;

    // Assumes LOW means product detected
    if (irReading == LOW) {

      productCount++;

      machineStatus = "DISPENSED";

      Serial.println("Product Dispensed Successfully");

    } else {

      machineStatus = "DISPENSE_FAILED";

      Serial.println("Product Not Detected");

    }

    Serial.print("Product Count: ");
    Serial.println(productCount);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(productCount));
    kiwisiot.send("1", machineStatus);
  }

  lastButtonState = buttonState;

  // Maintain cloud communication
  kiwisiot.run();
}
