import serial
import csv
import time
from gtts import gTTS
import os
from playsound import playsound

# Set the correct serial port (e.g., COM3 for Windows or /dev/ttyUSB0 for Linux)
serial_port = '/dev/cu.usbmodem101'  # Change this to your serial port
baud_rate = 9600  # Match the baud rate in your Arduino script
output_file = 'flex1_data.csv'

# Range thresholds
C_range = (195, 235)
O_range = (120, 135)

def speak(text):
    tts = gTTS(text=text, lang='en')
    tts.save("output.mp3")
    playsound("output.mp3")
    os.remove("output.mp3")

# Open the serial port
ser = serial.Serial(serial_port, baud_rate)
time.sleep(2)  # Give some time for the connection to establish

# Open the CSV file for writing
with open(output_file, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Time", "SensorValue"])  # Write the header

    while True:
        try:
            # Read a line from the serial port
            line = ser.readline().decode('utf-8').strip()
            
            # Check if the line contains the expected data
            if "Finger 1:" in line:
                # Extract the sensor value from the line
                sensor_value = int(line.split(":")[1].strip())
                # Get the current time
                current_time = time.strftime('%Y-%m-%d %H:%M:%S')
                # Write the data to the CSV file
                writer.writerow([current_time, sensor_value])
                print(f"Time: {current_time}, SensorValue: {sensor_value}")  # Print to console for debugging

                # Check the value range and speak accordingly
                if C_range[0] <= sensor_value <= C_range[1]:
                    speak("C")
                elif O_range[0] <= sensor_value <= O_range[1]:
                    speak("O")

        except KeyboardInterrupt:
            print("Program interrupted")
            break

# Close the serial port
ser.close()
