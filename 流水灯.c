#include"STC12C5A60S2.H"

void main()
{
	long i;
	char cnt;
	P20 = 0;	//×Ü¿ª¹Ø
	P21 = 1;	//make LEDS6=0
	P22 = 1;
	P11 = 0;
	while(1)
	{
	P0 = ~(0x01 << cnt);	
	i=50000;while(i--);	//late
	cnt++;
	if(cnt >=8)	//reset
	{
		cnt = 0;
	}
	}
}