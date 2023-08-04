import serial
import time
import struct
arduino = serial.Serial('/dev/ttyACM1', 9600, timeout=1.0)
time.sleep(3)

def arduino_send(data):
    arduino.write(data.encode())

def arduino_read():
    data = arduino.readline().decode().strip()
    return data

def get_ultrasonic_front():
    arduino.write('u')
    data = arduino_read()
    return data

def get_motor_dir():
    arduino.write('m')
    data = arduino_read()
    return data
