#include "B_IRRemote.h"
#include "variable.h"
#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial BT(8,9);
Cwin win1;
void setup( )
{
  Serial.begin(9600);   // 與電腦序列埠連線
  BT.begin(9600);
  Serial.println("BT is ready!");
  pinMode(motorPinA,OUTPUT);
  pinMode(motorPinB,OUTPUT);
  pinMode(motorPinC,OUTPUT);
  pinMode(motorPinD,OUTPUT);
  pinMode(motorPinE,OUTPUT);
  pinMode(motorPinF,OUTPUT);
  pinMode(motorPinG,OUTPUT); 
  pinMode(motorPinH,OUTPUT);
  pinMode(LED_pin,OUTPUT);
}
// 0:motor stop 1:motor forward 2:motor_right_turn 3:motor_left_turn 4:leave motor 5:emit signal 6:leave other_side_motor
void loop() 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
{
  if(BT.available()) 
  {
        win1.val = BT.read();
        if(win1.val == '5') 
        {
        Serial.println("motor_start");
        win1.val = Serial.read();
        win1.val = '1';
        BT.print(win1.val);
        delay(500);
        }
          
                          do
                          {
                            
                            switch(win1.val)
                            {
                                  case '1':
                                  do
                                  {
                                  motor_forward();
                                  Serial.println("motor_forward");
                                  win1.val = BT.read();
                                  }while(win1.val != '4');
                                  break;
                                  case '2':
                                  do
                                  {
                                  right_motor_slow();
                                  left_motor_normal();
                                  Serial.println("motor_left_turn");
                                  win1.val = BT.read();
                                  }while(win1.val != '4');
                                  break;
                                  case '3':
                                  do
                                  {
                                  right_motor_normal();
                                  left_motor_slow();
                                  Serial.println("motor_right_turn"); 
                                  win1.val = BT.read();
                                  }while(win1.val != '4');
                                  break;
                                  default:
                                  motor_stop();
                                  win1.val = BT.read();
                                  Serial.println("motor_stop");
                                  break;
                             } 
                             /*win1.val = BT.read();
                             if(win1.val == '4')
                             {
                              win1.val = BT.read();
                              win1.val = Serial.read();
                              win1.val = '2';  
                              BT.print(win1.val);
                              break;
                             }*/  
                          }while(win1.val != '4');
        
        
  }
}
