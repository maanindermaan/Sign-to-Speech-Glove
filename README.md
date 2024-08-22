# Sign To Speech Glove Project

**Project Overview**  
This project involves the development of a Sign to Speech Glove that utilizes various sensors to translate hand gestures into spoken words. The glove integrates accelerometers, gyroscopes, and flex sensors to capture finger movements and hand orientations, which are then processed and converted into speech output.

**Team Members**
- Kabir Kapur
- Namanbeer
- Maninder Maan
- Kunwarpreet Singh

**Institution**  
Thapar Institute of Engineering and Technology

**Project Components**

1. **Accelerometer Tilt Detection using Arduino Nano 33 BLE Sense**
   - **Code:** [`accelerometer_tilt_detection.ino`](accelerometer_tilt_detection.ino)

2. **Gyroscope Collision Detection using Arduino Nano 33 BLE Sense**
   - **Code:** [`gyroscope_collision_detection.ino`](gyroscope_collision_detection.ino)

3. **Flex Sensor Data Acquisition using Arduino**
   - **Code:** [`flex_sensor_data_acquisition.ino`](flex_sensor_data_acquisition.ino)

4. **Creating a CSV File of Data Gathered using Sensors**
   - **Code:** [`create_csv.py`](create_csv.py)

5. **Comprehensive Sensor Data Monitoring with Flex Sensors and IMU**
   - **Code:** [`comprehensive_sensor_monitoring.ino`](comprehensive_sensor_monitoring.ino)

6. **Test Data Processing and Prediction**
   - **Description:** This script reads sensor data from the Arduino, processes it, and uses a trained model to predict gestures, converting the prediction to speech.
   - **Code:** [`testdata.py`](test_data.py)

7. **Data Logging for Analysis**
   - **Description:** This script logs data from the sensors to a CSV file for further analysis and training.
   - **Code:** [`to_excel_charcha.py`](https://github.com/yourusername/yourrepository/blob/main/to_excel_charcha.py)

8. **Training Data Model**
   - **Description:** This script trains a Random Forest model on the sensor data and saves the trained model and scaler for future predictions.
   - **Code:** [`train_data.py`](https://github.com/yourusername/yourrepository/blob/main/train_data.py)

9. **Calibration and Data Capture**
   - **Description:** This script handles calibration of flex sensors and captures the necessary data for training and prediction.
   - **Code:** [`charcha_final1.ino`](charcha_final1.ino)

10. **Bluetooth Data Visualization**
    - **Description:** This script reads data from flex sensors and sends it over Bluetooth, allowing for real-time visualization and monitoring.
    - **Code:** [`charcha_visualize_final.ino`](charcha_visualize_final.ino)

**Models**

- [`serial_classifier_model.pkl`](serial_classifier_model.pkl)
- [`serial_classifier_scaler.pkl`](serial_classifier_scaler.pkl)

**Requirements**
- **Hardware:**
  - Arduino Nano 33 BLE Sense
  - Flex Sensors
- **Software:**
  - Arduino IDE
  - Python 3.x
  - gTTS library
  - playsound library
  - Arduino_BMI270_BMM150 library

**Setup Instructions**
- **Hardware Setup:**
  - Connect the flex sensors to the specified analog pins on the Arduino Nano 33 BLE Sense.
  - Ensure the Arduino Nano 33 BLE Sense is properly connected to your computer.

- **Software Setup:**
  - Install the Arduino IDE.
  - Install the necessary libraries:
    - Arduino_BMI270_BMM150: Go to Arduino IDE -> Tools -> Manage Libraries -> Search for "Arduino_BMI270_BMM150" and install it.
  - Clone this repository:
    ```sh
    git clone https://github.com/yourusername/yourrepository.git
    cd yourrepository
    ```
  - Open the `.ino` files in the Arduino IDE and upload them to the Arduino Nano 33 BLE Sense.

- **Python Script Setup:**
  - Ensure Python 3.x is installed.
  - Install the required Python libraries:
    ```sh
    pip install gtts playsound
    ```
  - Run the Python script:
    ```sh
    python create_csv.py
    ```

**Usage**
- Upload the Arduino sketches to the Arduino Nano 33 BLE Sense.
- Run the Python script to start capturing sensor data and converting it into speech.

**Contribution**
Feel free to fork this repository, make improvements, and submit pull requests. Any contributions are highly appreciated!

**License**
This project is licensed under the MIT License - see the LICENSE file for details.

**Acknowledgments**
We would like to thank Thapar Institute of Engineering and Technology for providing the resources and support for this project.
