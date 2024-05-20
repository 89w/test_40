// the setup function runs once when you press reset or power the board
// 定义LED和传感器引脚

#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11 
// 定义温度相关变量
int ledPin=9;
int breatheTime; // 呼吸周期
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println(F("组号:40!"));
  dht.begin(); 
  pinMode(ledPin,OUTPUT);
}

void loop() {
  delay(2000);  
  // 读取温度传感器数值
 // int sensorValue = analogRead(sensorPin);
    float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F(";"));
  // 映射传感器数值到呼吸频率范围
  breatheTime = map(t, 0.0, 50.0, 50.0, 0.0);
  Serial.print(F("breatheTime: "));
  Serial.print(breatheTime);
   Serial.print(F(";\n"));
  // LED呼吸效果
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(breatheTime);
  }

  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(breatheTime);
  }
}