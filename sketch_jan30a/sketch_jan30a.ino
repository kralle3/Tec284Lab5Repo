#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
void setup() {
  // put your setup code here, to run once:
AFMS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
rightMotor->setSpeed(100);
leftMotor->setSpeed(100);

rightMotor->run(BACKWARD);
leftMotor->run(BACKWARD);
}
