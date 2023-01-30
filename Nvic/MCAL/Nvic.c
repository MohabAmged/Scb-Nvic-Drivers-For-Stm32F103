/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.c
 *  Module:  	  IntCtrl
 *  Description:  Source file for NVIC Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  27/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Nvic.h"
#include "Macros.h"
#include "Nvic_Cfg.h"
#include "Nvic_Regs.h"
#include "Nvic_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Nvic_InitInt(Nvic_InterruptConfigType IntCfg)
{
	/* If Interrupt Mode Set To Enable  */
	if(IntCfg.mode==INT_ENABLED)
	{
		/* Activate Interrupt*/
		Nvic_EnableInterrupt(IntCfg.interruptId);

		/* Set Interrupt Priority  */
		Nvic_SetInterruptPriority(IntCfg.interruptId, IntCfg.priority);




	}
	else if (IntCfg.mode==INT_DISABLED)    	/* If Interrupt Mode Set To Disable  */
	{

	/* Deactivate Interrupt */
		Nvic_DisableInterrupt(IntCfg.interruptId);
	}



}



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
void Nvic_EnableInterrupt(Nvic_InterruptType InterruptId)

{

	/*  Checking The Id And Writing The Enable Bit To Its Mapped Register   */
	/*  Enabling Interrupt */
	if (InterruptId > 0 && InterruptId <=31)
	{
		/* Register 0    */
		SET_BIT(NVIC_INTERRUPTSET_ENABLE_REGISTER0,InterruptId);

	}
	else if(InterruptId>31 && InterruptId<=63)
	{
		/* Register 1    */
		SET_BIT(NVIC_INTERRUPTSET_ENABLE_REGISTER1,InterruptId);

	}
	else if(InterruptId>63 && InterruptId<=67)
		{
		/* Register 2    */
			SET_BIT(NVIC_INTERRUPTSET_ENABLE_REGISTER2,InterruptId);


		}
	else
	{
		/*  Error  do nothing */
		return ;

	}


}

/*******************************************************************************
* Service Name: Nvic_DisableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Disable the passing interrupt
*******************************************************************************/
void Nvic_DisableInterrupt(Nvic_InterruptType InterruptId)
{
	/*  Checking The Id And Writing The Enable Bit To Its Mapped Register   */
		/*  Enabling Interrupt */
		if (InterruptId > 0 && InterruptId <=31)
		{
			/* Register 0    */
			SET_BIT(NVIC_INTERRUPTCLR_ENABLE_REGISTER0,InterruptId);

		}
		else if(InterruptId>31 && InterruptId<=63)
		{
			/* Register 1    */
			SET_BIT(NVIC_INTERRUPTCLR_ENABLE_REGISTER1,InterruptId);

		}
		else if(InterruptId>63 && InterruptId<=67)
			{
			/* Register 2    */
				SET_BIT(NVIC_INTERRUPTCLR_ENABLE_REGISTER2,InterruptId);


			}
		else
		{
			/*  Error  do nothing */
			return ;

		}


}


/*******************************************************************************
* Service Name: Nvic_GetPendingInterrupt
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Nvic_InterruptType InterruptId
* Parameters (inout): None
* Parameters (out): uint8
* Return value: void
* Description: Disable the passing interrupt
*******************************************************************************/
uint8 Nvic_GetPendingInterrupt(Nvic_InterruptType InterruptId)
{
	uint8 state=0;
	if (InterruptId > 0 && InterruptId <=31)
		{
			/* Register 0    */
		state=GET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER0,InterruptId);

		}
		else if(InterruptId>31 && InterruptId<=63)
		{
			/* Register 1    */
			state=GET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER1,InterruptId);

		}
		else if(InterruptId>63 && InterruptId<=67)
			{
			/* Register 2    */
			state=GET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER2,InterruptId);


			}
		else
		{
			/*  Error  do nothing */
			state= 0 ;

		}

	return state;


}

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

void Nvic_SetPendingInterrupt(Nvic_InterruptType InterruptId)
{

	if (InterruptId > 0 && InterruptId <=31)
		{
			/* Register 0    */
		SET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER0,InterruptId);

		}
		else if(InterruptId>31 && InterruptId<=63)
		{
			/* Register 1    */
			SET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER1,InterruptId);

		}
		else if(InterruptId>63 && InterruptId<=67)
			{
			/* Register 2    */
			SET_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER2,InterruptId);


			}
		else
		{
			/*  Error  do nothing */


		}



}

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
void Nvic_ClrPendingInterrupt(Nvic_InterruptType InterruptId)
{


	if (InterruptId > 0 && InterruptId <=31)
		{
			/* Register 0    */
		CLEAR_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER0,InterruptId);

		}
		else if(InterruptId>31 && InterruptId<=63)
		{
			/* Register 1    */
			CLEAR_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER1,InterruptId);

		}
		else if(InterruptId>63 && InterruptId<=67)
			{
			/* Register 2    */
			CLEAR_BIT(NVIC_INTERRUPTSET_PENDING_REGISTER2,InterruptId);


			}
		else
		{
			/*  Error  do nothing */


		}

}


/*******************************************************************************
* Service Name: Nvic_GetActiveInterrupt
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Void
* Parameters (inout): None
* Parameters (out): uint8
* Return value: void
* Description: Get the Active Interrupt id or return a dummy value if not exist
*******************************************************************************/

uint8 Nvic_GetActiveInterrupt(void)
	{

		uint8 id=0,counter;

		for(counter=0;counter<=NVIC_INTERRUPTS_NUMBER;counter++)
		{


			if (counter > 0 && counter <=31)
				{
					/* Register 0    */
				/*  checking each bit in register 0     */
				if(GET_BIT(NVIC_INTERRUPT_ACTIVEBIT_REGISTER0,counter)==TRUE)
				{
					/* getting the id of the Interrupt*/
					id=counter;
					break;
				}

				}
				else if(counter>31 && counter<=63)
				{
					/* Register 1   */
					/*  checking each bit in register 1     */
					if(GET_BIT(NVIC_INTERRUPT_ACTIVEBIT_REGISTER1,counter)==TRUE)
							{
								/* getting the id of the Interrupt*/
								id=counter;
								break;
							}

				}
				else if(counter>63 && counter<=67)
					{
					/* Register 2    */
					/*  checking each bit in register 2     */
				if(GET_BIT(NVIC_INTERRUPT_ACTIVEBIT_REGISTER2,counter)==TRUE)
							{
								/* getting the id of the Interrupt*/
								id=counter;
								break;
							}


					}
				else
				{
					/*  Set id to a dummy value  */

					id=0xff;

				}

		}


		return id;
	   }



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
void Nvic_SetInterruptPriority(Nvic_InterruptType InterruptId , Nvic_PriorityLevelType Priority)
{

	     /* Setting Priority */

		/* getting the priority register number  */
		uint8 interrupt_priority_register=InterruptId/4;

		/* getting the priority byte for the interrupt inside the priority register */

		uint8 offset=interrupt_priority_register%4;

		/* saving the place we need to write at */

		/* Interrupt Priority Registers Definitions */

		/* From Address offset 0x300 to 0x320 each Register Contains 4 Byte Each byte represent Interrupt
		 *for each byte the Least 4 Bits are Read only
		 * Priority is Set by The Most Four Bits  So we can use the Equation at the data sheet
		 *  corresponding IPR number, M, is given by M = N DIV 4
		• The byte offset of the required Priority field in this register is N MOD 4, To Determine the Required field we want to Write at
		  For The corresponding Interrupt  */

		/* At Offset 0x320 Only The Least Byte Can Be Written The Most 3 Bytes Are Reserved   */

	     uint8 priority_place = *((volatile uint8* )(NVIC_REGISTERS_BASEADDRES+0x300+(interrupt_priority_register*4)+offset));

	    /* Assigning The Priority  */
	    priority_place|=((Priority&0x0F)<<4); /* clearing the most four bits and adding the value to the register*/





}



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
void Nvic_EnSoftWareInterrupt(Nvic_InterruptType InterruptrId)
{
	Nvic_InterruptType *Id= &InterruptrId;
	SCB_CONFIGANDCTRL.USERSETMPEND=1;  /* Enables Software Interrupt With The Given ID        */
    NVIC_INTERRUPT_SOFTWARETRIGEER_REGISTER|=(*Id);  /*Inserting The First 8 Bits To Select The Interrupt*/


}

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
void Nvic_InterruptPriorityGroup(Scb_PriorityGroupType PRIGROUP)
{
	/* Writing The Key To the Register So We Can Write Inside The Register */
	SCB_APPINTANDRESET_REGISTER.VECTKEY=SCB_AIRCR_WRITEVECTKEY;

	/* Writing Group Priority To The Priority Field*/
	SCB_APPINTANDRESET_REGISTER.PRIGROUP=PRIGROUP;

}


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
void Nvic_InitCfg(void)
{
	uint8 InC;
	/* Looping Over The Configuration Struct */
	Nvic_ConfigType *ConfigPtr = &Nvic_Config;
	for(InC=0 ; InC < MICROCONTROLLER_INTERRUPTS_NUM;InC++)
	{
		/* Check State if Its Enabled Set Int Enable And Priority*/
		if(ConfigPtr->interrupts[InC].mode==INT_ENABLED)
		{   /* Enable Interrupt */
			Nvic_EnableInterrupt(ConfigPtr->interrupts[InC].interruptId);

			/* Set Interrupt Priority */
			Nvic_EnableInterrupt(ConfigPtr->interrupts[InC].priority);

		}
		else if(ConfigPtr->interrupts[InC].mode==INT_DISABLED)
		{
			  /* Disable Interrupt */

			Nvic_DisableInterrupt(ConfigPtr->interrupts[InC].interruptId);

		}


	}



}









/**********************************************************************************************************************
 *  END OF FILE: Nvic.c
 *********************************************************************************************************************/
