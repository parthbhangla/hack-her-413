#include <EEPROM.h>

#define PASSWORD_LENGTH 4 
#define PASSWORD_ADDRESS 0 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  char password[PASSWORD_LENGTH + 1]; 
  
  // prompting the user to set the password
  Serial.println("Please set a password:");
  while (Serial.available() < PASSWORD_LENGTH); 
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    password[i] = Serial.read(); 
  }
  password[PASSWORD_LENGTH] = '\0'; 
  
  // storing the password in the memory
  for (int i = 0; i < PASSWORD_LENGTH; i++) {
    EEPROM.write(PASSWORD_ADDRESS + i, password[i]); 
  }
  EEPROM.write(PASSWORD_ADDRESS + PASSWORD_LENGTH, '\0'); 
  
  Serial.println("Password set successfully.");
  delay(1000); 
}
