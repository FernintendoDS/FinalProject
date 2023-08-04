import serial
import time

# Replace 'COM3' with the appropriate serial port of your Arduino.
# On Windows, it will be 'COMX', and on macOS or Linux, it will be '/dev/ttyUSBX' or '/dev/ttyACMX'.
ser = serial.Serial('COM3', 9600, timeout=1)

def send_data_to_arduino(data):
    ser.write(data.encode())

def receive_data_from_arduino():
    data = ser.readline().decode().strip()
    return data

if __name__ == "__main__":
    try:
        while True:
            # Example usage:
            command = input("Enter 1 to turn on LED, 0 to turn off LED: ")
            send_data_to_arduino(command)
            time.sleep(0.1)
            response = receive_data_from_arduino()
            print("Arduino response:", response)
    except KeyboardInterrupt:
        ser.close()
