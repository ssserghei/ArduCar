#include <Wire.h>
#include <Adafruit_INA219.h> // You will need to download this library


Adafruit_INA219 sensor219; // Declare and instance of INA219

void setup(void) 
{
  Wire.begin(21, 22); //define which pins used for i2c
  Serial.begin(115200);    
  sensor219.begin();
  
}

void loop(void) 
{
  float busVoltage = 0;
  float current = 0; // Measure in milli amps
  float power = 0;

  busVoltage = sensor219.getBusVoltage_V();
  current = sensor219.getCurrent_mA();
  power = busVoltage * (current/1000); // Calculate the Power
  
  
  Serial.print("Bus Voltage:   "); 
  Serial.print(busVoltage); 
  Serial.println(" V");  
  
  Serial.print("Current:       "); 
  Serial.print(current); 
  Serial.println(" mA");
  
  Serial.print("Power:         "); 
  Serial.print(power); 
  Serial.println(" W");  
  
  Serial.println("");  

   Serial.println(busVoltage, current, power);


  delay(2000);
}?
