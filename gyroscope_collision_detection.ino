#include "Arduino_BMI270_BMM150.h"  // Include the IMU library

float x, y, z;  // Variables to store gyroscope data

int plusThreshold = 30, minusThreshold = -30;  // Thresholds for detecting collisions

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  while (!Serial);  // Wait for the serial port to connect
  Serial.println("Started");  // Print a message indicating that the program has started

  // Check if the IMU begins correctly
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");  // Print error message if IMU initialization fails
    while (1);  // Infinite loop to halt the program
  }

  // Print the gyroscope sample rate
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
}

void loop() {
  // Check if new gyroscope data is available
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);  // Read gyroscope data

    // Check and process collision detection
    if (y > plusThreshold) {  // If the Y-axis gyroscope reading exceeds the positive threshold
      Serial.println("Collision front");  // Print message indicating a front collision
      delay(500);  // Delay to avoid multiple triggers
    }

    if (y < minusThreshold) {  // If the Y-axis gyroscope reading exceeds the negative threshold
      Serial.println("Collision back");  // Print message indicating a back collision
      delay(500);  // Delay to avoid multiple triggers
    }

    if (x < minusThreshold) {  // If the X-axis gyroscope reading exceeds the negative threshold
      Serial.println("Collision right");  // Print message indicating a right collision
      delay(500);  // Delay to avoid multiple triggers
    }

    if (x > plusThreshold) {  // If the X-axis gyroscope reading exceeds the positive threshold
      Serial.println("Collision left");  // Print message indicating a left collision
      delay(500);  // Delay to avoid multiple triggers
    }
  }
}
