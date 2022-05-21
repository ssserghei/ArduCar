

#include <SoftwareSerial.h>

SoftwareSerial swSer(4, 5); //Define hardware connections

void setup() {
  Serial.begin(57600);   //Initialize hardware serial with baudrate of 115200
  swSer.begin(9600);    //Initialize software serial with baudrate of 115200

  Serial.println("\nSoftware serial test started");
}

void loop() {
  while (swSer.available() > 0) {  //wait for data at software serial
    Serial.write(swSer.read()); //Send data recived from software serial to hardware serial    
  }
  while (Serial.available() > 0) { //wait for data at hardware serial
    swSer.write(Serial.read());     //send data recived from hardware serial to software serial
  }

}
