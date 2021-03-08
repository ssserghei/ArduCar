//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  //1 Line 
  lcd.setCursor(0,0);   //(position,line)
  lcd.print("6543210987654321");//16 characaters
   //2 Line1
  lcd.setCursor(0,1);     //(position,line)
  lcd.print("6543210987654321!");//16 characaters
  //3 Line
  lcd.setCursor(16, 0);     //(position,line)
  lcd.print("1234");     //only 4 character!!!
  lcd.setCursor(0, 2);  //(position,line)
  lcd.print("567890123456");//12-16 caracters
  //4 Line
  lcd.setCursor(16, 1);  //(position,line)
  lcd.print("1234");     //only 4 character!!!
  lcd.setCursor(0, 3);//(position,line)
  lcd.print("567890123456");//12-16 caracters
   
}

void loop()
{
  
}
