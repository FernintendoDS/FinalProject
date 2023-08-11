#define ECHOpin1 2 // it defines the ECHO pin of the sensor to pin 2 of Arduino   
#define TRIGpin1 4  // it defines the TRIGGER pin of the sensor to pin 4 of Arduino 
#define ECHOpin2 7 // it defines the ECHO pin of the sensor to pin 7 of Arduino   
#define TRIGpin2 8 // it defines the TRIGGER pin of the sensor to pin 8 of Arduino 
#define ECHOpin3 12 // it defines the ECHO pin of the sensor to pin 12 of Arduino   
#define TRIGpin3 13 // it defines the TRIGGER pin of the sensor to pin 13 of Arduino 
 
long duration; // variable for the duration1 of sound wave travel  
int distance; // variable for the distance1 measurement  

void setup() {  
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
    char data = Serial.read();

    if (data == 'u') {
      read_ultrasonic(1,"UFL"); 
      read_ultrasonic(2,"UFM"); 
      read_ultrasonic(3,"UFR"); 
    } 
    
  }
}

void read_ultrasonic(int number, String text) {
if (number == 1) {
  digitalWrite(TRIGpin1, LOW);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin1, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin1, LOW);  
  duration = pulseIn(ECHOpin1, HIGH);  
}
if (number == 2) {
  digitalWrite(TRIGpin2, LOW);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin2, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin2, LOW);  
  duration = pulseIn(ECHOpin2, HIGH);  
}
if (number == 3) {
  digitalWrite(TRIGpin3, LOW);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin3, HIGH);  
  delayMicroseconds(4);  
  digitalWrite(TRIGpin3, LOW);  
  duration = pulseIn(ECHOpin3, HIGH);  
}
  distance = duration*(0.034/2); 
  Serial.print(text); Serial.print(" ");  
  Serial.println(distance);
  
}
