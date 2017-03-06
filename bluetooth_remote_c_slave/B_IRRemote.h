#ifndef __B_IRRemote__H__
#define __B_IRRemote__H__

#include <Arduino.h>
#define motorPinA  2
#define motorPinB  3
#define motorPinC  4
#define motorPinD  5
#define motorPinE  6
#define motorPinF  7
#define motorPinG  10
#define motorPinH  11
#define IR_rec_pin  2// IR 接收器輸出腳位
#define LED_pin  3   // IR_LED 輸出腳位
extern void motor_forward();
extern void motor_stop();
extern void right_motor_slow();
extern void left_motor_slow();
extern void right_motor_normal();
extern void left_motor_normal();

#endif
