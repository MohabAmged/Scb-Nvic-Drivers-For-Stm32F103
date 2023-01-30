
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Nvic.h
 *  Module:  	  Nvic
 *
 *  Description:  Header file for STM32F103 MCU - NVIC Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  27/09/2022
 *********************************************************************************************************************/
#ifndef MCAL_NVIC_H_
#define MCAL_NVIC_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Nvic_Types.h"
#include "Scb_McuHw.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Nvic_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptConfigType
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Initialize NVIC Module by parsing the configuration
*			   into NVIC registers
*******************************************************************************/
void Nvic_Init(Nvic_InterruptConfigType IntCfg);

/*******************************************************************************
* Service Name: Nvic_EnableInterrupt
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Enable the passing interrupt
*******************************************************************************/
void Nvic_EnableInterrupt(Nvic_InterruptType InterruptId);

/*******************************************************************************
* Service Name: IntCtrl_DisableInterrupt
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Disable the passing interrupt
*******************************************************************************/
void Nvic_DisableInterrupt(Nvic_InterruptType InterruptId);

/*******************************************************************************
* Service Name: Nvic_GetPendingInterrupt
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): uint8
* Return value: void
* Description: Check the passing interrupt if it's Pending
*******************************************************************************/
uint8 Nvic_GetPendingInterrupt(Nvic_InterruptType InterruptId);


/*******************************************************************************
* Service Name: Nvic_SetPendingInterrupt
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Set the passed Interrupt To Pending state
*******************************************************************************/
void Nvic_SetPendingInterrupt(Nvic_InterruptType InterruptId);



/*******************************************************************************
* Service Name: Nvic_ClrPendingInterrupt
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Clear the passed Interrupt From Pending state
*******************************************************************************/
void Nvic_ClrPendingInterrupt(Nvic_InterruptType InterruptId);


/*******************************************************************************
* Service Name: Nvic_GetActiveInterrupt
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Void
* Parameters (inout): None
* Parameters (out): Nvic_InterruptType
* Return value: void
* Description: Get the Active Interrupt id
*******************************************************************************/
Nvic_InterruptType Nvic_GetActiveInterrupt(void);




/*******************************************************************************
* Service Name: Nvic_SetPriorityInterrupt
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType , Nvic_PriorityLevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Set The Priority of an Interrupt
*******************************************************************************/
void Nvic_SetInterruptPriority(Nvic_InterruptType InterruptId , Nvic_PriorityLevelType Priority);



/*******************************************************************************
* Service Name: Nvic_EnSoftWareInterrupt
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): InterruptrId
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Enable The Software Interrupt With The Given ID
*******************************************************************************/
void Nvic_EnSoftWareInterrupt(Nvic_InterruptType InterruptrId);


/*******************************************************************************
* Service Name: Nvic_InterruptPriorityGroup
* Service ID[hex]: 0x09
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PRIGROUP
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Set Priority Grouping (Priority and Sub priority)
*******************************************************************************/
void Nvic_InterruptPriorityGroup(Scb_PriorityGroupType PRIGROUP);


/*******************************************************************************
* Service Name: Nvic_InitCfg
* Service ID[hex]: 0x0A
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Init Nvic Using Lcfg
*******************************************************************************/
void Nvic_InitCfg(void);




#endif /* MCAL_NVIC_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Nvic.h
 *********************************************************************************************************************/
