#ifndef __particle_function__H__
#define __particle_function__H__
#include <Arduino.h>
//數位腳位 3~6 紅外線接收腳
#define irReceiver1 A0
#define irReceiver2 A1
#define irReceiver3 A2
#define irReceiver4 A3
//超音波腳位
#define TrigPin A4
#define EchoPin A5
//數位腳位 9~12 紅外線發射腳
#define irLed1 6
#define irLed2 9  
#define irLed3 10
#define irLed4 11
//類比腳位 A0~A3 馬達
#define motor0 3  //pwm
#define motor1 2  
#define motor2 5  //pwm
#define motor3 4  
#define DUTY_CYCLE         1/3       // duty cycle
#define PERIOD             26        // Carrier Frequency @38kHz, 1/38kHz =~ 26us
#define ACTIVE_HIGH       (PERIOD * DUTY_CYCLE)
#define ACTIVE_LOW        (PERIOD - (PERIOD * DUTY_CYCLE))
extern int motor_rotato(int,int);
extern int motor_switch(int);
extern void IR_MARK(int,long  time);
//extern void all_mark_LED();
extern void all_ir();
extern float Ultrasound();
#endif
