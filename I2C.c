//#include "I2C.h"
//
//#define I2C_PORT I2C1
//#define I2C_SCL_PIN GPIO_PIN_8
//#define I2C_SCL_PORT GPIOB
//#define I2C_SDA_PIN GPIO_PIN_9
//#define I2C_SDA_PORT GPIOB
//
//#define BH1750_L_ADDRESS_WRITE 0b0100011
//
//#define BH1750_H_ADDRESS_WRITE 0b1011100
//
//#define BH1750_ADDRESS_WRITE (BH1750_H_ADDRESS_WRITE<<1)
//#define BH1750_ADDRESS_READ  (BH1750_ADDRESS_WRITE+1)
//
//#define BH1750_COMMAND_POWERON  0b00000001
//#define BH1750_COMMAND_CONRES   0b00010011
//
//
//
//void I2C_Init(){
//	__GPIOB_CLK_ENABLE();
//
//	GPIO_InitTypeDef initSrtuct;
//
////
//	initSrtuct.Alternate = 0;
//	initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
//	initSrtuct.Pin = LED_RED | LED_GREEN | LED_BLUE;
//	initSrtuct.Speed = GPIO_SPEED_HIGH;
//	HAL_GPIO_Init(LED_PORT, &initSrtuct);
//
//
//	initSrtuct.Alternate = GPIO_AF4_I2C1;
//	initSrtuct.Mode = GPIO_MODE_AF_OD;
//	initSrtuct.Pull = GPIO_PULLUP;
//	initSrtuct.Pin = I2C_SCL_PIN;
//	initSrtuct.Speed = GPIO_SPEED_HIGH;
//	HAL_GPIO_Init(I2C_SCL_PORT, &initSrtuct);
//
//	initSrtuct.Alternate = GPIO_AF4_I2C1;
//	initSrtuct.Mode = GPIO_MODE_AF_OD;
//	initSrtuct.Pull = GPIO_PULLUP;
//	initSrtuct.Pin = I2C_SDA_PIN;
//	initSrtuct.Speed = GPIO_SPEED_HIGH;
//	HAL_GPIO_Init(I2C_SDA_PORT, &initSrtuct);
//
//
//
//	__I2C1_CLK_ENABLE();
//	I2C_HandleTypeDef initS;
//	initS.Instance = I2C_PORT;
//	initS.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//	initS.Init.ClockSpeed = 10000;
//	initS.Init.DualAddressMode = 0;
//	initS.Init.GeneralCallMode = 0;
//	initS.Init.NoStretchMode = 0;
//	HAL_I2C_Init(&initS);
//
////	I2C_PORT->CR2 |= I2C_CR2_ITEVTEN;
////	I2C_PORT->CR2 |= I2C_CR2_ITBUFEN;
////	I2C_PORT->CR2 |= I2C_CR2_FREQ_1;
//
////	NVIC_EnableIRQ(I2C1_EV_IRQn);
////	NVIC_EnableIRQ(I2C1_ER_IRQn);
//
//	I2C_PORT->CR1 |= I2C_CR1_PE;
//	I2C_PORT->CR1 |= I2C_CR1_ACK;
//}
//
//
//
//void i2c_write_byte(char address, char value){
//	I2C_PORT->CR1 |= I2C_CR1_START;
//	while((I2C_PORT->SR1 & I2C_SR1_SB) == 0);
//	int x = I2C_PORT->SR1;
//	I2C_PORT->DR = address;
//	while((I2C_PORT->SR1 &  I2C_SR1_ADDR) == 0){
//			if ((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//				I2C_PORT->CR1 |= I2C_CR1_STOP;
//				return;
//			}
//	}
//	x = I2C_PORT->SR1;
//	x = I2C_PORT->SR2;
//	I2C_PORT->DR = value;
//	while((I2C_PORT->SR1 &  I2C_SR1_TXE) == 0);
//	I2C_PORT->CR1 |= I2C_CR1_STOP;
//}
//
//int i2c_read_2byte(char address){
//	I2C_PORT->CR1 |= I2C_CR1_START;
//	while((I2C_PORT->SR1 &  I2C_SR1_SB) == 0);
//	int x = I2C_PORT->SR1;
//	I2C_PORT->DR = address;
//	while((I2C_PORT->SR1 &  I2C_SR1_ADDR) == 0)
//	{
//		if ((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//			I2C_PORT->CR1 |= I2C_CR1_STOP;
//			return 0;
//		}
//	}
//	I2C_PORT->SR1;
//	I2C_PORT->SR2;
//	while((I2C_PORT->SR1 &  I2C_SR1_RXNE) == 0);
//	int tmp = I2C_PORT->DR;
//	tmp = tmp<<8;
//
//	while((I2C_PORT->SR1 &  I2C_SR1_RXNE) == 0);
//	tmp |= I2C_PORT->DR;
//	I2C_PORT->CR1 |= I2C_CR1_STOP;
//	return tmp;
//}
//
//
//void i2c_write_reg(char reg, char value){
//	I2C_PORT->CR1 |= I2C_CR1_START;
//	while((I2C_PORT->SR1 &  I2C_SR1_SB) == 0);
//	int x = I2C_PORT->SR1;
////	I2C_PORT->DR = I2C_ADRESS_WRITE;
//	while((I2C_PORT->SR1 &  I2C_SR1_ADDR) == 0)
//		{
//			if ((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//				return 0;
//			}
//	}
//	x = I2C_PORT->SR1;
//	x = I2C_PORT->SR2;
//	I2C_PORT->DR = reg;
//	while((I2C_PORT->SR1 &  I2C_SR1_TXE) == 0);
//	I2C_PORT->DR = value;
//	while((I2C_PORT->SR1 &  I2C_SR1_TXE) == 0);
//	I2C_PORT->CR1 |= I2C_CR1_STOP;
//}
//
//
//char read_reg(char reg){
//	I2C_PORT->CR1 |= I2C_CR1_START;
//	int x;
//
//	while((I2C_PORT->SR1 &  I2C_SR1_SB) == 0);
//	x = I2C_PORT->SR1;
////	I2C_PORT->DR = I2C_ADRESS_WRITE;
//
//
//	while((I2C_PORT->SR1 &  I2C_SR1_ADDR) == 0)
//	{
//		if ((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//			return 0;
//		}
//	}
//
//	I2C_PORT->SR1;
//	I2C_PORT->SR2;
//
//	I2C_PORT->DR = reg;
//	while((I2C_PORT->SR1 &  I2C_SR1_TXE) == 0);
//
//	I2C_PORT->CR1 |= I2C_CR1_START;
//	while((I2C_PORT->SR1 &  I2C_SR1_SB) == 0);
//	x = I2C_PORT->SR1;
////	I2C_PORT->DR = I2C_ADRESS_READ;
//
///*	while((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//		I2C_PORT->DR = I2C_ADRESS_READ;
//		delay();
//	}
//*/
//	while((I2C_PORT->SR1 &  I2C_SR1_ADDR) == 0)
//		{
//			if ((I2C_PORT->SR1 &  I2C_SR1_AF) == I2C_SR1_AF){
//				return 0;
//			}
//		}
//	I2C_PORT->SR1;
//	I2C_PORT->SR2;
//	while((I2C_PORT->SR1 &  I2C_SR1_RXNE) == 0);
//	char tmp = I2C_PORT->DR;
//	I2C_PORT->CR1 |= I2C_CR1_STOP;
//	return tmp;
//}
