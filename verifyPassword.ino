#include <EEPROM.h>
#include <Servo.h>

#define PASSWORD_LENGTH 4 
#define PASSWORD_ADDRESS 0 
#define SERVO_PIN 9 

Servo myservo; 

void setup() {
  Serial.begin(9600); 
  myservo.attach(SERVO_PIN); 
}

void loop() {
  char password[PASSWORD_LENGTH + 1]; 
  // prompt the user to enter the password
  Serial.println("Please enter the password:");
  while (Serial.available() < PASSWORD_LENGTH); 
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = Serial.read(); 
    Serial.print("*"); 
  }
  password[PASSWORD_LENGTH] = '\0'; 
  
  // compare the entered password with the stored password in EEPROM memory
  char stored_password[PASSWORD_LENGTH + 1];
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    stored_password[i] = EEPROM.read(PASSWORD_ADDRESS + i); 
  }
  stored_password[PASSWORD_LENGTH] = '\0'; 
  if (strcmp(password, stored_password) == 0) { 
    Serial.println("\nPassword accepted. Turning servo...");
    myservo.write(90); 
    delay(2000); 
    myservo.write(0); 
  } else {
    Serial.println("\nIncorrect password.");
  }
}
