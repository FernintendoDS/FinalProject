#include <Wire.h>

void setup() {
  Serial.begin(9600);

  
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();

    if (data == 'u') {
      read_all_ultrasonic();
    } 
    
  }
}

read_all_ultrasonic() {

    
}
