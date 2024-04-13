// Motor A connections
int enA = 9;  // Enable pin for Motor A
int in1 = 8;  // Input 1 for Motor A
int in2 = 7;  // Input 2 for Motor A

// Motor B connections
int enB = 3; // Enable pin for Motor B
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
  analogWrite(enA, 150); // 255 is full speed, we went with 150 for the testing
  analogWrite(enB, 150); // 255 is full speed, we went with 150 for the testing
}

void loop() {

  //TEST1-FORWARD 5M

  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Added a delay here to control the duration of the movement
  delay(16000); // Spin for 16 seconds or 5m of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(8000); // Pause for 8 seconds


   //TEST2-REVERSE 5M

    // Spin both motors in reverse
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Added a delay here to control the duration of the movement
  delay(16000); // Spin for 16 seconds or 5m of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(8000); // Pause for 8 seconds


 //TEST3-INTERVALED FORWARD 0.5M

 for (int i = 0; i < 10; i++) { // Loop 10 times
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Added a delay here to control the duration of the movement
  delay(1600); // Spin for 1.6 seconds or 0.5m of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(1600); // Pause for 1.6 seconds
 }

   // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(8000); // Pause for 8 seconds


 //TEST4-INTERVALED REVERSE 0.5M

 for (int i = 0; i < 10; i++) { // Loop 10 times
      // Spin both motors in reverse
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Added a delay here to control the duration of the movement
  delay(1600); // Spin for 1.6 seconds or 0.5m of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(1600); // Pause for 1.6 seconds
 }

   // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(8000); // Pause for 8 seconds


 //TEST5-FORWARD REVERSE CYCLE  1M

 for (int i = 0; i < 10; i++) {

  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  // Added a delay here to control the duration of the movement
  delay(3200); // Spin for 3.2 seconds or 1m  of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(1600); // Pause for 1.6 second

      // Spin both motors in reverse
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Added a delay here to control the duration of the movement
  delay(3200); // Spin for 3.2 seconds or 1m of distance

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added another delay here to control the pause between movements
  delay(1600); // Pause for 1.6 seconds
}

  // Stop both motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  // Added the final delay here to reset
  delay(60000); // Pause for 1 minute to restart the whole experiment

}