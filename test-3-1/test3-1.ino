// the setup function runs once when you press reset or power the board
// 定义LED和传感器引脚

#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11 
int frequent;
int ledPin=9;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("组号:40!"));
  dht.begin(); 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(2000);  
  // 读取温度传感器数值
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F(";"));
  // 映射传感器数值到呼吸频率范围
  frequent = map(t, 0.0, 50.0, 0.0, 1000.0);
  Serial.print(F("frequent: "));
  Serial.print(frequent);
  Serial.print(F(";\n"));
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(frequent);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(frequent);  

}