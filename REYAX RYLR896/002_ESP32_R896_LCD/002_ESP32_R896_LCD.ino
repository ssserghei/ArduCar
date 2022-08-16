/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-oled
 */
 //https://esp32io.com/tutorials/esp32-oled

 /*
 работает для ESP и 0,91" OLED дисплеем
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define RXD2 16
#define TXD2 17

#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 32 // OLED height, in pixels




// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
// Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: "+String(TX));
  Serial.println("Serial Rxd is on pin: "+String(RX));

  

  Serial2.print("AT\r\n");   //общаемся с молулем,посылаем команду AT
  delay(100);
    Serial.print(char(Serial2.read()));

  //посылаем тестовое сообщение в эфир 
   Serial2.print("AT+SEND=0,8,ArduHelo\r\n");   //send "HELLO" to address 0("5" bytes)

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }//end setup

  delay(2000);         // wait two seconds for initializing
  oled.clearDisplay(); // clear display

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 0);       // set position to display
  oled.println("1111"); // set text
  oled.display();              // display on OLED

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 10);       // set position to display
  oled.println("123"); // set text
  oled.display();              // display on OLED

  oled.setTextSize(1);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 20);       // set position to display
  oled.println("3333"); // set text
  oled.display();              // display on OLED
}

void loop() {

  //то что пришло от лоры посылаем в компорт и наоборот.
  //то что пришло с компорт посылаем лоре. 
 while (Serial2.available()) {
    Serial.print(char(Serial2.read()));
  }
  
}
