#include <Servo.h>

Servo myservo;  // Create a servo object

#define trigPin 12  // Define the trigger pin
#define echoPin 13  // Define the echo pin

void setup() {
  Serial.begin(9600);  // Initialize serial communication

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myservo.attach(11);  // Attaches the servo on pin 11

  // Wait for the sensor and servo to settle
  delay(1000);
}

void loop() {
  for (int angle = 30; angle <= 180; angle += 75) {
    myservo.write(angle);  // Rotate the servo to the current angle
    delay(4000);  // Wait for the servo to reach the angle

    long duration, distance;

    // Send a pulse to the sensor to trigger a measurement
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the duration of the echo signal
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance (in cm) based on the speed of sound
    distance = (duration / 2) / 29.1;  // Divide by 29.1 to convert microseconds to centimeters

    // Print the distance to the serial monitor
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees, Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}
