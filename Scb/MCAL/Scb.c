/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Scb.c
 *  Module:  	  Scb
 *  Description:  Source file for SCB Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  29/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scb.h"
#include "Scb_Types.h"
#include "Macros.h"
#include "Scb_Cfg.h"
#include "Scb_Regs.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Scb_VectLocation
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): check    (if 1 Vector Table At SRAM else flash (Default))
* Return value: uint8
* Description: Get Vector Table Location
*******************************************************************************/
uint8 Scb_VectLocation(void)
{
	uint32 state=0;
	uint8  check=0;
	/* Get The Indicating bit For Flash Or Ram Location           */
	state=(SCB_VTOR_REGISTER.TBLOFF);

	if(state>>20==1)
	{
		check=1;
	}

	return check;

}


/*******************************************************************************
* Service Name: Scb_VectLocation
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): BINARY_POINT
* Parameters (inout): None
* Parameters (out): none
* Return value: void
* Description: Set Priority Group
*******************************************************************************/
void Scb_SetPriorityGroup(Scb_PriorityGroupType PRIGROUP)
{
	/* Writing The Key To the Register So We Can Write Inside The Register */
	SCB_APPINTANDRESET_REGISTER.VECTKEY=SCB_AIRCR_WRITEVECTKEY;

	/* Writing Group Priority To The Priority Field*/
	SCB_APPINTANDRESET_REGISTER.PRIGROUP=PRIGROUP;

}

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
void Scb_ExcEnable(Scb_ExceptionType ExcId ,Scb_PriorityLevelType ExcPriority)
{
    switch (ExcId)
	{
    /* Switch Between IDs To Enable Exceptions */
    case MEMORY_MANAGE_FAULT:
    	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.MEMFAULTENA=1;            /* Enable MMF EXC*/
    	SCB_SYSHANDLERPRIORITY_REGISTER1.MEMMF=ExcPriority;           /* Set Priority  */
        break;
    case BUS_FAULT:
        	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.BUSFAULTENA=1;        /* Enable BF EXC*/
        	SCB_SYSHANDLERPRIORITY_REGISTER1.BUSF=ExcPriority;        /* Set Priority  */
            break;
    case USAGE_FAULT:
           	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.USGFAULTENA=1;        /* Enable USAGE FAULT EXC*/
           	SCB_SYSHANDLERPRIORITY_REGISTER1.USAGE=ExcPriority;       /* Set Priority  */
               break;
    case SVCALL:
                  /* Enable From Another Peripheral */
           	SCB_SYSHANDLERPRIORITY_REGISTER2.SVCALL=ExcPriority;       /* Set Priority  */
               break;
    case PENDSV:
                  /* Enable From Another Peripheral */
           	SCB_SYSHANDLERPRIORITY_REGISTER3.PendSV=ExcPriority;       /* Set Priority  */
               break;
    case SYSTICK:
                     /* Enable From Another Peripheral */
              	SCB_SYSHANDLERPRIORITY_REGISTER3.SysTick=ExcPriority;       /* Set Priority  */
                  break;
    default:
    	break; /* Default Case Break (Do Nothing) */

	}
}


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
uint32* Scb_GetMemoryMFaultAddress(void)
{
	uint32 ** mmfaddptr=NULL;   /* Creating A Pointer To Pointer As We Return Address*/
	*mmfaddptr=SCB_MMFAR_REGISTER;       /* Getting the reading From MMFA Register   */

	/* Checking If The Address Inside The Register is Valid   */
	if(SCB_COFNGFAULTSTATUS_REGISTER.MMARVALID==1)
	{
		/* Return The Valid Address  */
		return (*mmfaddptr);

	}
	else
		return NULL;  /* IF The Address Isn't Valid Return NULL */

}

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
uint32* Scb_GetBusFaultAddress(void)
{
	uint32 ** Bfaddptr=NULL;   /* Creating A Pointer To Pointer As We Return Address*/
	*Bfaddptr=SCB_MMFAR_REGISTER;       /* Getting the reading From MMFA Register   */

	/* Checking If The Address Inside The Register is Valid   */
	if(SCB_COFNGFAULTSTATUS_REGISTER.BFARVALID==1)
	{
		/* Return The Valid Address  */
		return (*Bfaddptr);

	}
	else
		return NULL;  /* IF The Address Isn't Valid Return NULL */

}
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
void Scb_ExcDisable(Scb_ExceptionType ExcId )
{
    switch (ExcId)
	{
    /* Switch Between IDs To Enable Exceptions */
    case MEMORY_MANAGE_FAULT:
    	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.MEMFAULTENA=0;            /* Disable MMF EXC*/
        break;
    case BUS_FAULT:
        	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.BUSFAULTENA=0;        /* Disable BF EXC*/
            break;
    case USAGE_FAULT:
           	SCB_SYSHANDLERCTRLANDSTATE_REGISTER.USGFAULTENA=0;        /* Disable USAGE FAULT EXC*/
               break;

    default:
    	break; /* Default Case Break (Do Nothing) */

	}
}
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
void Scb_ExcInit(Scb_ExceptionConfigType ExcCfg)
{
	/* If Interrupt Mode Set To Enable  */
	if(ExcCfg.mode==INT_ENABLED)
	{


		/* Activate and Set Interrupt Priority  */
		Scb_ExcEnable(ExcCfg.exceptionId, ExcCfg.priority);





	}
	else if (ExcCfg.mode==INT_DISABLED)    	/* If Interrupt Mode Set To Disable  */
	{

	/* Deactivate Interrupt */
		Scb_ExcDisable(ExcCfg.exceptionId);
	}



}

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
void Scb_ExcInitCfg(void)
{
	uint8 exc;
	/* Looping Over The Configuration Struct */
	Scb_ConfigType *ConfigPtr = &Exceptions_Config;
	for(exc=0 ; exc < PROCESSOR_EXCEPTIONS_NUM; exc++)
	{
		/* Check State if Its Enabled Set Int Enable And Priority*/
		if(ConfigPtr->Exception[exc].mode==EXC_ENABLED)
		{   /* Enable Interrupt */
			Scb_ExcEnable(ConfigPtr->Exception[exc].exceptionId,ConfigPtr->Exception[exc].priority);



		}
		/*      Check Exception Mode             */
		else if(ConfigPtr->Exception[exc].mode==EXC_DISABLED)
		{
			  /* Disable Interrupt */

			Scb_ExcDisable(ConfigPtr->Exception[exc].exceptionId);

		}


	}



}




/**********************************************************************************************************************
 *  END OF FILE: Scb.c
 *********************************************************************************************************************/
