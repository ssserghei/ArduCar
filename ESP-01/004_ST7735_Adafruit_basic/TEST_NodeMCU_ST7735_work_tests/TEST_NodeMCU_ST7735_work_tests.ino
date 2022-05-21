
/*
 *  ForbiddenBit.com
 *  
 *  NodeMCU and Display ST7735
 *  работает но левая сторона с краю есть артефакты
 */

//  --------  Libraries required to use the Display  ---------------
#include <Adafruit_GFX.h>       
#include <Adafruit_ST7735.h> 
#include <SPI.h>

// -----------  Display pins  --------------------------------------
#define TFT_CS         15      
#define TFT_RST        0
#define TFT_DC         2

void setup() {
  
  Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST); //Those things are for the display
  tft.initR(INITR_GREENTAB);



 // --------  TEST TEXT  -------------------------------------------
  
  tft.fillScreen(ST7735_BLACK);
  tft.setTextWrap(false);
  tft.setCursor(0, 2);    //Horiz/Vertic
  tft.setTextSize(3);
  tft.setTextColor(ST7735_YELLOW);
  tft.print("SERGHEI");

  tft.fillScreen(ST7735_RED);
  delay(100);
  tft.fillScreen(ST7735_GREEN);
  delay(100);
  tft.fillScreen(ST7735_BLUE);
  delay(100);
  tft.fillScreen(ST7735_BLACK);
/*
  tft.setCursor(15, 25);    //Horiz/Vertic
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE);
  tft.print("COVID-19 Tracker");

  tft.setCursor(5, 45);    //Horiz/Vertic
  tft.setTextSize(2);
  tft.setTextColor(ST7735_BLUE);
  tft.print("Cases:");
  tft.setCursor(10, 65);
  tft.print("929,637");  

  tft.setCursor(5, 93);    //Horiz/Vertic
  tft.setTextSize(2);
  tft.setTextColor(ST7735_GREEN);
  tft.print("RECOVERED:");
  tft.setCursor(15, 115);
  tft.setTextColor(ST7735_WHITE);
  tft.print("110,504"); 


  tft.fillRect(0, 138 , 48, 10, ST7735_WHITE); 
  tft.setCursor(7, 140);    //Horiz/Vertic
  tft.setTextSize(1);
  tft.setTextColor(ST7735_BLACK);
  tft.print("DEATHS:  ");
  tft.setCursor(55, 140);
  tft.setTextColor(ST7735_WHITE);
  tft.print("52,838");
 */

} 

void loop() {

  
 
}
