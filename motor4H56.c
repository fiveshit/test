#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#define a 22
//#define b 23
//#define c 24
//#define d 25
void phase_a(void);
void phase_b(void);
void phase_c(void);
void phase_d(void);
	int a = 22;
	int b = 23;
	int c = 24;
	int d = 25;
	int pins[4]={a ,b ,c ,d};
int main(void)
{	

	pinMode(a,OUTPUT);
	pinMode(b,OUTPUT);
	pinMode(c,OUTPUT);
	pinMode(d,OUTPUT);
	while(1)
	{
	phase_a();
	delayMicroseconds(200);
	phase_b();
	delayMicroseconds(200);
	phase_c();
	delayMicroseconds(200);
	phase_d();
	delayMicroseconds(200);
	}
	
}
void phase_a()
{
	digitalWrite(pins[0],LOW);
	digitalWrite(pins[1],HIGH);
	digitalWrite(pins[2],LOW);
	digitalWrite(pins[3],LOW);
}
void phase_b()
{
	digitalWrite(pins[0],LOW);
	digitalWrite(pins[1],LOW);
	digitalWrite(pins[2],HIGH);
	digitalWrite(pins[3],LOW);
}
void phase_c()
{
	digitalWrite(pins[0],HIGH);
	digitalWrite(pins[1],LOW);
	digitalWrite(pins[2],LOW);
	digitalWrite(pins[3],LOW);
}
void phase_d()
{
	digitalWrite(pins[0],LOW);
	digitalWrite(pins[1],LOW);
	digitalWrite(pins[2],LOW);
	digitalWrite(pins[3],HIGH);
}














