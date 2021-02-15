/*Автор-ССС   
Проверка управления машинки простыми командами с блютуза. 
Программа создана только для того чтоб проверить
правильност подклюяения моторов и проверить оборудование,
принятие команд с блютуза и тд...
Оборудование:
  Ардуино уно
  Модуль НС-06 или НС-05
  Драйвер моторов+моторы

***
Нужно добавить хож по поковым полуосям. 

*
HC05 - Bluetooth AT-Command mode  
modified on 10 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
*/ 
//L298N Драйвер двигателей
  const int motorA1  = 5;  // L298N'in IN3
  const int motorA2  = 6;  // L298N'in IN1
  const int motorB1  = 10; // L298N'in IN2
  const int motorB2  = 9;  // L298N'in IN4

int i=0; //Случайная переменная, назначенная циклам
  int j=0; //Случайная переменная, назначенная циклам
  int state; //Переменная сигнала от устройства Bluetooth
  int vSpeed=255;  // Стандартная скорость может принимать значение от 0-255

#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
int flag = 0; 
int LED = 13; 

void setup() //******************************************************
{   
// Давайте откроем последовательный порт со скоростью 9600
 Serial.begin(9600);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
 
//Софтварный компорт для блютуза
 MyBlue.begin(9600); 
//лед на плате Ардуино
 pinMode(LED, OUTPUT); 
// Давайте определим наши контакты
 pinMode(motorA1, OUTPUT);
 pinMode(motorA2, OUTPUT);
 pinMode(motorB1, OUTPUT);
 pinMode(motorB2, OUTPUT);    
} 

void loop() //******************************************************
{ 
 if (MyBlue.available()) 
   flag = MyBlue.read(); 

// 4 уровня скорости, которые можно регулировать из приложения.(Значения должны быть между 0-255)
    if (flag == '0'){
      vSpeed=0;}
    else if (flag == '1'){
      vSpeed=100;}
    else if (flag == '2'){
      vSpeed=180;}
    else if (flag == '3'){
      vSpeed=200;}
    else if (flag == '4'){
      vSpeed=255;}
   
 //ВПЕРЕД! Если входяшие данные 'F'- едем вперед
 if (flag == 'F') 
 { 
  //управление моторами
  analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
  analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0); 
  //выводим отладочную информацию
  digitalWrite(LED, HIGH);         //Управляем светодиодом. Он/ОФФ
  Serial.println("Едем Вперед");   //Пихаем данные в хардверный компорт 
  MyBlue.println("Едем Вперед");   //Пихаем данные в блютуз
 } 

//НАЗАД! Если входяшие данные 'B'- едем назад
 else if (flag == 'B') 
 { 
  //управление моторами
  analogWrite(motorA1, 0);  analogWrite(motorA2, vSpeed); 
  analogWrite(motorB1, 0);  analogWrite(motorB2, vSpeed);
  //выводим отладочную информацию
  digitalWrite(LED, LOW);      //Управляем светодиодом. Он/ОФФ
  Serial.println("Назад");     //Пихаем данные в хардверный компорт 
  MyBlue.println("Назад");     //Пихаем данные в блютуз
 }//end else IF
 
//STOP! Если входяшие данные 'S'- останавливаемся
 else if (flag == 'S') 
 { 
  //управление моторами
  analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
  analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
  //выводим отладочную информацию
  digitalWrite(LED, LOW);          //Управляем светодиодом. Он/ОФФ
  Serial.println("Остановка");     //Пихаем данные в хардверный компорт 
  MyBlue.println("Остановка");     //Пихаем данные в блютуз
 }//end else IF

/***************************Sol*****************************/
  //Если входящие данные 'L' автомобиль идет влево.
    else if (flag == 'L') {
      analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
  /***************************Sağ*****************************/
  //Если входящие данные 'R' автомобиль идет вправо
    else if (flag == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150);     
    }
 
}//end IF
