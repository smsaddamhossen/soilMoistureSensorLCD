#include <LiquidCrystal_I2C.h>
#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  lcd.init(); //display initialization
  lcd.backlight(); // activate the backlight
}

void loop() {
  int value = analogRead(AOUT_PIN); 
  int vvalue = map(value,0,1023,0,5);
  int mvalue = map(value,1023,242,0,100);
  //Serial.println(value);
  //lcd.setCursor(1,0); 
  //lcd.print("Reading Data.."); 
  //delay(3000);
  //lcd.clear();
  lcd.setCursor(2,0); 
  lcd.print("Moisture : ");
  lcd.setCursor(2,1);  
  lcd.print(mvalue);
  lcd.print(" %");
  delay(500);
  lcd.clear();
}

