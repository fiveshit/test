void MC(int m,int v);
int D;
void setup()
{
	Serial.begin(9600);
  //3,5,6,9 是PWM腳位
	pinMode(3,OUTPUT);  
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);
	pinMode(9,OUTPUT);
}
void loop()
{
	switch(D)
	{
		case '0':  //前進
			MC(0,225);
			MC(1,225);
			break;
		case '1':  //左轉
			MC(0,100);
			MC(1,225);
			break;
		case '2':  //右轉
			MC(0,225);
			MC(1,100);
			break;
		case '3':  //後退
			MC(0,-225);
			MC(1,-225);
			break;
		case '4':  //停止
			MC(0,0);
			MC(1,0);
			break;
		default:
			break;
	}
}
void MC(int m,int v)
{
	if(m == 0)
	{
		if(v > 0)
		{
			analogWrite(6,v);
			analogWrite(9,0);
		}
		else
		{
			v = v*(-1);
			analogWrite(6,0);
			digitalWrite(9,v);
		}
	}
	if(m == 1)
	{
		if(v > 0)
		{
			analogWrite(3,v);
			analogWrite(5,0);
		}
		else
		{
			v = v*(-1);
			analogWrite(3,0);
			analogWrite(5,v);
		}

	}
}
