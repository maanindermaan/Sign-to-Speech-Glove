import serial
import numpy as np
import joblib
from gtts import gTTS
import os
from playsound import playsound

def speak(text):
    tts = gTTS(text=text, lang='en')
    tts.save("output.mp3")
    playsound("output.mp3")
    os.remove("output.mp3")

# Load the trained model and scaler
model = joblib.load('serial_classifier_model.pkl')
scaler = joblib.load('serial_classifier_scaler.pkl')

# Configure the serial port
serial_port = '/dev/cu.usbmodem101'  # Adjust to match your Arduino's port
baud_rate = 9600
ser = serial.Serial(serial_port, baud_rate, timeout=1)

print("Listening for data...")

try:
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        print(">>>>>",line)
        if line:
            # Process the line into a list of floats
            data = np.array([float(x) for x in line.split()]).reshape(1, -1)

            # Scale the input data
            scaled_data = scaler.transform(data)

            # Predict using the model
            prediction = model.predict(scaled_data)[0]
            confidence = np.max(model.predict_proba(scaled_data))

            if confidence > 0.3:  # Only consider predictions with high confidence
                print(f"Prediction: {prediction}")
                speak(prediction)
            else:
                print("Prediction: Not Found")
                speak('L')

except KeyboardInterrupt:
    print("\nStopped by user.")
finally:
    ser.close()
