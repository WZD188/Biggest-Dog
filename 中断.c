#include"stc12c5a60s2.h"

unsigned char code ledchar[]={
		0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
		0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e
	};
unsigned char ledbuff[6]={
	0xff,0xff,0xff,0xff,0xff,0xff
};

unsigned int cnt;
unsigned char flag1s = 0;
unsigned char i;
	
void main()
{
	unsigned long sec = 0;
	
	P11 = 0;
	TMOD = 0x01;
	TH0 = 0xf5;
	TL0 = 0x34;
	TR0 = 1;
	EA = 1;
	ET0 = 1;
	
	while(1)
	{
		if(flag1s == 1)
		{
			flag1s = 0;
			sec++;
			ledbuff[0] = ledchar[sec/1%10];
			ledbuff[1] = ledchar[sec/10%10];
			ledbuff[2] = ledchar[sec/100%10];
			ledbuff[3] = ledchar[sec/1000%10];
			ledbuff[4] = ledchar[sec/10000%10];
			ledbuff[5] = ledchar[sec/100000%10];
		}
	}	
}
void interrupttime0() interrupt 1
{
		TH0 = 0xf5;
		TL0 = 0x34;
		cnt++;
		if(cnt>=1000)
		{		
			cnt = 0;
			flag1s = 1;
		}
			P0=0xff;
			switch(i)
			{
				case 0:P22 = 0; P21 = 0; P20 = 0; i++; P0 = ledbuff[5];break;
				case 1:P22 = 0; P21 = 0; P20 = 1; i++; P0 = ledbuff[4];break;
				case 2:P22 = 0; P21 = 1; P20 = 0; i++; P0 = ledbuff[3];break;
				case 3:P22 = 0; P21 = 1; P20 = 1; i++; P0 = ledbuff[2];break;
				case 4:P22 = 1; P21 = 0; P20 = 0; i++; P0 = ledbuff[1];break;
				case 5:P22 = 1; P21 = 0; P20 = 1; i=0; P0 = ledbuff[0];break;
				default:break;
			}
}