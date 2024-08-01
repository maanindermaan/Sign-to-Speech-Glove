#include "Arduino_BMI270_BMM150.h"  // Include the IMU library

float x, y, z;  // Variables to store acceleration data
int degreesX = 0;  // Variable to store the degree of tilt in the X direction
int degreesY = 0;  // Variable to store the degree of tilt in the Y direction

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  while (!Serial);  // Wait for the serial port to connect
  Serial.println("Started");  // Print a message indicating that the program has started

  // Check if the IMU begins correctly
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");  // Print error message if IMU initialization fails
    while (1);  // Infinite loop to halt the program
  }

  // Print the accelerometer sample rate
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
}

void loop() {
  // Check if new acceleration data is available
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);  // Read acceleration data

    // Check and process tilt in the X direction
    if (x > 0.1) {  // If the X-axis acceleration is greater than 0.1
      x = 100 * x;  // Scale the acceleration value
      degreesX = map(x, 0, 97, 0, 90);  // Map the scaled value to degrees
      Serial.print("Tilting up ");
      Serial.print(degreesX);  // Print the degree of tilt upwards
      Serial.println(" degrees");
    }

    if (x < -0.1) {  // If the X-axis acceleration is less than -0.1
      x = 100 * x;  // Scale the acceleration value
      degreesX = map(x, 0, -100, 0, 90);  // Map the scaled value to degrees
      Serial.print("Tilting down ");
      Serial.print(degreesX);  // Print the degree of tilt downwards
      Serial.println(" degrees");
    }

    // Check and process tilt in the Y direction
    if (y > 0.1) {  // If the Y-axis acceleration is greater than 0.1
      y = 100 * y;  // Scale the acceleration value
      degreesY = map(y, 0, 97, 0, 90);  // Map the scaled value to degrees
      Serial.print("Tilting left ");
      Serial.print(degreesY);  // Print the degree of tilt to the left
      Serial.println(" degrees");
    }

    if (y < -0.1) {  // If the Y-axis acceleration is less than -0.1
      y = 100 * y;  // Scale the acceleration value
      degreesY = map(y, 0, -100, 0, 90);  // Map the scaled value to degrees
      Serial.print("Tilting right ");
      Serial.print(degreesY);  // Print the degree of tilt to the right
      Serial.println(" degrees");
    }
  }
}
