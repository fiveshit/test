#ifndef __B_IRRemote__H__
#define __B_IRRemote__H__

#include <Arduino.h>
#define motorPinA  4
#define motorPinB  5
#define motorPinC  6
#define motorPinD  7
#define motorPinE  10
#define motorPinF  11
#define motorPinG  12
#define motorPinH  13
#define TrigPin A0
#define EchoPin A1
#define IR_rec_pin  2// IR 接收器輸出腳位
#define LED_pin  3   // IR_LED 輸出腳位
extern void motor_forward();
extern void motor_stop();
extern void right_motor_slow();
extern void left_motor_slow();
extern void right_motor_normal();
extern void left_motor_normal();

#endif
