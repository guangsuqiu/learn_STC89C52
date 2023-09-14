

void DelayMs(unsigned char ms)		//@12.000MHz
{
	while(ms--)
	{
		unsigned char i, j;

		i = 16;
		j = 147;
		do
		{
			while (--j);
		} while (--i);
	}
}