/*
Интерфейс I2C — последовательная асимметричная шина. 
I2C используется для подключения датчиков и периферийных устройств.
NodeMCU ESP8266 не имеет аппаратных выводов I2C, но интерфейс можно реализовать программно. 
Поддерживаются как I2C Master, так и I2C Slave. 
Обычно в качестве контактов I2C используются следующие выводы.
GPIO5: SCL
GPIO4: SDA
*/
/*
Формирует напряжение 1В 2В 3В.
*/
#include <Wire.h>
#include <Adafruit_MCP4725.h>
Adafruit_MCP4725 dac;

void setup(void) {
dac.begin(0x60); // This may vary between 0x60 and 0x65 or 0x63 for your board
}
void loop() {
// 1V Out from MC4725 -> 2V Out from LM358
dac.setVoltage(1241, false); // false meaning "do not write to EEPROM"
delay(2000);
// 2V Out from MC4725 -> 4V Out from LM358
dac.setVoltage(2482, false);
delay(2000);
// 3V Out from MC4725 -> 6V Out from LM358
dac.setVoltage(3723, false);
delay(2000);

}
