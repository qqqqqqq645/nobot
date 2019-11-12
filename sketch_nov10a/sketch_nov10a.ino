/*
 제목   : 온습도 센서로 실내 온도와 습도 학인하기
 내용   : DHT11 온습도 센서를 사용하여 실내 온도와 습도를 측정하고 I2C_LCD 에 표시해봅니다
 */
 
// DHT11 센서를 쉽게 제어하기 위한 라이브러리를 추가해줍니다.
#include "DHT.h"
// I2C LCD를 쉽게 제어하기 위한 라이브러리를 추가해줍니다.

 
// 온습도 센서를 디지털 2번 핀에 연결합니다.
#define DHTPIN 2
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
 

 
void setup() {
  Serial.begin(9600);
  dht.begin();

}
 
void loop() {
  // 습도와 온도값을 측정하고, 제대로 측정되었는지 확인해줍니다.
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
 
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  // 온도와 습도값을 시리얼 모니터에 출력해 줍니다.
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
 
  // LCD에 출력할 습도 메세지를 만듭니다.
  String humi = "Humi : ";
  humi += (String)humidity;
  humi += "%";
 
  // LCD에 출력할 온도 메세지를 만듭니다.
  String temp = "temp : ";
  temp += (String)temperature;
  temp += "C";
 
  // 첫번째 줄, 첫번째 칸부터 "Humi = 000%" 를 출력해 줍니다.

 

 
  delay(1500);
}
