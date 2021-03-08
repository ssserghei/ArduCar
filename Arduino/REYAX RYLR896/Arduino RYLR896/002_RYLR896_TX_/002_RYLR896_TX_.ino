/*Скеч РАБОЧИЙ. 08,03,2021
 * тестовый проект с моулем лора, общаемся с модулем 
и перебрасываем данные с компорта лоре и с лоры в компорт
выводим чтото на I2C дисплей

*/
/*
Лог обмена с модулем
AT
+OK
AT+MODE?
+MODE=0
AT+IPR?
+IPR=115200
AT+PARAMETER?
+PARAMETER=12,7,1,4
AT+BAND?
+BAND=915000000
AT+ADDRESS?
+ADDRESS=0
AT+NETWORKID?
+NETWORKID=0
AT+CPIN?
+CPIN=00000000000000000000000000000000
AT+CRFOP?
+CRFOP=15
AT+SEND?
+SEND=0,8,FUCKfuck
AT+VER?
+VER=RYLR89C_V1.2.4
AT+UID?
+ERR=4
*/
/*
лог записан через termite(включен Append CR+LF)
В проге Terminal 1.9b нужно в конце добавлять $0D$0A (AT$0D$0A)
***послать HELLO с настройками по умолчанию :
AT+SEND=0,5,HELLO
должно вернутся;
+OK
***в терминале получателя должно появится 
+RCV=0,5,HELLO,-49,36

*/
#include <SoftwareSerial.h> 
#include <LiquidCrystal_I2C.h>
SoftwareSerial LORA(2, 3); // RX | TX 
LiquidCrystal_I2C lcd(0x27,16,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {// put your setup code here, to run once:
  //инициализация дисплея
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  
  // Давайте откроем последовательный порт со скоростью 9600
  Serial.begin(115200);
  Serial.println("LORA RYLR896"); 
  //Откроем компорт для модуля LORA
  LORA.begin(115200); //default baudrate of module is 115200
  delay(100);             //wait for Lora device to be ready

  LORA.print("AT\r\n");   //общаемся с молулем,посылаем команду AT
  delay(100);
  Serial.write(LORA.read());//посылаем в компорт то что ответил молуль

  //посылаем тестовое сообщение в эфир 
  LORA.print("AT+SEND=0,5,HELLO\r\n");   //send "HELLO" to address 0("5" bytes)

}//end setup

void loop() {// put your main code here, to run repeatedly:
  //то что пришло от лоры посылаем в компорт и наоборот.
  //то что пришло с компорт посылаем лоре. 
  if (LORA.available())
    Serial.write(LORA.read());
    //выводим на дисплей
     lcd.setCursor(0,0);   //1 Line(position,line)
  lcd.print("Lr");//16 characaters
      lcd.setCursor(6,0);   //1 Line(position,line)
  lcd.print("test lora");//16 characaters
  
  if (Serial.available())
    LORA.write(Serial.read());
  //выводим на дисплей
  lcd.setCursor(1,0);   //1 Line(position,line)
  lcd.println("Ct");//16 characaters
      lcd.setCursor(6,1);   //1 Line(position,line)
  lcd.println("test comp");//16 characaters
}
