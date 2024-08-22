import serial
import csv

# Configure the serial port
serial_port = '/dev/cu.usbmodem101'  # Adjust to match your Arduino's port
baud_rate = 9600
ser = serial.Serial(serial_port, baud_rate, timeout=1)

# Open a CSV file to write the data
csv_filename = 'arduino_data_log_O.csv'
csv_file = open(csv_filename, 'w', newline='')
csv_writer = csv.writer(csv_file)

# Write the header row
header = ['Flex1', 'Flex2', 'Flex3', 'Flex4', 'Flex5', 
          'AccelX', 'AccelY', 'AccelZ', 
          'GyroX', 'GyroY', 'GyroZ', 
          'MagX', 'MagY', 'MagZ']
csv_writer.writerow(header)

print(f"Logging data to {csv_filename}. Press Ctrl+C to stop.")

try:
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        
        # Split the line into individual values based on spaces
        data = line.split()
        
        # Log only if we have the expected number of values (14 in this case)
        if len(data) == 11:
            csv_writer.writerow(data)
            csv_file.flush()  # Ensure data is written to the file
            print(f"Logged: {data}")
        else:
            print(f"Unexpected data format: {line}")

except KeyboardInterrupt:
    print("\nLogging stopped by user.")
finally:
    csv_file.close()
    ser.close()
    print(f"Data logged to {csv_filename}")
