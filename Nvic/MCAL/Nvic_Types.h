

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  NVIC_Types.h
 *  Module:  	  NVIC_Types
 *
 *  Description:  Header file for STM32F103 MCU - NVIC Module's Types
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  27/09/2022
 *********************************************************************************************************************/
#ifndef MCAL_NVIC_TYPES_H_
#define MCAL_NVIC_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/* Number Of Interrupts Want To Activate  */
#define NVIC_INTERRUPTS_NUMBER     60

/* Nvic Priority Level Type         */
typedef unsigned char Nvic_PriorityLevelType;


typedef enum
{
	/* Interrupts Id    */
	WWDG=0,
	PVD=1,
	TAMPER=2,
	RTC=3,
	FLASH=4,
	RCC=5,
	EXTI0=6,
	EXTI1=7,
	EXTI2=8,
	EXTI3=9,
	EXTI4=10,
	DMA1_Channel1=11,
	DMA1_Channel2=12,
	DMA1_Channel3=13,
	DMA1_Channel4=14,
	DMA1_Channel5=15,
	DMA1_Channel6=16,
	DMA1_Channel7=17,
	ADC1_2=18,
	CAN1_TX=19,
	CAN1_RX0=20,
	CAN1_RX1=21,
	CAN1_SCE=22,
	EXTI9_5=23,
	TIM1_BRK=24,
	TIM1_UP=25,
	TIM1_TRG_COM=26,
	TIM1_CC=27,
	TIM2=28,
	TIM3=29,
	TIM4=30,
	I2C1_EV=31,
	I2C1_ER=32,
	I2C2_EV=33,
	I2C2_ER=34,
	SPI1=35,
	SPI2=36,
	USART1=37,
	USART2=38,
	USART3=39,
	EXTI15_10=40,
	RTCAlarm=41,
	OTG_FS_WKUP=42,

	/* From 42 to 50 Reserved */

	TIM5=50,
	SPI3=51,
	UART4=52,
	UART5=53,
	TIM6=54,
	TIM7=55,
	DMA2_Channel1=56,
	DMA2_Channel2=57,
	DMA2_Channel3=58,
	DMA2_Channel4=59,
	DMA2_Channel5=60,
	ETH=61,
	ETH_WKUP=62,
	CAN2_TX=63,
	CAN2_RX0=64,
	CAN2_RX1=65,
	CAN2_SCE=66,
	OTG_FS=67
} Nvic_InterruptType;



typedef enum
{
	INT_DISABLED = 0,
	INT_ENABLED  = 1
} Nvic_InterruptModeType;


typedef struct
{
	Nvic_InterruptType interruptId;
	Nvic_InterruptModeType mode;
	Nvic_PriorityLevelType priority;
} Nvic_InterruptConfigType;







#endif /* MCAL_NVIC_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Nvic_Types.h
 *********************************************************************************************************************/
