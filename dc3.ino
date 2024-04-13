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

byte maxDist = 160;                               //Maximum sensing distance (Objects further than this distance are ignored)
byte stopDist = 47;                               //Minimum distance from an object to stop in cm
float timeOut = 2*(maxDist+10)/100/340*1000000;  

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




void moveForwardCentimeters(int centimeters) {
  // Check if a valid distance was provided
  if (centimeters <= 0) {
    Serial.println("Invalid distance. Distance must be greater than zero.");
    return;
  }

  // Calculate delay time based on the assumption that the car moves 1 meter in 3.5 seconds
  long delayTime = centimeters * 35;

  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  delay(delayTime); // Move for the specified delay time

  // Stop the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}



void moveBackwardCentimeters(int centimeters) {
  // Check if a valid distance was provided
  if (centimeters <= 0) {
    Serial.println("Invalid distance. Distance must be greater than zero.");
    return;
  }

  // Calculate delay time based on the assumption that the car moves 1 meter in 3.5 seconds
  long delayTime = centimeters * 35;

  // Spin both motors backward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  delay(delayTime); // Move for the specified delay time
  // Stop the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void moveForward() {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);


}

void stopMove()   {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void stopMotors(int delayTime) {
  // Spin both motors forward
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(delayTime); // Use the delayTime provided as an argument
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
    delayTime = 1050;
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
    delayTime = 1050;
  }

  // Check if a valid angle was provided
  if (delayTime == 0) {
    Serial.println("Invalid angle. Available options: 30, 45, 60, 90 degrees");
    return;
  }

  delay(delayTime);
}

int getDistance()                                   //Measure the distance to an object
{
  unsigned long pulseTime;                          //Create a variable to store the pulse travel time
  int distance;                                     //Create a variable to store the calculated distance
  digitalWrite(trig, HIGH);                         //Generate a 10 microsecond pulse
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pulseTime = pulseIn(echo, HIGH, timeOut);         //Measure the time for the pulse to return
  distance = (float)pulseTime * 340 / 2 / 10000;    //Calculate the object distance based on the pulse time
  return distance;
}

int checkDirection()                                            //Check the left and right directions and decide which way to turn
{
  int distances [2] = {0,0};                                    //Left and right distances
  int turnDir = 1;                                              //Direction to turn, 0 left, 1 reverse, 2 right
  myservo.write(180);                                      //Turn servo to look left
  delay(500);
  distances [0] = getDistance();                                //Get the left object distance
 myservo.write(0);                                           //Turn servo to look right
  delay(1000);
  distances [1] = getDistance();                                //Get the right object distance
  if (distances[0]>=200 && distances[1]>=200)                   //If both directions are clear, turn left
    turnDir = 0;
  else if (distances[0]<=stopDist && distances[1]<=stopDist)    //If both directions are blocked, turn around
    turnDir = 1;
  else if (distances[0]>=distances[1])                          //If left has more space, turn left
    turnDir = 0;
  else if (distances[0]<distances[1])                           //If right has more space, turn right
    turnDir = 2;
  return turnDir;
}

void loop() {
  
      myservo.write(90);  // Rotate the servo to the current angle


 
int distance = getDistance();                   //Check that there are no objects ahead
  if(distance >= stopDist)                        //If there are no objects within the stopping distance, move forward
  {
    moveForward();
  }
  while(distance >= stopDist)                     //Keep checking the object distance until it is within the minimum stopping distance
  {
    distance = getDistance();
    delay(250);
  }
  stopMove();



 int turnDir = checkDirection();                 //Check the left and right object distances and get the turning instruction
  Serial.print(turnDir);
  switch (turnDir)                                //Turn left, turn around or turn right depending on the instruction
  {
    case 0:                                       //Turn left
      turnLeftDegrees (90);
      break;
    case 1:                                       //Turn around
      turnLeftDegrees (45);
      break;
    case 2:                                       //Turn right
      turnRightDegrees (90);
      break;
  }
}
