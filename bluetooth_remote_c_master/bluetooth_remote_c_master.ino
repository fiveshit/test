#include "B_IRRemote.h"
#include "variable.h"
#include <IRremote.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial BT(8,9);
Cwin win1,win2;
IRrecv IRrecver(IR_rec_pin);// IRremote 函式庫接收用對象
decode_results results;// 解碼結果存放資料用
void Print_IRdecodeResult( decode_results &decodeResults )//印出解碼成功的訊息以便觀察
{
 if( decodeResults.decode_type == NEC )
 {
  if( decodeResults.value == 0x00FFE21D ) // CH+ buttom
  {
   digitalWrite(LED_pin,HIGH);     
   win1.x = 1;
   win1.val = Serial.read();
   win1.val = '5';
   BT.print(win1.val);
  }
  
  if(decodeResults.value == 0x00FFA25D)// CH- buttom
  {
  digitalWrite(LED_pin,HIGH);
  win2.x = 2;
  win2.val = Serial.read();
  win2.val = '5';
  BT.print(win2.val);
  }
 }
 }
 
void setup( )
{
 IRrecver.enableIRIn( );// 初始化接收對象
  Serial.begin(9600);
  BT.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  pinMode(motorPinA,OUTPUT);
  pinMode(motorPinB,OUTPUT);
  pinMode(motorPinC,OUTPUT);
  pinMode(motorPinD,OUTPUT);
  pinMode(motorPinE,OUTPUT);
  pinMode(motorPinF,OUTPUT);
  pinMode(motorPinG,OUTPUT); 
  pinMode(motorPinH,OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  win1.mode = 1;
  win1.other_side = 1;
  win2.mode = 1;
  win2.other_side = 1;
}
//  1:motor forward 2:motor_left_turn 3:motor_right_turn 4:leave motor 5:emit signal 6:leave other_side_motor
void loop()
{
  if(IRrecver.decode( &results ))
  {
  Print_IRdecodeResult( results );  
 if(win1.x == 1)
 {
  while(1)
  {
    if(win1.other_side == !win1.mode)
   {
    Serial.println("Hello4");
    win1.val = Serial.read();
    win1.val = '2';          //命令尾隨車左轉
    BT.print(win1.val);
    delay(27000);            //27s
    win1.val = '4';          //命令尾隨車停止
    BT.print(win1.val);
    delay(100);
    win1.val = '5';          //雙方前進
    BT.print(win1.val);
    win1.other_side = !win1.mode;
   }
   
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if(BT.available()) {
   // win1.other_side = win1.mode;
    win1.val = BT.read();
    Serial.println(win1.val);
                          while(1)
                          {
                            switch(win1.val)
                            {   
                                  case '0':
                                  motor_stop();
                                  Serial.println("motor_stop");
                                  break;
                                  case '1':
                                  do
                                  {
                                  //Serial.println("motor_forward");
                                  digitalWrite(TrigPin, LOW); //低高低電平發一個短時間脈波去TrigPin
                                  delayMicroseconds(2);
                                  digitalWrite(TrigPin, HIGH);
                                  delayMicroseconds(10);
                                  digitalWrite(TrigPin, LOW);
                                  win1.Value_cm = float( pulseIn(EchoPin, HIGH) * 17 )/1000; //將脈波來回訊號轉成cm
                                  Serial.print(win1.Value_cm);
                                  Serial.println("cm");
                                  motor_forward();
                                  win1.val = BT.read();
                                  }while(win1.Value_cm >= 10);
                                  break;
                                  case '2':
                                  do
                                  {
                                  right_motor_slow();
                                  left_motor_normal();
                                  Serial.println("motor_left_turn");
                                  win1.val = BT.read();
                                  }while(win1.val != '0');
                                  break;
                                  case '3':
                                  do
                                  {
                                  right_motor_normal();
                                  left_motor_slow();
                                  Serial.println("motor_right_turn");
                                  win1.val = BT.read();
                                  }while(win1.val != '0');
                                  break;
                                  default:
                                  win1.val = BT.read();
                                  break;
                             }
                             if(win1.Value_cm < 10)
                             {
                              Serial.println("0000000");
                              win1.val = Serial.read();
                              win1.val = '4';
                              BT.print(win1.val);
                              win1.other_side = !win1.mode;
                               break;
                             }
                           
                             
                          }
                    }
    IRrecver.resume( );// 解碼完需要呼叫這一行，才能再繼續接收後續資料
   }
  }
  if(win2.x == 2)
  {
     while(1)
  {
    if(win2.val == '2')
    {
       win2.val = Serial.read();
       win2.val = '1';          //命令尾隨車前進
       BT.print(win2.val);
      // delay(15000)
       for(int k=1;k<450;k++)
       {
        motor_forward();
        Serial.println("motor_forward");
       }
       delay(100);
    }
    
    if(win2.other_side == !win2.mode)
   {
    /*Serial.println("Hello4");
    win2.val = Serial.read();
    win2.val = '1';          //命令尾隨車前進
    BT.print(win2.val);
    delay(15000);*/
    win2.val = Serial.read();
    win2.val = '4';          //命令尾隨車停止
    BT.print(win2.val);
    Serial.println("Hello5");
    delay(1000);
    //win2.val = Serial.read();
    win2.val = '2';          //命令尾隨車左轉
    BT.print(win2.val);
    Serial.println("Hello6");
    delay(25000);
    //win2.val = Serial.read();
    win2.val = '4';          //命令尾隨車停止
    BT.print(win2.val);
    Serial.println("Hello7");
    delay(10);
    //win2.val = Serial.read();
    win2.val = '5';          //雙方前進
    BT.print(win2.val);
    Serial.println("Hello8");
    win2.other_side = win2.mode;
   }
 
 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if(BT.available()) {
    //win2.other_side = win2.mode;
    win2.val = BT.read();
    Serial.println(win2.val);
    Serial.println("motor_start");
                          for(int i=1;i<3;i++)
                          {
                            switch(win2.val)
                            {   
                                  case '0':
                                  motor_stop();
                                  Serial.println("motor_stop");
                                  break;
                                  case '1':
                                  do
                                  {
                                  //Serial.println("motor_forward");
                                  digitalWrite(TrigPin, LOW); 
                                  delayMicroseconds(2);
                                  digitalWrite(TrigPin, HIGH);
                                  delayMicroseconds(10);
                                  digitalWrite(TrigPin, LOW);
                                  win2.Value_cm = float( pulseIn(EchoPin, HIGH) * 17 )/1000; //將回波算成時間
                                  Serial.print(win2.Value_cm);
                                  Serial.println("cm");
                                  motor_forward();
                                  win2.val = BT.read();
                                  }while(win2.Value_cm >= 10);
                                  break;
                                  case '2': 
                                  for(int j=1;j<700;j++)
                                  {
                                  right_motor_slow();
                                  left_motor_normal();
                                  Serial.println("motor_left_turn");
                                  win2.val = BT.read();
                                  }
                                  win2.val = Serial.read();
                                  win2.val = '4';
                                  BT.print(win2.val);
                                  break;
                                  case '3':
                                  for(int k=1;k<700;k++)
                                  {
                                  right_motor_normal();
                                  left_motor_slow();
                                  Serial.println("motor_right_turn");
                                  win2.val = BT.read();
                                  }
                                  win2.val = Serial.read();
                                  win2.val = '4';
                                  BT.print(win2.val);
                                  break;
                                  default:
                                  win2.val = BT.read();
                                  break;
                             }
                             if(win2.Value_cm < 10)
                             {
                              Serial.println("0000000");
                              win2.val = Serial.read();
                              win2.val = '4';
                              BT.print(win2.val);
                              win2.val = '2';
                             }
                             if(i == 2)
                             {
                              win2.val = '2';
                              Serial.println("111");
                              win2.other_side = !win2.mode;
                             }
                           
                             
                          }
                    }
    IRrecver.resume( );// 解碼完需要呼叫這一行，才能再繼續接收後續資料
   }
    //  IRrecver.resume( );// 解碼完需要呼叫這一行，才能再繼續接收後續資料
  }
 }
}
