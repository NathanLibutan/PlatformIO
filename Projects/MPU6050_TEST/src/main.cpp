#include <MPU6050_tockn.h>
#include <Wire.h>

// put function declarations here:
int myFunction(int, int);

MPU6050 mpu6050(Wire);
long timer = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  mpu6050.update();

  if(millis() - timer > 5) {

    Serial.println("======================");
    Serial.print("temp : ");
    Serial.println(mpu6050.getTemp());

    //now gettin the accel values
    Serial.print("accX : "); Serial.print(mpu6050.getAccX());
    Serial.print("\taccY : "); Serial.print(mpu6050.getAccY());
    Serial.print("\taccZ : "); Serial.println(mpu6050.getAccZ());

    Serial.print("gyroX : "); Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : "); Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : "); Serial.println(mpu6050.getGyroZ());

    Serial.print("agnelX : "); Serial.print(mpu6050.getAngleX());
    Serial.print("\tagnelY : "); Serial.print(mpu6050.getAngleY());
    Serial.print("\tagnelZ : "); Serial.println(mpu6050.getAngleZ());
    Serial.println("=============");
    timer = millis();

  }







}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}