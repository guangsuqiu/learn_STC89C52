
#include "LCD1602.h"
#include "MatrixKey.h"

#define PASSWORD 0x1234

unsigned char MatrixKeyNum;
unsigned int  password;
unsigned char cnt;

int main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowString(2,1,"_");
	while (1)
	{
		MatrixKeyNum=MatrixKey();
		if(MatrixKeyNum)
		{
			LCD_ShowString(1,1,"Password:        ");
			if (MatrixKeyNum==1||MatrixKeyNum==2||MatrixKeyNum==3||
			MatrixKeyNum==5||MatrixKeyNum==6||MatrixKeyNum==7||
			MatrixKeyNum==9||MatrixKeyNum==10||MatrixKeyNum==11
			||MatrixKeyNum==14)
			{
				cnt++;
				if(cnt==5)
				{
					cnt--;
					continue;
				}

				if(MatrixKeyNum>3&&MatrixKeyNum<8)
				{
					MatrixKeyNum-=1;
				}
				else if(MatrixKeyNum>8&&MatrixKeyNum<12)
				{
					MatrixKeyNum-=2;
				}
				else if(MatrixKeyNum==14)
				{
					MatrixKeyNum=0;
				}
				password|=MatrixKeyNum<<((4-cnt)*4);
				
				LCD_ShowHexNum(2,9,password,4); // 显式密码
		
				LCD_ShowString(2,cnt,"*");
				if(cnt+1!=5)
				{
					LCD_ShowString(2,cnt+1,"_");
				}
			}
			else if(MatrixKeyNum==13)	// 删除
			{
				if (cnt==0)	// 没有数据，不用删除
				{
				}
				else
				{
					password&=~(0xF<<(4-cnt)*4);	// int/short 都是16bit
					LCD_ShowString(2,cnt,"_ ");
					cnt--;
					LCD_ShowHexNum(2,9,password,4); // 显式密码
				}
				
				
			}
			else if(MatrixKeyNum==15)	// 确定
			{
				if (cnt!=4||PASSWORD!=password)	// 密码不对
				{
					LCD_ShowString(1,14,"ERR");
					cnt=0;
					LCD_ShowString(2,cnt,"_   ");
					password=0x0000;
					LCD_ShowHexNum(2,9,password,4); // 显式密码
				}
				else	// 密码正确
				{	
					LCD_ShowString(1,14,"OK!");
				}
				
			}
			else	// 不做处理
			{
				
			}
			
		}
	}
	return 0;
}