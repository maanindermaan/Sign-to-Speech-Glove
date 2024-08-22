#include <ArduinoBLE.h>

const int flexPins[5] = {A1, A2, A3, A5, A6};
const int numSensors = 5;
int flexMin[numSensors] = {1023, 1023, 1023, 1023, 1023};
int flexMax[numSensors] = {0, 0, 0, 0, 0};

BLEService flexService("19b10000-e8f2-537e-4f6c-d104768a1214");
BLECharacteristic flexCharacteristic("19b10001-e8f2-537e-4f6c-d104768a1214", BLERead | BLENotify, 30);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Starting BLE failed!");
    while (1);
  }

  BLE.setLocalName("FlexSensorGlove");
  BLE.setAdvertisedService(flexService);
  flexService.addCharacteristic(flexCharacteristic);
  BLE.addService(flexService);
  BLE.advertise();

  Serial.println("Bluetooth device active, waiting for connections...");
  
  // Initial calibration
  calibrateSensors();
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());
    while (central.connected()) {
      updateAndSendFlexData();
      delay(50);  // Send data every 50ms for smoother updates
    }
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }
}

void calibrateSensors() {
  Serial.println("Calibrating sensors...");
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < numSensors; j++) {
      int value = analogRead(flexPins[j]);
      if (value < flexMin[j]) flexMin[j] = value;
      if (value > flexMax[j]) flexMax[j] = value;
    }
    delay(20);
  }
  Serial.println("Calibration complete.");
}

void updateAndSendFlexData() {
  String data = "";
  for (int i = 0; i < numSensors; i++) {
    int rawValue = analogRead(flexPins[i]);
    
    // Map the raw value to the 90-390 range
    int mappedValue = map(rawValue, flexMin[i], flexMax[i], 90, 390);
    mappedValue = constrain(mappedValue, 90, 390);

    data += String(mappedValue);
    if (i < numSensors - 1) {
      data += ",";
    }
  }
  
  flexCharacteristic.writeValue(data.c_str());
  Serial.println("Sent: " + data);
}