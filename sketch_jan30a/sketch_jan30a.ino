#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *rightMotor = AFMS.getMotor(4);
Adafruit_DCMotor *leftMotor = AFMS.getMotor(3);
long duration, distance;

void setup() {
  // put your setup code here, to run once:
AFMS.begin();
pinMode(7, OUTPUT);
pinMode(8, INPUT);
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:

distanceTest();
if (distance > 30){
  backwards();
}
else if (distance < 30) {
  forwards();
}
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

long distanceTest() {
digitalWrite(7, LOW);
delayMicroseconds(2);
digitalWrite(7, HIGH);
delayMicroseconds(10);
digitalWrite(7, LOW);
duration = pulseIn(8, HIGH);
distance = (duration/2) / 29.1;
Serial.print(distance);
return distance;
}
