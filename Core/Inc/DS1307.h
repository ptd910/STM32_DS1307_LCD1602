#ifndef _DS1307_H_
#define _DS1307_H_

#include "stm32f1xx_hal.h"
#define DS1307_ADDR (0x68 << 1)

typedef struct
{
	uint8_t sec;
	uint8_t min;
	uint8_t hour;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}DS1037_Time;
void I2C_Config(I2C_HandleTypeDef *i2c);
uint8_t B2D(uint8_t num);
uint8_t D2B(uint8_t num);
void SET_TIME(DS1037_Time *setTime);
void GET_TIME(DS1037_Time *getTime);
#endif /*_DS1307_H_*/
