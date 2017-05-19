#include "particle_function.h"
int motor_rotato(int mode,int velocity)
{
    if(mode == 0)
    {
        if(velocity > 0)
        {
           analogWrite(motor0,velocity);
           digitalWrite(motor1,LOW);
        }
        else 
        {
          analogWrite(motor0,velocity);
          digitalWrite(motor1,HIGH);
               
        }
    }
    if(mode == 1)
    {
        if(velocity > 0)
        {
           analogWrite(motor2,velocity);
           digitalWrite(motor3,LOW);
        }
        else
        {
           analogWrite(motor2,velocity);
           digitalWrite(motor3,HIGH);
        }
    }
    
}
int motor_switch(int a)
{
    switch(a)
  {
      case 0: //往前
      motor_rotato(0,225);
      motor_rotato(1,-225);
      break;
      case 1: //右轉
      motor_rotato(0,1);
      motor_rotato(1,-225);
      break;
      case 2: //左轉  
      motor_rotato(0,225);
      motor_rotato(1,1);
      break;
      case 3: //往後
      motor_rotato(0,-225);
      motor_rotato(1,225);
      break;
      case 4: //停止
      motor_rotato(0,1);
      motor_rotato(1,1);
      break;
      default:
      break;    
  }
}
void IR_MARK(int irPin,long time)
{
    for(int i = 0 ; i < (time/PERIOD) ; i ++)
    {
    digitalWrite(irPin, HIGH);
    delayMicroseconds(ACTIVE_HIGH - 4); // digitalWrite() takes 4us
    digitalWrite(irPin, LOW);
    delayMicroseconds(ACTIVE_LOW - 4); // digitalWrite() takes 4us
    }
  
}
/*void all_mark_LED()
{
    int  ir_status1, ir_status2, ir_status3, ir_status4;
      motor_switch(4);
      for(int i=0 ; i<200 ; i++)
      {
          IR_MARK(irLed1,9000);
      delay(40);
          IR_MARK(irLed2,9000);
      delay(40); 
          IR_MARK(irLed3,9000);
      delay(40);
          IR_MARK(irLed4,9000);
      delay(40);
        ir_status1 = digitalRead(irReceiver1);
        ir_status2 = digitalRead(irReceiver2);
        ir_status3 = digitalRead(irReceiver3);
        ir_status4 = digitalRead(irReceiver4);
      if(ir_status1 == 0)
      int A = A + 1;
      else if(ir_status2 == 0)
      int B = B + 1;
      else if(ir_status3 == 0)
      int C = C + 1;
      else if(ir_status4 == 0)
      int D = D + 1;
      }
}*/
void all_ir()
{
      IR_MARK(irLed1,9000);
      delay(40);
      IR_MARK(irLed2,9000);
      delay(40); 
      IR_MARK(irLed3,9000);
      delay(40);
      IR_MARK(irLed4,9000);
      delay(40);
}
float Ultrasound()
{
    float Value_cm;
    for(int j = 1; j < 10 ; j++) 
        {
        delay(10);
        digitalWrite(TrigPin, LOW);
        delayMicroseconds(2);  
        digitalWrite(TrigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(TrigPin, LOW);
        Value_cm = float( pulseIn(EchoPin, HIGH) * 17 )/1000;
        }
   return Value_cm;
}



