#include"STC12C5A60S2.H"

void main()
{
	char cnt;
	P20 = 0;
	P21 = 1;
	P22 = 1;
	P11 = 0;
	TMOD = 0X01;	//made timer0 = mode1
	TH0 = 0X28;		
	TL0 = 0X00;		//time = 20ms
	TR0 = 1;
	
	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;		//reset TF0
			TH0 = 0X28;
			TL0 = 0X00;
			cnt++;
			if(cnt>=50) //time = 1s
			{
				cnt = 0;
				P0 = ~P0; //open or close all LED
			}
		}
	}
}