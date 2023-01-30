 /**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Mcu_Hw.h
 *  Module:  	  Mcu_Hw
 *
 *  Description:  Header file for the microcontroller hardware specifications like registers' definitions
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  26/09/2022
 *********************************************************************************************************************/
#ifndef MCU_HW_H_
#define MCU_HW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Nvic_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define F_CPU																		16U		/* In MHz */
#define NVIC_REGISTERS_BASEADDRES    0xE000EF00

/* Interrupt Set Enable Registers Definitions */

#define NVIC_INTERRUPTSET_ENABLE_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x000)))
#define NVIC_INTERRUPTSET_ENABLE_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x004)))
#define NVIC_INTERRUPTSET_ENABLE_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x008)))


/* Interrupt Clear Enable Registers Definitions */

#define NVIC_INTERRUPTCLR_ENABLE_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x080)))
#define NVIC_INTERRUPTCLR_ENABLE_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x084)))
#define NVIC_INTERRUPTCLR_ENABLE_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x088)))



/* Interrupt Set Pending Registers Definitions */

#define NVIC_INTERRUPTSET_PENDING_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x100)))
#define NVIC_INTERRUPTSET_PENDING_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x104)))
#define NVIC_INTERRUPTSET_PENDING_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x108)))


/* Interrupt Clear Pending Registers Definitions */

#define NVIC_INTERRUPTCLR_PENDING_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x180)))
#define NVIC_INTERRUPTCLR_PENDING_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x184)))
#define NVIC_INTERRUPTCLR_PENDING_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x188)))




/* Interrupt Active Bit Registers Definitions */

#define NVIC_INTERRUPT_ACTIVEBIT_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x200)))
#define NVIC_INTERRUPT_ACTIVEBIT_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x204)))
#define NVIC_INTERRUPT_ACTIVEBIT_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x208)))


/* Interrupt Active Bit Registers Definitions */

#define NVIC_INTERRUPTCLR_PENDING_REGISTER0     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x180)))
#define NVIC_INTERRUPTCLR_PENDING_REGISTER1     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x184)))
#define NVIC_INTERRUPTCLR_PENDING_REGISTER2     (*((volatile uint32*)(NVIC_REGISTERS_BASEADDRES+0x188)))


/* Software trigger interrupt register Definitions */

/*  Only The Least Byte Can Be Written The Most 3 Bytes Are Reserved    */
#define NVIC_INTERRUPT_SOFTWARETRIGEER_REGISTER     (*((volatile uint32*)(0xE000EF00+0xE00)))



















/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif  /* MCU_HW_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
