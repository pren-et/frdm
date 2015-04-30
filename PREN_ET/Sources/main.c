/* ###################################################################
**     Filename    : main.c
**     Project     : uC_Host
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-06, 09:12, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
#include "Vent.h"
#include "BitsIoLdd1.h"
#include "BLDCspi.h"
#include "SMasterLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include "shell.h"
#include "Error.h"
#include "BLDC.h"
#include "../../../stepper/driver/drv/l6480.h"


static void Task1(void *pvParameters)
{
	(void)pvParameters;
	while (1) {
		LedGreen_Neg();
		FRTOS1_vTaskDelay(1000/portTICK_RATE_MS);
	}

}

static void Task2(void *pvParameters)
{
	(void)pvParameters;
	while (1) {
		LedRed_Neg();
		FRTOS1_vTaskDelay(500/portTICK_RATE_MS);
	}
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	xTaskHandle A;
	xTaskHandle B;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  	l6480_init();							// Compilertest
	l6480_cmd_getstatus();

	/*******************************************************
	 * Einstellungen fï¿½r den Motor und die Treiberstufen   *
	 ******************************************************/
	l6480_set_ocd_th_millivolt(1000); 			// Overcurrentdetection Treshold
	l6480_set_stall_th_millivolt(1000); 		// Stalldetection Tresold
	l6480_set_gatecfg1_igate_milliampere(96);	// Gatstrom
	l6480_set_gatecfg1_tcc_nanosecond(250);		// Bestromungszeiten
	l6480_set_gatecfg1_tboost_nanosecond(125);
	l6480_set_gatecfg2_tdt_nanosecond(250);
	l6480_set_gatecfg2_tblank_nanosecond(250);	// Pausenzeit Messung
	l6480_set_kval_hold(20);						// KVAL Motor Stillstand
	l6480_set_kval_run(64);						// kVAL Motor Run
	l6480_set_kval_acc(64);
	l6480_set_kval_dec(64);



  set_status(STATUS_RESET);
  l6480_init();							// Compilertest
  BLDC_init();
  SHELL_Init();
  l6480_cmd_hardstop();							// Aus HiZ
  uint16_t speed = 0;
  for(;;){
	  l6480_cmd_softstop();
	  WAIT1_Waitms(1000);
	  l6480_cmd_run(0,speed); 					// Motor rueckwärts
	  WAIT1_Waitms(2000);
	  l6480_cmd_softstop();						//
	  WAIT1_Waitms(1000);
	  if (speed < 0xfffff) {					// Geschwindigkeit erhï¿½hen
		  speed += 1000;
	  }
	  else {
		  speed = 0;							// Geschwindigkeit rï¿½cksetzen
	  }
  }
  l6480_cmd_goto(1000);

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
