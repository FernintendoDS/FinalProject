#include <Wire.h>

#define PCA_ADDR 0x70      // I2C address of the PCA9548A multiplexer
#define ULTRASONIC_ADDR 0x57 // Address of the I2C ultrasonic sensor

void setup() {
  
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read();
      if(data == 'u'){ 
      read_ultrasonic(2,"UF1");
      }
      if(data == 's'){
      read_ultrasonic(3,"UF2");
      }
      if(data == 't'){
      read_ultrasonic(4,"UF3");
      }
}
}
void read_ultrasonic(int number,String text) {
  
        Wire.beginTransmission(PCA_ADDR);
        Wire.write(1 << number);        // Enable channel 
        Wire.endTransmission();
  
        Wire.beginTransmission(ULTRASONIC_ADDR);
        Wire.write(0x01);     // Example command to trigger measurement
        Wire.endTransmission();

        // Wait for the measurement to complete (adjust based on sensor specs)
         delay(100);

        // Request data from the ultrasonic sensor
        Wire.requestFrom(ULTRASONIC_ADDR, 5); // Request 5 bytes of data from the sensor

        // Check if data is available
        if (Wire.available() >= 2) {
        byte highByte = Wire.read();
        byte lowByte = Wire.read();
        int distance = (highByte << 8) | lowByte; // Combine high and low bytes into a 16-bit integer

        // Process the distance data as needed
        float distanceInCentimeters = static_cast<float>(distance) / 10.0;
        Serial.print(text); Serial.print(" ");
        Serial.println(distanceInCentimeters);

        delay(100);
        }
  }
    
