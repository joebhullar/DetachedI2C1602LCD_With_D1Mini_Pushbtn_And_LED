/*
  Hello World 
  Author: Bonezegei (Jofel Batutay)
  Date:  January 2024
*/

#include <Bonezegei_LCD1602_I2C.h>

Bonezegei_LCD1602_I2C lcd(0x3F); //K22901 PCF8574AT LCD SCREEN DRIVER WORKING we use 0x3f for the LCD
bool buttonStateValue = 0;
bool currentPushButtonState;
bool firstButtonPress = false;  // Flag to track first button press
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D5, INPUT_PULLUP);
  
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  lcd.begin();
  //lcd.print("BIGGER THAN TOMMMYS!");
  lcd.setPosition(0, 0);
  lcd.print("JOE'S PROJECT!");

  lcd.setPosition(0, 1);      //param1 = X   param2 = Y
  //lcd.print("HD44780");
  lcd.print("PUSH THE BUTTON!");
  delay(5000);
}

void loop() {

   if (!firstButtonPress) {  // Check if the button has been pressed for the first time
       currentPushButtonState = digitalRead(D5);
        if (currentPushButtonState == 1) {
          firstButtonPress = true;  // Set the flag to true after the first press
        }
   } else if (firstButtonPress) {

      currentPushButtonState = digitalRead(D5); 
      if(currentPushButtonState  == 1) { 
        if (buttonStateValue ==0) {
          buttonStateValue = 1;
        } else if (buttonStateValue ==1) 
        {
          buttonStateValue =0;
        }
      }

      if (buttonStateValue == 1) {
          delay(500);
          Serial.print(" BUTToN PRESSED ");
          lcd.setPosition(0, 1);      //param1 = X   param2 = Y
          lcd.print("BUTTON PRESSED");
          digitalWrite(LED_BUILTIN, HIGH); 
      } else if (buttonStateValue == 0) {
          delay(500);
          Serial.print(" TURNED OFF  ");
          lcd.setPosition(0, 1);      //param1 = X   param2 = Y
          lcd.print("  TURNED  OFF  ");
          digitalWrite(LED_BUILTIN, LOW); 
      }
  }
}
