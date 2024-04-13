// Define the pin to which the sensor is connected
int irSensorPin = 12;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the value from the IR sensor
  int sensorValue = digitalRead(irSensorPin);

  // Print the sensor value to the serial monitor
  Serial.println(sensorValue);

  // Add a short delay for stability (you can adjust this value)
  delay(100);
}
