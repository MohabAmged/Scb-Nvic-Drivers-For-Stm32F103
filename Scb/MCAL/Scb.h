/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Scb.h
 *  Module:  	  SCB
 *
 *  Description:  Header file for STM32F103 MCU - SCB Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  29/09/2022
 *********************************************************************************************************************/
#ifndef MCAL_SCB_H_
#define MCAL_SCB_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Scb_Regs.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Scb_VectLocation
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): state
* Return value:  uint8   (if 1 Vector Table At SRAM else flash)
* Description: Get Vector Table Location
*******************************************************************************/
uint8 Scb_VectLocation(void);

/*******************************************************************************
* Service Name: Scb_VectLocation
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PRIGROUP
* Parameters (inout): None
* Parameters (out): none
* Return value: void
* Description: Set Priority Group
*******************************************************************************/
void Scb_SetPriorityGroup(Scb_PriorityGroupType PRIGROUP);

/*******************************************************************************
* Service Name: Scb_ExcEnable
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ExcId,ExcPriority
* Parameters (inout): None
* Parameters (out): none
* Return value: void
* Description: Enable and Set Priority for Exceptions
*******************************************************************************/
void Scb_ExcEnable(Scb_ExceptionType ExcId ,Scb_PriorityLevelType ExcPriority);

/*******************************************************************************
* Service Name: Scb_GetMemoryMFaultAddress
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): mmfaddptr
* Return value: uint32*
* Description: Get The Address Of The Location Which Caused The MMF
*******************************************************************************/
uint32* Scb_GetMemoryMFaultAddress(void);


/*******************************************************************************
* Service Name: Scb_GetBusFaultAddress
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): Bfaddptr
* Return value: uint32*
* Description: Get The Address Of The Location Which Caused The BF
*******************************************************************************/
uint32* Scb_GetBusFaultAddress(void);


/*******************************************************************************
* Service Name: Scb_ExcDisable
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ExcId
* Parameters (inout): None
* Parameters (out): none
* Return value: void
* Description: Disable and Set Priority for Exceptions
*******************************************************************************/
void Scb_ExcDisable(Scb_ExceptionType ExcId );



/*******************************************************************************
* Service Name: Scb_ExcInit
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Scb_ExceptionConfigType
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Initialize Scb Exceptions by parsing the configuration
*			   into Scb registers
*******************************************************************************/
void Scb_ExcInit(Scb_ExceptionConfigType ExcCfg);


/*******************************************************************************
* Service Name: Scb_ExcInitCfg
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Init Scb Using Lcfg
*******************************************************************************/
void Scb_ExcInitCfg(void);


#endif /* MCAL_SCB_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Scb.h
 *********************************************************************************************************************/
