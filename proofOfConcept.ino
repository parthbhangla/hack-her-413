#include <SoftwareSerial.h>
#include <Servo.h>

Servo myservo;
SoftwareSerial BTserial(10, 11); // declaring rx and tx pins
void setup() {
  Serial.begin(9600);   // set up serial monitor
  BTserial.begin(9600); // set up bluetooth module
  myservo.attach(9);
}

void loop() {
  if (Serial.available() > 0) { // check if there **is** incoming data
    int input = Serial.parseInt(); // read data as integer
    int c = BTserial.read();      // read the incoming data
    Serial.print(c);      // print tha data
    if (input == 1234) { // check for input
      myservo.write(180);// move servo
      delay(5000); 
      myservo.write(0);
    }
  }
}
