/*
https://ampermarket.kz/indicators/tft-display-128x160-st7735s/
http://robocontroller.ru/news/opisanie_biblioteki_adafruit_gfx_dlja_arduino/2015-04-26-56
*/

/*====================================================*/
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        15
  #define TFT_RST        0 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         2

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

/*SETUP====================================================*/
void setup(void) {
  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab

  tft.fillScreen(ST7735_BLACK);
  
/*--------------------------------------------------------*/
//tftPrintTest(teht);
  
  tft.setTextColor(ST7735_MAGENTA);
  tft.setTextSize(3);
  tft.setCursor(0,0);
int i;
int j;
int n = 5;
//    tft.print("*");
   
    for (int i = 1; i <= n; i++){
        for(int j = 0; j <i; j++){
             tft.print("*");
             delay(200);
        }
        tft.println("");
    }


}//END SETUP  

/*LOOP===================================================*/
void loop() {

}//END LOOP

/*====================================================*/
//128
//160



//  delay(500);
