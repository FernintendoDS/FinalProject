import serial
import time
import struct
arduinoL = serial.Serial('/dev/ttyACM0', 9600, timeout=1.0)
arduinoM = serial.Serial('/dev/ttyACM1', 9600, timeout=1.0)
time.sleep(3)

def send_command():
    while True:
        line = arduinoL.readline().decode().strip()
        
        print(line)
    

send_command()
    
arduino.close()
    
    
