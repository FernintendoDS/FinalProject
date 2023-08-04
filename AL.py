import serial
import time
import struct
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1.0)
time.sleep(3)

def arduino_send(data):
    arduino.write(data.encode())

def arduino_read():
    data = arduino.readline().decode().strip()
    return data

def get_imu():
    arduino.write('i')
    data = arduino_read()
    return data
    
def get_ultrasonic_back():
    arduino.write('u')
    data = arduino_read()
    return data

def motor_control():
    arduino.write('m')
    data = arduino_read()
    return data

def fan_control():
    arduino.write('f')
    data = arduino_read()
    return data

def get_temp():
    arduino.write('t')
    data = arduino_read()
    return data

