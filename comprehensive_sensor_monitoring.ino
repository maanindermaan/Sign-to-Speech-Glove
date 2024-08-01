#include "Arduino_BMI270_BMM150.h"

// Define the pins for the flex sensors
const int flexPins[5] = {A1, A2, A3, A5, A6};

// Variables to store IMU readings
float xGyro, yGyro, zGyro;
float xAccel, yAccel, zAccel;

void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate for faster data transfer
  while (!Serial);  // Wait for the Serial Monitor to open

  // Initialize the IMU
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");  // Print an error message if IMU initialization fails
    while (1);  // Stop the program execution
  }

  // Print the gyroscope sample rate
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");

  // Print the accelerometer sample rate
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");

  Serial.println("Started");  // Indicate that the setup is complete
}

void loop() {
  // Read and store flex sensor values
  int flexValues[5];
  for (int i = 0; i < 5; i++) {
    flexValues[i] = analogRead(flexPins[i]);  // Read analog values from flex sensors
  }

  // Read gyroscope values if available
  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(xGyro, yGyro, zGyro);
  }

  // Read accelerometer values if available
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(xAccel, yAccel, zAccel);
  }

  // Print all sensor values to the Serial Monitor
  Serial.print("Finger1: ");
  Serial.print(flexValues[0]);
  Serial.print("\tFinger2: ");
  Serial.print(flexValues[1]);
  Serial.print("\tFinger3: ");
  Serial.print(flexValues[2]);
  Serial.print("\tFinger4: ");
  Serial.print(flexValues[3]);
  Serial.print("\tFinger5: ");
  Serial.print(flexValues[4]);
  Serial.print("\tXg: ");
  Serial.print(xGyro);
  Serial.print("\tYg: ");
  Serial.print(yGyro);
  Serial.print("\tZg: ");
  Serial.print(zGyro);
  Serial.print("\tXa: ");
  Serial.print(xAccel);
  Serial.print("\tYa: ");
  Serial.print(yAccel);
  Serial.print("\tZa: ");
  Serial.println(zAccel);

  delay(1000);  // Delay for readability of the output
}
