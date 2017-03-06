#include "B_IRRemote.h"
#include <Arduino.h>
void motor_forward()
{
  digitalWrite(motorPinA,LOW);   //left
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,HIGH);
  digitalWrite(motorPinE,HIGH);   //right
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,HIGH);
  digitalWrite(motorPinD,LOW);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,HIGH);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,HIGH);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,HIGH);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinA,HIGH);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,HIGH);
  delay(10);
}

void motor_stop()
{
   digitalWrite(motorPinA,LOW);
   digitalWrite(motorPinB,LOW);
   digitalWrite(motorPinC,LOW);
   digitalWrite(motorPinD,LOW);
   digitalWrite(motorPinE,LOW);
   digitalWrite(motorPinF,LOW);
   digitalWrite(motorPinG,LOW);
   digitalWrite(motorPinH,LOW);
   delay(1);
}
void right_motor_slow()
{
  digitalWrite(motorPinE,HIGH);   
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,HIGH);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,HIGH);
  digitalWrite(motorPinH,LOW);
  delay(10);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,HIGH);
  delay(10);
}
void left_motor_slow()
{ 
  digitalWrite(motorPinA,HIGH);   
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  delay(10);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,HIGH);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  delay(10);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,HIGH);
  delay(10);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,HIGH);
  delay(10);
}
void right_motor_normal()
{
  digitalWrite(motorPinE,HIGH);   //right
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(1);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,HIGH);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,LOW);
  delay(1);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,HIGH);
  digitalWrite(motorPinH,LOW);
  delay(1);
  digitalWrite(motorPinE,LOW);
  digitalWrite(motorPinF,LOW);
  digitalWrite(motorPinG,LOW);
  digitalWrite(motorPinH,HIGH);
  delay(1);
}
void left_motor_normal()
{
  digitalWrite(motorPinA,HIGH);   //left
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  delay(1);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,HIGH);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,LOW);
  delay(1);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,HIGH);
  digitalWrite(motorPinD,LOW);
  delay(1);
  digitalWrite(motorPinA,LOW);
  digitalWrite(motorPinB,LOW);
  digitalWrite(motorPinC,LOW);
  digitalWrite(motorPinD,HIGH);
  delay(1);
}