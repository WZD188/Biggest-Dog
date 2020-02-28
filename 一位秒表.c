#include"STC12C5A60S2.H"

unsigned char code ledchar[]={
		0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
		0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e
	};
	
void main()
{
	char cnt,sec;
	P20 = 0;
	P21 = 0;
	P22 = 0;
	P11 = 0;
	TMOD = 0X01;
	TH0 = 0X28;
	TL0 = 0X00;
	TR0 = 1;
	
	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0X28;
			TL0 = 0X00;
			cnt++;
			if(cnt>=50)
			{
				cnt = 0;
				P0 = ledchar[sec];
				sec++;
				if(sec >= 16)
				{
					sec = 0;
				}
			}
		}
	}
}