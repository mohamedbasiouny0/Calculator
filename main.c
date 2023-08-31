/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Mohamed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "dioo_int.h"
#include "LCD.h"
#include <util/delay.h>
#include "KEYBAD.h"

int main ()
{
	u8 key,i,key1;
	f32 num1,num2;
	i = 0;
	f32 flooat;
	HCLCD_vidInit();
	keybad_inti();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("WELCOME MOHAMED");
	_delay_ms(1500);
	HCLCD_vidClear();
	HCLCD_vidGoTo(0,0);
	HCLCD_vidSendString("***Calculator***");
	_delay_ms(1500);
	HCLCD_vidClear();
	while (1)
	{
		key = keybad_PressKey();
		if (key != NO_KEY)
		{
			if (key>='0' && key<='9' )
			{
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				i++;
				num1=num1*10+( key -'0');
			}
			if(key=='+')
			{
				num2=num1;
				num1=0;
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				key1=key;
				i++;
			}
			if(key=='-')
			{
				num2=num1;
				num1=0;
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				key1=key;
				i++;
			}
			if(key=='*')
			{
				num2=num1;
				num1=0;
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				key1=key;
				i++;
			}
			if(key=='/')
			{
				num2=num1;
				num1=0;
				HCLCD_vidGoTo(0,i);
				HCLCD_vidSendData(key);
				key1 = key;
				i++;
			}
			if (key =='=')
			{
				if (key1 =='+')
				{
					HCLCD_vidGoTo(0,i);
					HCLCD_vidSendData(key);
					HCLCD_vidSendNumber(num2+num1);
				}
				if (key1 =='-')
				{
					HCLCD_vidGoTo(0,i);
					HCLCD_vidSendData(key);
					HCLCD_vidSendNumber(num2-num1);
				}
				if (key1 =='*')
				{
					HCLCD_vidGoTo(0,i);
					HCLCD_vidSendData(key);
					HCLCD_vidSendNumber(num2*num1);
				}
				if (key1 =='/')
				{
					HCLCD_vidGoTo(0,i);
					HCLCD_vidSendData(key);
					flooat =num2/num1;
					HCLCD_vidSendFloat(flooat);
				}
			}
			if(key == 'n')
			{
				HCLCD_vidClear();
				num1 = 0;
				num2 = 0;
				i = 0;
			}
		}
	}
}
