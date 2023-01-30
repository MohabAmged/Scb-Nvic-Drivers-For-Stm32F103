 /**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Scb_Types.h
 *  Module:  	  Scb
 *
 *  Description:  Header file for the microcontroller Scb Data Types specifications
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohab Amged
 *	Date:		  29/09/2022
 *********************************************************************************************************************/
#ifndef MCAL_SCB_TYPES_H_
#define MCAL_SCB_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* SCB Exceptions Count                    */
#define SCB_EXCEPTIONS_NUMBER     10

/* To write to AIRCR register, you must write 0x5FA to the VECTKEY field */

#define SCB_AIRCR_WRITEVECTKEY    0x5FA

/*  Priority Group Binary Point */

typedef enum
{
	PRIGROUP1 = 0b011,      /*     Group Priority 16  Sub Priority None 0bxxxx  (X:Main Priority, Y:Sub Priority)  */
	PRIGROUP2 = 0b100,      /*     Group Priority 8  Sub Priority 2     0bxxxy  (X:Main Priority, Y:Sub Priority)  */
	PRIGROUP3 = 0b101,      /*     Group Priority 4  Sub Priority 4     0bxxyy  (X:Main Priority, Y:Sub Priority)  */
	PRIGROUP4 = 0b110,      /*     Group Priority 2  Sub Priority 8     0bxyyy  (X:Main Priority, Y:Sub Priority)  */
	PRIGROUP5 = 0b111       /*     Group Priority none  Sub Priority 16 0byyyy  (X:Main Priority, Y:Sub Priority)  */
} Scb_PriorityGroupType;


/* SCB Priority Level Type         */
typedef unsigned char Scb_PriorityLevelType;

/* SCB Exceptions State */

typedef enum
{
	EXC_DISABLED = 0,
	EXC_ENABLED  = 1
} Scb_ExceptionModeType;



/* SCB Exceptions Id */

typedef enum
{
	/* Exceptions Id   */
	RESET = 1,
	NMI = 2,
	HARD_FAULT = 3,
	MEMORY_MANAGE_FAULT = 4,
	BUS_FAULT = 5,
	USAGE_FAULT = 6,
	SVCALL = 7,
	DEBUG_MONITOR = 8,
	PENDSV = 9,
	SYSTICK = 10
} Scb_ExceptionType;



/*  SCB CONFIG Type                 */

typedef struct
{
	Scb_ExceptionType exceptionId;
	Scb_ExceptionModeType mode;
	Scb_PriorityLevelType priority;
} Scb_ExceptionConfigType;





/* Scb Interrupt control and state register Bit Fields   */
typedef struct
{
	uint32 VECTACTIVE		:9; /*  Contains the active exception number     */
	uint32				    :2; /*  Reserved                                 */
	uint32 RETOBASE		    :1; /*  Indicates whether there are preempted active exceptions:           */
	uint32 VECTPENDING		:10;/*Indicates the exception number of the highest priority pending enabled exception.*/
	uint32 ISRPENDING		:1; /*Interrupt pending flag, excluding NMI and Faults*/
	uint32 				    :2; /*  Reserved                                 */
	uint32 PENDSTCLR	    :1; /*  SysTick exception clear-pending bit.     */
	uint32 PENDSTSET	    :1; /* SysTick exception set-pending bit         */
    uint32 PENDSVCLR        :1; /* PendSV clear-pending bit                  */
    uint32 PENDSVSET        :1; /* PendSV set-pending bit.                   */
	uint32 				    :2; /*  Reserved                                 */
    uint32 NMIPENDSET       :1; /* NMI set-pending bit                       */


} Scb_IntCtrl;

typedef union
{
	uint32			R;    /* Read State  */
	Scb_IntCtrl	    W;    /* Write State */
} Scb_IntCtrlRwType;



/* SCB Vector table offset  register Bit Fields   */
typedef struct
{
	uint32          		:9; /*  Reserved                                    */
	uint32	TBLOFF		    :21; /* Vector table base offset field
	                             Bit 29 determines whether the vector
	                             table is in the code or SRAM memory region*/
	uint32          		:2; /*  Reserved                                     */


} Scb_VectOffType;


/* Scb Application interrupt and reset control register Bit Fields   */
typedef struct
{
	uint32 VECTRESET		:1; /*  Reserved for Debug use.     */
	uint32 VECTCLRACTIVE    :1; /*  Reserved for Debug use.     */
	uint32 SYSRESETREQ		:1; /*  System reset request        */
	uint32           		:5;/*   Reserved                    */
	uint32 PRIGROUP   		:3; /*  Interrupt priority grouping field
	This field determines the split of group priority from subpriority */

	uint32 				    :4; /*  Reserved                                 */
	uint32 ENDIANESS	    :1; /*  Data endianness bit Reads as 0 ->Little InEndians     */
	uint32 VECTKEY	        :16; /* Register key Reads as 0xFA05
                                   On writes, write 0x5FA to VECTKEY, otherwise the write is ignored       */
} Scb_AIRCRType;





/* Scb System control register Bit Fields   */
typedef struct
{
	uint32          		:1; /*  Reserved      */
	uint32 SLEEPONEXIT      :1; /*  Configures sleep-on-exit when returning from Handler mode to Thread mode
	                                Setting this bit to 1 enables an interrupt-driven application
	                                to avoid returning to an empty main application.                      */

	uint32 SLEEPDEEP		:1; /*  Controls whether the processor uses sleep or deep sleep as its low power mode    */
	uint32           		:1; /*   Reserved                    */
	uint32 SEVEONPEND   	:1; /*  Send Event on Pending bit  When Set :
                                	Enabled events and all interrupts,
                                	including disabled interrupts, can wakeup the processor. */
	uint32 				    :27; /*  Reserved                                 */

} Scb_ScrType;




/* Scb Configuration and control register Bit Fields   */
typedef struct
{
	uint32 NONBASETHRDENA   :1; /*  Configures how the processor enters Thread mode.      */
	uint32 USERSETMPEND     :1; /*  Enables unprivileged software access to the STIR      */
	uint32           		:1; /*   Reserved                    */
	uint32 UNALIGN_TRP		:1; /*  Enables unaligned access traps   */
	uint32 DIV_0_TRP      	:1; /*  Enables faulting or halting when the processor
	                                executes an SDIV or UDIV instruction with a
                                    divisor of 0                    */
	uint32 				    :3; /*  Reserved                                 */

	uint32 BFHFNMIGN     	:1; /* Enables handlers with priority -1 or -2 to ignore
	                               data bus faults caused by load and store instructions. */
	uint32 STKALIGN		    :1; /* Configures stack alignment on exception entry          */
	uint32                  :22;/* Reserved                                               */

} Scb_CcrType;


/* Scb System handler priority registers  Bit Fields   */


/* Scb System handler priority register1  Bit Fields   */
typedef struct
{
	uint32 				:4;   /* Can't Type */
	uint32 MEMMF		:4;   /* MMF Priority Bits */
	uint32 				:4;   /* Can't Type */
	uint32 BUSF		    :4;   /* Bus Fault Priority Bits */
	uint32				:4;   /* Can't Type */
	uint32 USAGE		:4;   /* Usage Fault Bits */
	uint32				:8;
} Scb_SHPR1Type;

/* Scb System handler priority register2  Bit Fields   */


typedef struct
{
	uint32 				:28; /* Reserved */
	uint32 SVCALL		:4;  /* Priority of system handler SVCall */
} Scb_SHPR2Type;


/* Scb System handler priority register3  Bit Fields   */

typedef struct
{
	uint32 				:20; /* Reserved    */
	uint32 PendSV		:4;  /* Priority of system handler Pend SV  */
	uint32				:4;  /* Reserved    */
	uint32 SysTick		:4;  /* Priority of system handler System Tick  */
} Scb_SHPR3Type;


/* Scb System handler control and state register  Bit Fields   */


typedef struct
{
	uint32 MEMFAULTACT			:1;   /* Memory management fault exception */
	uint32 BUSFAULTACT			:1;   /* Bus fault exception active bit,   */
	uint32 				        :1;   /* Reserved                          */
	uint32 USGFAULTACT			:1;   /* Usage fault exception active bit, */
	uint32 				        :3;   /* Reserved                          */
	uint32 SVCALLACT			:1;   /* SVC call active bit*/
	uint32 MONITORACT			:1;   /* Debug monitor active bit, reads as 1 if Debug monitor is active*/
	uint32 				        :1;   /* Reserved                          */
	uint32 PENDSVACT		    :1;   /* PendSV exception active bit       */
	uint32 SYSTICKACT			:1;   /* SysTick exception active bit      */
	uint32 USGFAULTPENDED		:1;   /* Usage fault exception pending bit */
	uint32 MEMFAULTPENDED	    :1;   /* Memory management fault exception pending bit*/
	uint32 BUSFAULTPENDED		:1;   /* Bus fault exception pending bit              */
	uint32 SVCALLPENDED			:1;   /* SVC call pending bit              */
	uint32 MEMFAULTENA			:1;   /* Memory management fault enable bit*/
	uint32 BUSFAULTENA			:1;   /* Bus fault enable bit              */
	uint32 USGFAULTENA		    :1;   /* Usage fault enable bit            */
	uint32 				        :13;  /* Reserved */
} Scb_SHCSRType;



/* Scb Configurable fault status register Bit Fields */


typedef struct
{
	/* From 0->7 MMF sub Register (Byte) */
	uint32 IACCVIOL    :1;      /*  Instruction access violation flag    */
	uint32 DACCVIOL    :1;      /*  Data access violation flag           */
	uint32             :1;      /*  Reserved                             */
	uint32 MUNSTKERR   :1;      /*  : Memory manager fault on unstacking for a return from exception
                                    This fault is chained to the handler           */
	uint32 MSTKERR     :1;      /*  Memory manager fault on stacking for exception entry      */
	uint32             :2;      /*  Reserved      */
	uint32 MMARVALID   :1;      /*  Memory Management Fault Address Register (MMAR) valid flag    */


	/* From 8->15 Bus Fault sub Register (Byte) */
	uint32 IBUSERR     :1;      /*  Instruction bus error    */
	uint32 PRECISERR   :1;     /*  : Precise data bus error    */
	uint32 IMPRECISERR :1;      /*  Imprecise data bus error */
	uint32 UNSTKERR    :1;      /*  Bus fault on unstacking for a return from exception
                                    This fault is chained to the handler */
	uint32 STKERR      :1;      /*  Bus fault on stacking for exception entry */
	uint32             :2;      /*  Reserved   */
	uint32 BFARVALID   :1;      /*  Bus Fault Address Register (BFAR) valid flag */


	/* From 16->31 Usage Fault sub Register (Half Word) */
	uint32 UNDEFINSTR  :1;      /*  Undefined instruction usage fault           */
	uint32 INVSTATE    :1;      /*  Invalid State usage fault           */
	uint32 INVPC       :1;      /*  Invalid PC load usage fault, caused by an invalid PC load by EXC_RETURN      */
	uint32 NOCP        :1;      /*  No coprocessor usage fault. The processor does not support coprocessor instructions */
	uint32             :4;      /*  Reserved */
	uint32 UNALIGNED   :1;      /*  Unaligned access usage fault  */
	uint32 DIVBYZERO   :1;      /*  Divide by zero usage fault   */
	uint32             :6;      /*  Reserved */

}Scb_CFSRType;




/* Scb Hard fault status register Bit Fields */


typedef struct
{
	uint32 		        :1;   /* Reserved */
	uint32 VECTTBL		:1;   /* Vector Table Hard Fault */
	uint32 		        :8;   /* Reserved */
	uint32 FORCED		:1;   /* Forced Hard Fault */
	uint32 DEBUG_VT		:1;   /* Reserved for Debug use.  */



} Scb_HFSRType;


/* Scb Memory management fault address register  Type Def */

/*this field holds the address of the
location that generated the memory management fault*/
typedef unsigned long Scb_MmfarType;



/* Scb Bus fault address register  Type Def */

/*this field holds the address of the
location that generated the Bus fault*/
typedef unsigned long Scb_BfarType;











#endif /* MCAL_SCB_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Scb_Types.h
 *********************************************************************************************************************/
