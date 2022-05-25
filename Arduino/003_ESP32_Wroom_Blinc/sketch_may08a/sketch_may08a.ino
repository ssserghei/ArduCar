#define DAC1 25
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  int value = 255; // 255= 3.3V, 128=1.65V
  
  dacWrite(DAC1, value);
  delay(1000);
}
