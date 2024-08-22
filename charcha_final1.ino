#include "Arduino_BMI270_BMM150.h"

const int flexPins[5] = {A1, A2, A3, A5, A6};
int flexMin[5], flexMax[5];
float accelOffset[3], gyroOffset[3];
bool isCalibrated = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  calibrateSensors();
}

void calibrateSensors() {
  // Serial.println("Flex Sensor Calibration");
  // Serial.println("Fully bend all fingers for 5 seconds");
  delay(3000);

  for (int i = 0; i < 5; i++) {
    flexMin[i] = analogRead(flexPins[i]);
  }

  // Serial.println("Straighten all fingers for 5 seconds");
  delay(3000);

  for (int i = 0; i < 5; i++) {
    flexMax[i] = analogRead(flexPins[i]);
  }

  isCalibrated = true;
  // Serial.println("Calibration complete. Starting data collection.");
}

int capFlexValue(int value) {
  if (value < 90) return 90;
  if (value > 390) return 390;
  return value;
}

void captureAndPrintData() {
  float ax, ay, az, gx, gy, gz, mx, my, mz;
  int flexValues[5];

  for (int i = 0; i < 5; i++) {
    int rawFlexValue = analogRead(flexPins[i]);
    int mappedValue = map(rawFlexValue, flexMin[i], flexMax[i], 90, 390);
    flexValues[i] = capFlexValue(mappedValue);
    Serial.print(flexValues[i]);
    Serial.print(" ");
  }

  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable() && IMU.magneticFieldAvailable()) {
    IMU.readAcceleration(ax, ay, az);
    IMU.readGyroscope(gx, gy, gz);

    Serial.print((ax) * 9.81);
    Serial.print(" ");
    Serial.print((ay) * 9.81);
    Serial.print(" ");
    Serial.print((az) * 9.81);
    Serial.print(" ");
    Serial.print(gx);
    Serial.print(" ");
    Serial.print(gy);
    Serial.print(" ");
    Serial.println(gz);
  }
}

void loop() {
  if (!isCalibrated) {
    calibrateSensors();
  }

  // Serial.println("Make a sign. Capturing in 5 seconds...");
  delay(3000);
  captureAndPrintData();
  // Serial.println("Captured!");

  delay(3000);  // Additional delay after capture, adjust as needed
}