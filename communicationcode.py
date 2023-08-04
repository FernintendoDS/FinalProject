import serial
import time
import struct
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1.0)
time.sleep(3)

def send_command():
    while True:
        line = arduino.readline().decode().strip()
        
        print(line)
    

send_command()
    
arduino.close()
    
    
