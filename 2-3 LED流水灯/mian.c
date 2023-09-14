#include <STC89C5xRC.H>
#include <INTRINS.H>

void Delay1000ms(unsigned int s)	//@11.0592MHz
{
	while(s--)
	{
		unsigned char i, j, k;

		_nop_();
		i = 8;
		j = 1;
		k = 243;
		do
		{
			do
			{
				while (--k);
			} while (--j);
		} while (--i);
	}
}


void main()
{
	unsigned int i=0;
	while(1)
	{
		Delay1000ms(1);
		if(i==8)
			i=0;
		P2=0xFF&~(1<<i++);
	}
}