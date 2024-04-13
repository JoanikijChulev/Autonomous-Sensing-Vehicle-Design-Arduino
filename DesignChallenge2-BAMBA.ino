// Motor A connections
int enA = 9;  // Enable pin for Motor A
int in1 = 8;  // Input 1 for Motor A
int in2 = 7;  // Input 2 for Motor A

// Motor B connections
int enB = 3;  // Enable pin for Motor B
int in3 = 4;  // Input 1 for Motor B
int in4 = 5;  // Input 2 for Motor B

void setup() {
  // Set the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Initialize both motors to stop (zero speed)
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Set the motor enable pins to control the speed
  analogWrite(enA, 220); // Adjust the speed as needed
  analogWrite(enB, 220); // Adjust the speed as needed
}

void moveForward5m() {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(17000);
}

void moveForward3m() {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(10000);
}

void moveForward1m() {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(3500);
}

void moveBackward5m() {
  // Spin both motors backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(17000);
}
void moveBackward3m() {
  // Spin both motors backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(10000);
}
void moveBackward1m() {
  // Spin both motors backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(3500);
}


void turnRight30degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(2000);
// Start turning right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(330);

}

void turnRight45degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(2000);
// Start turning right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(490);

}
void turnRight60degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(2000);
// Start turning right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(650);

}
void turnRight90degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(2000);
// Start turning right
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(940);

}
void turnLeft30degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(2000);

  // Start turning left
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   delay(340);
}

void turnLeft45degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(2000);

  // Start turning left 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   delay(490);
}

void turnLeft60degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(2000);

  // Start turning left
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   delay(650);
}
void turnLeft90degrees() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Adjust this delay based on your estimated turn time
  delay(2000);

  // Start turning left
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   delay(900);
}

void stopMotors() {
  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

  //Experiment 1
  moveForward1m();
  turnLeft90degrees();
  stopMotors(); delay(2000);
  moveForward1m();
  stopMotors(); delay(5000);


  //Experiment 2
  moveForward1m();
  turnRight90degrees();
  stopMotors(); delay(2000);
  moveForward1m();
  stopMotors(); delay(5000);

  //Experiment 3
 for (int i = 0; i < 4; i++) {
  moveForward1m();
  turnLeft90degrees();
  stopMotors();
  delay(1000);
 }
  stopMotors(); delay(5000);


  //Experiment 4
 for (int i = 0; i < 4; i++) {
  moveForward1m();
  turnRight90degrees();
  stopMotors();
  delay(1000);
 }
  stopMotors(); delay(5000);

  //Experiment 5
  turnLeft30degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnLeft45degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnLeft60degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnLeft90degrees();
    moveForward1m();
  stopMotors();   delay(5000);

  //Experiment 6
  turnRight30degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnRight45degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnRight60degrees();
    moveForward1m();
  stopMotors();   delay(5000);
  turnRight90degrees();
    moveForward1m();
  stopMotors();   delay(5000);

}