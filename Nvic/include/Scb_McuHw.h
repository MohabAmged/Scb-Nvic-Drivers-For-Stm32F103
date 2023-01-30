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
#ifndef MCAL_SCB_MCUHW_H_
#define MCAL_SCB_MCUHW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Scb_Types.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* System Control Block Register Definitions */

#define SCB_REGISTERS_BASEADDRES    0xE000ED00

/* System Control Block Cpu Id  Register Definitions */

/* The First 4 Bits (0->3) Are The Revision Area The Next 14 Bits Are the Part No Area(4->15)
 * The Next 4 bits (16->19) Are The Constant Area The Next 4 Bits (20->23) Are Variant Area
 * The Rest Are The Implementer Area (24->31)
 * */
#define SCB_CPUID_REGISTER                     (*((volatile uint32*)(SCB_REGISTERS_BASEADDRES+0x000)))



/* SCB Interrupt control and state register Definitions */

/*  Use The First Field To Read
 *  Second Filed For Writing (Each Field OF the Register is Declared)
 * */

#define SCB_ICSR_REGISTER                       (*((volatile Scb_IntCtrlRwType*)(SCB_REGISTERS_BASEADDRES+0x04)))

/* SCB Vector table offset  register Definitions */



#define SCB_VTOR_REGISTER                       (*((volatile Scb_VectOffType*)(SCB_REGISTERS_BASEADDRES+0x08)))



/* Scb Application interrupt and reset control register  Definitions */

#define SCB_APPINTANDRESET_REGISTER             (*((volatile Scb_AIRCRType*)(SCB_REGISTERS_BASEADDRES+0x0C)))



/* Scb System control register  Definitions */

#define SCB_SYSTEMCTRL_REGISTER                (*((volatile Scb_ScrType*)(SCB_REGISTERS_BASEADDRES+0x10 )))



/* Scb Configuration and control register Definitions */

#define SCB_CONFIGANDCTRL                      (*((volatile Scb_CcrType*)(SCB_REGISTERS_BASEADDRES+0x14)))



/* Scb System handler priority register 1 Definition */

#define SCB_SYSHANDLERPRIORITY_REGISTER1      (*((volatile Scb_SHPR1Type*)(SCB_REGISTERS_BASEADDRES+0x18)))



/* Scb System handler priority register 1 Definition */

#define SCB_SYSHANDLERPRIORITY_REGISTER2      (*((volatile Scb_SHPR2Type*)(SCB_REGISTERS_BASEADDRES+0x1C)))



/* Scb System handler priority register 1 Definition */

#define SCB_SYSHANDLERPRIORITY_REGISTER3      (*((volatile Scb_SHPR3Type*)(SCB_REGISTERS_BASEADDRES+0x20)))



/* Scb System handler control and state register Definition */

#define SCB_SYSHANDLERCTRLANDSTATE_REGISTER   (*((volatile Scb_SHCSRType*)(SCB_REGISTERS_BASEADDRES+0x24)))



/* Scb Configurable fault status register Definition */

#define SCB_COFNGFAULTSTATUS_REGISTER         (*((volatile Scb_CFSRType*)(SCB_REGISTERS_BASEADDRES+0x28)))



/* Scb Hard fault status register Definition */

#define SCB_HARDFAULTSTATUS_REGISTER         (*((volatile Scb_HFSRType*)(SCB_REGISTERS_BASEADDRES+0x2C)))



/* Scb Memory management fault address register Definition */

#define SCB_MMFAR_REGISTER                  (*((volatile Scb_MmfarType*)(SCB_REGISTERS_BASEADDRES+0x34)))



/* Scb Bus fault address register  Definition */

#define SCB_BFAR_REGISTER                   (*((volatile Scb_BfarType*)(SCB_REGISTERS_BASEADDRES+0x38)))










/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCAL_SCB_MCUHW_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Scb_McuHw.h
 *********************************************************************************************************************/
