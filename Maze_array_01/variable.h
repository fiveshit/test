#include "particle_function.h"
class Cwin
{
       public:
       // 紅外線發射頻率
       // const unsigned int frequency = 38000;
       char turn ;
       //紅外線接收狀態
       int ir_status1;
       int ir_status2;
       int ir_status3;
       int ir_status4;
       int all_statust;
       char chr;
       int index = 0;
       char path[10];
       int j = 0;
       float Value_cm;
       //int irLedPins[4] = {9,10,11,12};
       //int irPinCount = 4;
       //int A,B,C,D;
       //unsigned long time = millis();
};
