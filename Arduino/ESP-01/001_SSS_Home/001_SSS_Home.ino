/*
Проект рабочий. Выводит на дисплей температуру
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

#include <LM73.h>
#include <Wire.h>

LM73 lm73 = LM73();

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
//  lm73.begin(LM73_0_I2C_FLOAT);
  lm73.begin(LM73_0_I2C_GND);   //LM73_0_I2C_GND = 0x49,  
  lm73.setResolution(LM73_RESOLUTION_14BIT); // 14 bit
  lm73.power(LM73_POWER_OFF); // Turn off sensor (one shot temperature conversion)
  
}//END Setup 



/*Бесконечный цикл*/
void loop()
{
  delay(1000);
  // Begin one shot conversion 
  // Don't turn on sensor, that's done automatically
  lm73.startOneShot();
// Start timing conversion
  byte start = millis();

  // Wait for completion
  while(!lm73.ready());

  // Workout conversion time
  byte time = ((byte)millis()) - start;

  // Get the temperature
  double temp = lm73.temperature();

  Serial.print("Conversion time: ");
  Serial.println(time);

  Serial.print("Temperature: ");
  Serial.println(temp, 5);

  Serial.println();

  display.clearDisplay();                    // Очищаем дисплей
  display.setTextSize(2);                    // Устанавливаем размер шрифта
  display.setTextColor(WHITE);               // Цвет фона
  display.setCursor(0,0);                    // Установить позицию x, y для отображения
  display.println("   Temp  ");     // Отправка текста

  display.setCursor(0,20);                   // Установить позицию x, y для отображения 
  display.setTextSize(3);                    // Устанавливаем размер шрифта
  display.setTextColor(WHITE);        // Установить белый текст, черный фон
  display.println(temp, 4);             // Отправка текста
  display.display();

                         
}//END Loop
