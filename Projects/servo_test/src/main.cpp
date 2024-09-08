#include <Arduino.h>
#include <Stepper.h>

// put function declarations here:


const int stepsPerRevolution = 300;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // put your setup code here, to run once:
    myStepper.setSpeed(20);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Clock ");
  myStepper.step(stepsPerRevolution);
  delay(10);


}

