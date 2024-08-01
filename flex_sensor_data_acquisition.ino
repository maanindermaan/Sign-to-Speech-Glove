const int flexPins[5] = {A1, A2, A3, A5, A6};  // Pins for flex sensors

void setup() {
  Serial.begin(115200);  // Higher baud rate for faster serial communication
}

void loop() {
  // Read all sensor values and print them to the Serial Monitor
  for (int i = 0; i < 5; i++) {
    int flexValue = analogRead(flexPins[i]);  // Read the analog value from the flex sensor
    Serial.print("Finger ");
    Serial.print(i + 1);  // Print the finger number
    Serial.print(": ");
    Serial.print(flexValue);  // Print the flex sensor value
    Serial.print("\t");  // Tab-separated values for readability
  }
  Serial.println();  // New line after printing all sensor values

  delay(1000);  // Small delay to avoid too frequent polling
}
