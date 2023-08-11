import serial
import time
import struct
arduino = serial.Serial('/dev/ttyACM6', 9600, timeout=1.0)
time.sleep(1)

def arduino_send(data):
    arduino.write(data.encode())

def arduino_read():
    data = arduino.readline().decode().strip()
    return data

def get_imu():
    arduino_send('i')
    data = arduino_read()
    return data
    
def get_ultrasonic_back():
    arduino_send('u')
    data = arduino_read()
    return data

def motor_control():
    arduino_send('m')
    data = arduino_read()
    return data

def fan_control():
    arduino_send('f')
    data = arduino_read()
    return data

def get_temp():
    arduino_send('t')
    data = arduino_read()
    return data


