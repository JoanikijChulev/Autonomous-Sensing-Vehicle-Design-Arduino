#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("Arduino Bluetooth Communication");
}

void loop() {
  // Read data from Bluetooth module
  if (BTSerial.available()) {
    String receivedString = "";

    // Read the complete string until a newline character is received
    while (BTSerial.available() > 0) {
      char c = BTSerial.read();
      if (c == '\n') {
        break;
      }
      receivedString += c;
    }

    Serial.print("Received: ");
    Serial.println(receivedString);


    // Example: Echo back the received string
    BTSerial.print("You sent: ");
    BTSerial.println(receivedString);
  }

  // Read data from Serial Monitor and send it to Bluetooth module
  if (Serial.available()) {
    String sendString = Serial.readString();
    BTSerial.print(sendString);
  }
}