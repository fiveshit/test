 #include <SoftwareSerial.h>
 #include <string.h>
#include <Arduino.h>
#include "particle_function.h"
#include "variable.h"
SoftwareSerial BT(7,8);
Cwin c;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin(115200);
  pinMode(motor0,OUTPUT);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(irReceiver1,INPUT);
  pinMode(irReceiver2,INPUT);
  pinMode(irReceiver3,INPUT);
  pinMode(irReceiver4,INPUT);
  pinMode(irLed1,OUTPUT);
  pinMode(irLed2,OUTPUT);
  pinMode(irLed3,OUTPUT);
  pinMode(irLed4,OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
/* for(int thisPin = 0 ; thisPin < cwin1.irPinCount ; thisPin++)
 {
    pinMode(cwin1.irLedPins[thisPin],OUTPUT);
 }*/
}

void loop() {
  if (Serial.available())
  {
    c.chr = Serial.read(); // Read from Serial Monitor
    BT.print(c.chr);    // Write command or data to Bluetooth
  }

  if (BT.available()) // when receive data
  { 
    /*if(ones == 1)
    {
         c.Value_cm = Ultrasound();
         Serial.print(c.Value_cm);
        ones = 2;
    }*/
    c.chr = BT.read(); // Read from Bluetooth
    switch(c.chr)
    {
        case 'a':
          c.Value_cm = Ultrasound();
          BT.print(c.Value_cm);
          break;
        case 'b':
        while(1)
            { 
              if(BT.available())
              {
              c.chr = BT.read();
              c.path[c.j] = c.chr;
              Serial.print(c.path[c.j]);
              c.j++;
              if(c.chr == 'c')
              {
                 for(c.index; c.index < c.j - 1 ; c.index ++)
                   {
                     /*for(int j = 0; j < c.j ; j++)
                     {
                      Serial.print(c.path[j]);
                     }*/
                    if(c.path[c.index] == '0')
                    {
                      motor_switch(0);
                      delay(2000);
                      Serial.print("AA");
                    }
                    else if(c.path[c.index] == '1')
                    {
                      motor_switch(3);
                      delay(2000);
                      Serial.print("BB");
                    }
                    else if(c.path[c.index] == '2')
                    {
                      motor_switch(1);
                      delay(1000);
                      motor_switch(0);
                      delay(2000);
                      Serial.print("CC");
                    }
                    else if(c.path[c.index] == '3')
                    {
                      motor_switch(2);
                      delay(1000);
                      motor_switch(0);
                      delay(2000);
                      Serial.print("DD");
                    }
                   }
                 
                 } 
              } 
            }
           break;
      
    }
    /*}
    if(c.chr == 'a')
    {
      c.Value_cm = Ultrasound();
      BT.print(c.Value_cm); 
    }
    else if(c.chr == 'b')
    {
        for(int index = 0 ; index < c.j ; index ++)
        {
            Serial.print('x');
            delay(100);
            if(c.path[index] == '0')
            {
              motor_switch(0);
              delay(2000);
              Serial.print("AA");
            }
            else if(c.path[index] == '1')
            {
              motor_switch(3);
              delay(3000);
              Serial.print("BB");
            }
            else if(c.path[index] == '2')
            {
              motor_switch(1);
              delay(1000);
              motor_switch(0);
              delay(3000);
              Serial.print("CC");
            }
            else if(c.path[index] == '3')
            {
              motor_switch(2);
              delay(1000);
              motor_switch(0);
              delay(3000);
              Serial.print("DD");
            }
            
            
            /*Serial.print(c.path[index]);
             switch(c.path[index])
            {
            case '0':
              motor_switch(0);
              delay(3000);
              Serial.print("AA");
              break;
            case '1':
              motor_switch(3);
              delay(3000);
              Serial.print("BB");
              break;
            case '2':
              motor_switch(1);
              delay(1000);
              motor_switch(0);
              delay(3000);
              Serial.print("CC");
              break;
            case '3':
              motor_switch(2);
              delay(1000);
              motor_switch(0);
              delay(3000);
              Serial.print("DD");
              break;
            default:
              Serial.print("EE");
              break;
            } 
        }*/

        
    }
}
