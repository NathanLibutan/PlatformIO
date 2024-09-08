#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11



float cel_to_fah(float cel){
  float fah = (cel * (9.0/5.0)) + 32 - 3;

  return fah;
}

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);

  Serial.println("Work");
  Serial.println("DHT11 SENSOR TEST");

  pinMode(LED_BUILTIN, OUTPUT);

  dht.begin();

}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();


  if ((isnan(humidity) || isnan(temperature) == true )){
    Serial.println("nan ouput");
  }

  else {


  Serial.print("Humidity: ");
  
  Serial.println(humidity);
  Serial.println("\n");

  Serial.print("Temp: ");
  Serial.println(temperature);
  Serial.println(cel_to_fah(temperature));

  Serial.println("\n");

  }


}
