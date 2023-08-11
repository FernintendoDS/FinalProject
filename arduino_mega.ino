#define ECHOpin1 2 // it defines the ECHO pin of the sensor to pin 2 of Arduino   
#define TRIGpin1 4  // it defines the TRIGGER pin of the sensor to pin 4 of Arduino 
#define ECHOpin2 7 // it defines the ECHO pin of the sensor to pin 7 of Arduino   
#define TRIGpin2 8 // it defines the TRIGGER pin of the sensor to pin 8 of Arduino 
#define ECHOpin3 12 // it defines the ECHO pin of the sensor to pin 12 of Arduino   
#define TRIGpin3 13 // it defines the TRIGGER pin of the sensor to pin 13 of Arduino 


// we have defined the variable  
long duration; // variable for the duration1 of sound wave travel  
int distance; // variable for the distance1 measurement  

void setup()   
{  
  pinMode(TRIGpin1, OUTPUT); // It sets the ECHO pin as OUTPUT  
  pinMode(ECHOpin1, INPUT); // It sets the TRIG pin as INPUT  
  pinMode(TRIGpin2, OUTPUT); // It sets the ECHO pin as OUTPUT  
  pinMode(ECHOpin2, INPUT); // It sets the TRIG pin as INPUT  
  pinMode(TRIGpin3, OUTPUT); // It sets the ECHO3 pin as OUTPUT  
  pinMode(ECHOpin3, INPUT); // It sets the TRIG pin as INPUT 
  
  Serial.begin(9600); // // Serial Communication at the rate of 9600 bps  
}   

void loop() {
  if (Serial.available() > 0) {
    char dataUtrasonic = Serial.read();

    if (data == 'u') {
      read_ultrasonicSensor(); 
    } 
    
  }
}

read_ultrasonicSensor(int num, String tag) {
 

  digitalWrite(TRIGpin1, LOW);  
  delayMicroseconds(4);  

  digitalWrite(TRIGpin1, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin1, LOW);  

  duration = pulseIn(ECHOpin1, HIGH);  

  distance1 = duration1*(0.034/2); 

  Serial.print(distance1);  
  Serial.println();
  
}
read_ultrasonicSensor2() {
 
  // It first sets the TRIG pin at LOW for 2 microseconds  
  digitalWrite(TRIGpin2, LOW);  
  delayMicroseconds(4);  
  // It now sets TRIG pin at HIGH for 15 microseconds  
  digitalWrite(TRIGpin2, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin2, LOW);  
  // It will read the ECHO pin and will return the time   
  duration2 = pulseIn(ECHOpin2, HIGH);  
  // distance formula  
  distance2 = duration2*(0.034/2); // (speed in microseconds)  
  // Speed of sound wave (340 m/s)divided by 2 (forward and backward bounce)  
  // To display the distance on Serial Monitor  
  Serial.print(distance2);  
  Serial.println();
  
}
read_ultrasonicSensor3() {
 
  // It first sets the TRIG pin at LOW for 2 microseconds  
  digitalWrite(TRIGpin3, LOW);  
  delayMicroseconds(4);  
  // It now sets TRIG pin at HIGH for 15 microseconds  
  digitalWrite(TRIGpin3, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin3, LOW);  
  // It will read the ECHO pin and will return the time   
  duration3 = pulseIn(ECHOpin3, HIGH);  
  // distance formula  
  distance3 = duration3*(0.034/2); // (speed in microseconds)  
  // Speed of sound wave (340 m/s)divided by 2 (forward and backward bounce)  
  // To display the distance on Serial Monitor  
  Serial.print(distance3);  
  Serial.println();
  
}
