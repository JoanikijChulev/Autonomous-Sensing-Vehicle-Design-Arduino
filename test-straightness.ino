// Motor A connections
int enA = 9;  // Enable pin for Motor A
int in1 = 8;  // Input 1 for Motor A
int in2 = 7;  // Input 2 for Motor A

// Motor B connections
int enB = 3; // Enable pin for Motor B
int in3 = 4;  //+ Input 1 for Motor B
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
  analogWrite(enA, 120); // 255 is full speed
  analogWrite(enB, 120);
}

void loop() {

  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // You can add a delay here to control the duration of the movement
  delay(17000); // Spin for 16 seconds or 5m

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // You can add another delay here to control the pause between movements
  delay(5000); // Pause for 1 second
}