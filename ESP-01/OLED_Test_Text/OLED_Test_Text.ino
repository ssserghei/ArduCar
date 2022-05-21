/*
работает на ESP-12F если выбрать плату node mcu 09

*/

#include <SPI.h>                        // Подключение библиотеки SPI
#include <Wire.h>                       // Подключение библиотеки Wire
#include <Adafruit_GFX.h>               // Подключение библиотеки Adafruit_GFX
#include <Adafruit_SSD1306.h>           // Подключение библиотеки Adafruit_SSD1306
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 1  //Если ваш OLED дисплей не имеет pin сброса, вы должны установить переменную OLED_RESET в значение -1
//Adafruit_SSD1306 display(OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
/*Инициализация Дисплея*/
Wire.begin(2,0); 
display.begin(SSD1306_SWITCHCAPVCC, 0x3c); // Указываем адрес дисплея
display.clearDisplay();

/*Инициализация I2C*/
  Serial.begin(74880); // The baudrate of Serial monitor is set in 9600
  while (!Serial); // Waiting for Serial Monitor
  Serial.println("\nI2C Scanner");

/*Инициализация датчика температуры LM73*/

}//END Setup 



/*Бесконечный цикл*/
void loop()
{
  display.clearDisplay();                    // Очищаем дисплей
  display.setTextSize(1);                    // Устанавливаем размер шрифта
  display.setTextColor(WHITE);               // Цвет фона
  display.setCursor(0,0);                    // Установить позицию x, y для отображения
  display.println(" OLED 0.96 TESTER ");     // Отправка текста

  display.setCursor(0,10);                   // Установить позицию x, y для отображения 
  display.setTextSize(2);                    // Устанавливаем размер шрифта
  display.setTextColor(BLACK, WHITE);        // Установить белый текст, черный фон
  display.println("Robot Chip");             // Отправка текста
  display.display();                       
}//END Loop
