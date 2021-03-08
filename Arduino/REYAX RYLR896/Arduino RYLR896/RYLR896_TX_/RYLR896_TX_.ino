/*This Code is for the TRANSMITTER- но это еще не факт. 
возможно оба устройства будут передавать и принимать*/
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
SoftwareSerial LORA(2, 3); // RX | TX 

void setup() {
  // put your setup code here, to run once:
  // Давайте откроем последовательный порт со скоростью 9600
  Serial.begin(115200);
  Serial.println("LORA RYLR896"); 
  //Откроем компорт для модуля LORA
  LORA.begin(115200); //default baudrate of module is 115200
  delay(100);             //wait for Lora device to be ready

  LORA.print("AT\r\n");
  delay(100);
  Serial.write(LORA.read());

  LORA.print("AT\r\n");
  delay(100);
  Serial.write(LORA.read());

  LORA.print("AT\r\n");
  delay(100);
  Serial.write(LORA.read());
 
}//end setup

void loop() {
if (LORA.available())
    Serial.write(LORA.read());
  if (Serial.available())
    LORA.write(Serial.read());
   
}
