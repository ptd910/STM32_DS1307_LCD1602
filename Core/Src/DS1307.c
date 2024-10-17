#include "DS1307.h"
static I2C_HandleTypeDef *i2c_config;
void I2C_Config(I2C_HandleTypeDef *i2c)
{
	i2c_config = i2c;
}
uint8_t B2D(uint8_t num)
{
	return ((num>>4)*10 + (num & 0x0F));
}
uint8_t D2B(uint8_t num)
{
	return (num / 10 ) << 4 | (num % 10);
}
void SET_TIME(DS1037_Time *setTime)
{
	uint8_t tempTime[7];
	tempTime[0] = D2B(setTime->sec);
	tempTime[1] = D2B(setTime->min);
	tempTime[2] = D2B(setTime->hour);
	tempTime[3] = D2B(setTime->day);
	tempTime[4] = D2B(setTime->date);
	tempTime[5] = D2B(setTime->month);
	tempTime[6] = D2B(setTime->year);
	
	HAL_I2C_Mem_Write(i2c_config,DS1307_ADDR, 0x00, 1, tempTime, sizeof(tempTime),1000);
}

void GET_TIME(DS1037_Time *getTime)
{
	uint8_t temptime[7];
	HAL_I2C_Mem_Read(i2c_config, DS1307_ADDR, 0x00, 1, temptime, sizeof(temptime),1000);
	getTime->sec = B2D(temptime[0]);
	getTime->min = B2D(temptime[1]);
	getTime->hour = B2D(temptime[2]);
	getTime->day = B2D(temptime[3]);
	getTime->date = B2D(temptime[4]);
	getTime->month = B2D(temptime[5]);
	getTime->year = B2D(temptime[6]);
}
