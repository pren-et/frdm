/* ###################################################################
**     Filename    : Events.h
**     Project     : uC_Host
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-06, 09:12, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "FRTOS1.h"
#include "UTIL1.h"
#include "LedGreen.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LedRed.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "CLS1.h"
#include "WAIT1.h"
#include "CS1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "BLDCspi.h"
#include "SMasterLdd1.h"
//#include "RxBuf1.h"
#include "CS_BLDC1.h"
#include "BitIoLdd4.h"
#include "CS_BLDC2.h"
#include "BitIoLdd5.h"
#include "BLDC1_IRQ.h"
#include "ExtIntLdd1.h"
#include "BLDC2_IRQ.h"
#include "ExtIntLdd2.h"
#include "Stepperspi.h"
#include "SMasterLdd2.h"
#include "HF1.h"
#include "BT1.h"
#include "Serial1.h"
#include "ASerialLdd2.h"
#include "STP_BSY.h"
#include "ExtIntLdd3.h"
#include "PWM1.h"
#include "PwmLdd2.h"
#include "TU1.h"
#include "DIR.h"
#include "BitIoLdd6.h"
#include "Vent.h"
#include "BitsIoLdd1.h"

#ifdef __cplusplus
extern "C" {
#endif 

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void);


void FRTOS1_vApplicationStackOverflowHook(xTaskHandle pxTask, char *pcTaskName);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationStackOverflowHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         if enabled, this hook will be called in case of a stack
**         overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pxTask          - Task handle
**       * pcTaskName      - Pointer to task name
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationTickHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationTickHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called by the RTOS for every
**         tick increment.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationIdleHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationIdleHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called when the RTOS is idle.
**         This might be a good place to go into low power mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void FRTOS1_vApplicationMallocFailedHook(void);
/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationMallocFailedHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, the RTOS will call this hook in case memory
**         allocation failed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
** ===================================================================
**     Event       :  Cpu_OnSupervisorCall (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Supervisor Call exception had
**         occurred. This event is automatically enabled when the
**         [Supervisor Call] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnSupervisorCall(void);

/*
** ===================================================================
**     Event       :  Cpu_OnPendableService (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Pendable Service exception had
**         occurred. This event is automatically enabled when the
**         [Pendable Service] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnPendableService(void);

void CLS1_OnBeforeIterateCmd(const uint8_t *cmd);
/*
** ===================================================================
**     Event       :  CLS1_OnBeforeIterateCmd (module Events)
**
**     Component   :  CLS1 [uC_Host]
**     Description :
**         Hook called before parsing a command in IterateTable().
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - command parsed
**     Returns     : Nothing
** ===================================================================
*/

void CLS1_OnAfterIterateCmd(const uint8_t *cmd);
/*
** ===================================================================
**     Event       :  CLS1_OnAfterIterateCmd (module Events)
**
**     Component   :  CLS1 [uC_Host]
**     Description :
**         Hook called after parsing a command in IterateTable().
**     Parameters  :
**         NAME            - DESCRIPTION
**         cmd             - command parsed
**     Returns     : Nothing
** ===================================================================
*/

void BLDCspi_OnRxChar(void);
/*
** ===================================================================
**     Event       :  BLDCspi_OnRxChar (module Events)
**
**     Component   :  BLDCspi [SynchroMaster]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLDC2_IRQ_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  BLDC2_IRQ_OnInterrupt (module Events)
**
**     Component   :  BLDC2_IRQ [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLDC1_IRQ_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  BLDC1_IRQ_OnInterrupt (module Events)
**
**     Component   :  BLDC1_IRQ [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Stepperspi_OnRxChar(void);
/*
** ===================================================================
**     Event       :  Stepperspi_OnRxChar (module Events)
**
**     Component   :  Stepperspi [SynchroMaster]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Stepperspi_OnTxChar(void);
/*
** ===================================================================
**     Event       :  Stepperspi_OnTxChar (module Events)
**
**     Component   :  Stepperspi [SynchroMaster]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLDCspi_OnTxChar(void);
/*
** ===================================================================
**     Event       :  BLDCspi_OnTxChar (module Events)
**
**     Component   :  BLDCspi [SynchroMaster]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void STP_BSY_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  STP_BSY_OnInterrupt (module Events)
**
**     Component   :  STP_BSY [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.10]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
