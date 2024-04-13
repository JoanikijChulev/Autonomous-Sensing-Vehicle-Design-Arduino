#include <Servo.h>

Servo myservo;  // Create a servo object

#define trig 12  // Define the trigger pin
#define echo 13  // Define the echo pin

// Motor A connections
int enA = 9;  // Enable pin for Motor A
int in1 = 8;  // Input 1 for Motor A
int in2 = 7;  // Input 2 for Motor A

// Motor B connections
int enB = 3;  // Enable pin for Motor B
int in3 = 4;  // Input 1 for Motor B
int in4 = 5;  // Input 2 for Motor B

byte maxDist = 160;                               // Maximum sensing distance (Objects further than this distance are ignored)
byte stopDist = 47;                               // Minimum distance from an object to stop in cm
float timeOut = 2 * (maxDist + 10) / 100 / 340 * 1000000;

unsigned long lastCheckTime = 0;  // Variable to store the time of the last direction check

void setup() {
  // Set the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Set the motor enable pins to control the speed
  analogWrite(enA, 220); // Adjust the speed as needed
  analogWrite(enB, 220); // Adjust the speed as needed

  Serial.begin(9600);  // Initialize serial communication

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  myservo.attach(11);  // Attaches the servo on pin 11

  // Wait for the sensor, servo, and motors to settle
  delay(1000);
}

void moveForward() {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMove() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void turnRightDegrees(int degrees) {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(3000);

  // Start turning right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Calculate the delay based on the specified degrees
  long delayTime = 0;
  if (degrees == 30) {
    delayTime = 330;
  } else if (degrees == 45) {
    delayTime = 490;
  } else if (degrees == 60) {
    delayTime = 650;
  } else if (degrees == 90) {
    delayTime = 1300;
  }

  // Check if a valid angle was provided
  if (delayTime == 0) {
    Serial.println("Invalid angle. Available options: 30, 45, 60, 90 degrees");
    return;
  }

  delay(delayTime);
}

void turnLeftDegrees(int degrees) {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(3000);

  // Start turning left
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Calculate the delay based on the specified degrees
  long delayTime = 0;
  if (degrees == 30) {
    delayTime = 340;
  } else if (degrees == 45) {
    delayTime = 490;
  } else if (degrees == 60) {
    delayTime = 650;
  } else if (degrees == 90) {
    delayTime = 1300;
  }

  // Check if a valid angle was provided
  if (delayTime == 0) {
    Serial.println("Invalid angle. Available options: 30, 45, 60, 90 degrees");
    return;
  }

  delay(delayTime);
}

int getDistance() {
  // Measure the distance to an object
  unsigned long pulseTime;
  int distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulseTime = pulseIn(echo, HIGH, timeOut);
  distance = (float)pulseTime * 340 / 2 / 10000;
  return distance;
}

int checkDirection() {
  int distances[2] = {0, 0};
  int turnDir = 1;
  myservo.write(180);
  delay(500);
  distances[0] = getDistance();
  myservo.write(0);
  delay(1000);
  distances[1] = getDistance();
  if (distances[0] >= 200 && distances[1] >= 200)
    turnDir = 0;
  else if (distances[0] <= stopDist && distances[1] <= stopDist)
    turnDir = 1;
  else if (distances[0] >= distances[1])
    turnDir = 0;
  else if (distances[0] < distances[1])
    turnDir = 2;
  return turnDir;
}

void loop() {
  myservo.write(90);  // Rotate the servo to the current angle

  int distance = getDistance();
  if (distance >= stopDist) {
    moveForward();
  }
  while (distance >= stopDist) {
    distance = getDistance();
    delay(250);
  }
  stopMove();

  // Check if enough time has passed since the last direction check
  if (millis() - lastCheckTime >= 3000) {
    int turnDir = checkDirection();
    Serial.print(turnDir);
    switch (turnDir) {
      case 0:
        turnLeftDegrees(90);
        break;
      case 1:
        turnLeftDegrees(45);
        break;
      case 2:
        turnRightDegrees(90);
        break;
    }
    // Update the last direction check time
    lastCheckTime = millis();
  }
}



