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

forwards();
delay(300);
stops();
leftTurn();
}
void forwards(){
rightMotor->setSpeed(500);
leftMotor->setSpeed(500);

rightMotor->run(BACKWARD);
leftMotor->run(BACKWARD);
}
void rightTurn(){
rightMotor->setSpeed(250);
leftMotor->setSpeed(0);

rightMotor->run(BACKWARD);
leftMotor->run(BACKWARD);
}
void leftTurn(){
rightMotor->setSpeed(0);
leftMotor->setSpeed(250);

rightMotor->run(BACKWARD);
leftMotor->run(BACKWARD);
}
void backwards(){
rightMotor->setSpeed(500);
leftMotor->setSpeed(500);

rightMotor->run(FORWARD);
leftMotor->run(FORWARD);
}
void stops(){
rightMotor->setSpeed(0);
leftMotor->setSpeed(0);

rightMotor->run(FORWARD);
leftMotor->run(FORWARD);
}