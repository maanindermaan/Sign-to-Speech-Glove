# Sign To Speech Glove Project

## Project Overview

This project involves the development of a Sign to Speech Glove that utilizes various sensors to translate hand gestures into spoken words. The glove integrates accelerometers, gyroscopes, and flex sensors to capture finger movements and hand orientations, which are then processed and converted into speech output.

## Team Members
- Kabir Kapur
- Namanbeer
- Maninder Maan
- Kunwarpreet Singh

## Institution
Thapar Institute of Engineering and Technology

## Project Components

### 1. Accelerometer Tilt Detection using Arduino Nano 33 BLE Sense

This component tests the accelerometer of the Arduino Nano 33 BLE Sense to detect tilting in different directions. The code reads acceleration data from the IMU and maps it to degrees of tilt, providing feedback on the direction and degree of tilting.

**Code:** [accelerometer_tilt_detection.ino](./accelerometer_tilt_detection.ino)

### 2. Gyroscope Collision Detection using Arduino Nano 33 BLE Sense

This component uses the gyroscope of the Arduino Nano 33 BLE Sense to detect collisions from different directions. The code reads gyroscope data and checks if the readings exceed predefined thresholds to determine if a collision has occurred.

**Code:** [gyroscope_collision_detection.ino](./gyroscope_collision_detection.ino)

### 3. Flex Sensor Data Acquisition using Arduino

This component reads data from five flex sensors connected to an Arduino and prints the values to the Serial Monitor. The flex sensors are used to detect the bending of fingers, which can be useful in applications such as gesture recognition and sign language interpretation.

**Code:** [flex_sensor_data_acquisition.ino](./flex_sensor_data_acquisition.ino)

### 4. Creating a CSV File of Data Gathered using Sensors

This script captures data from the sensors and writes it to a CSV file. It also includes functionality to convert the sensor readings into speech using the Google Text-to-Speech API.

**Code:** [create_csv.py](./create_csv.py)

### 5. Comprehensive Sensor Data Monitoring with Flex Sensors and IMU

This Arduino sketch reads data from five flex sensors and an IMU (gyroscope and accelerometer) on an Arduino Nano 33 BLE Sense. It prints the sensor values to the Serial Monitor, providing a comprehensive overview of finger flexion and motion detection.

**Code:** [comprehensive_sensor_monitoring.ino](./comprehensive_sensor_monitoring.ino)

## Requirements

- Arduino Nano 33 BLE Sense
- Flex Sensors
- Arduino IDE
- Python 3.x
- gTTS library
- playsound library
- Arduino_BMI270_BMM150 library

## Setup Instructions

1. **Hardware Setup:**
    - Connect the flex sensors to the specified analog pins on the Arduino Nano 33 BLE Sense.
    - Ensure the Arduino Nano 33 BLE Sense is properly connected to your computer.

2. **Software Setup:**
    - Install the Arduino IDE from [here](https://www.arduino.cc/en/software).
    - Install the necessary libraries:
      - Arduino_BMI270_BMM150: Go to Arduino IDE -> Tools -> Manage Libraries -> Search for "Arduino_BMI270_BMM150" and install it.
    - Clone this repository:
      ```sh
      git clone https://github.com/yourusername/SignToSpeechGloveProject.git
      cd SignToSpeechGloveProject
      ```
    - Open the `.ino` files in the Arduino IDE and upload them to the Arduino Nano 33 BLE Sense.

3. **Python Script Setup:**
    - Ensure Python 3.x is installed.
    - Install the required Python libraries:
      ```sh
      pip install gtts playsound
      ```
    - Run the Python script:
      ```sh
      python create_csv.py
      ```

## Usage

- Upload the Arduino sketches to the Arduino Nano 33 BLE Sense.
- Run the Python script to start capturing sensor data and converting it into speech.

## Contribution

Feel free to fork this repository, make improvements, and submit pull requests. Any contributions are highly appreciated!

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

## Acknowledgments

We would like to thank Thapar Institute of Engineering and Technology for providing the resources and support for this project.
