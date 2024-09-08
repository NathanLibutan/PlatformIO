#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11



DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.println("Work");
  Serial.println("DHT11 SENSOR TEST");

  pinMode(LED_BUILTIN, OUTPUT);

  dht.begin();
  Serial.begin(9600);

}

void loop() {
  delay(1000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("Humidity: ");
  Serial.println(humidity);

  Serial.println("Temp");
  Serial.println(temperature);

}
