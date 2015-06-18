/*
 * Shell.c
 *
 *  Created on: Mar 7, 2015
 *      Author: Nino
 */

#include "FRTOS1.h"
#include "Shell.h"
#include "CLS1.h"
#include "LedRed.h"
#include "LedGreen.h"
#include "Error.h"
#include "../../../stepper/driver/drv/l6480.h"
#include "BLDC.h"
#include "DC.h"
#include "WAIT1.h"

static const CLS1_ParseCommandCallback CmdParserTable[] =
{
		CLS1_ParseCommand,
#if BLDC_PARSE_COMMAND_ENABLED
		BLDC_ParseCommand,
#endif
		l6480_ParseCommand,
        DC_ParseCommand,
		NULL
};

static void ShellTask(void *pvParameters)
{
	unsigned char buf[48];

	(void)pvParameters;
	buf[0] = '\0';
	(void)CLS1_ParseWithCommandTable((unsigned char*)CLS1_CMD_HELP, CLS1_GetStdio(), CmdParserTable);

	while (1) {
		(void)CLS1_ReadAndParseWithCommandTable(buf, sizeof(buf), CLS1_GetStdio(), CmdParserTable);
		// FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
	}
}

void SHELL_Init(void)
{
	set_status(STATUS_BUSY);
	WAIT1_Waitms(1000);
	CLS1_Init();
	if (FRTOS1_xTaskCreate(
			ShellTask,
			"Shell",
			configMINIMAL_STACK_SIZE+200,
			NULL,
			tskIDLE_PRIORITY,
			NULL ) != pdPASS) {
		while (1) {
			set_status(STATUS_ERROR);
		}
	}
	set_status(STATUS_OK);
}

void shellSendDone(void){
    CLS1_SendStr((unsigned char*)"job done\r\n", CLS1_GetStdio()->stdErr);
}

void shellSendEndpointShoot(void){
    CLS1_SendStr((unsigned char*)"endpoint shoot hit\r\n", CLS1_GetStdio()->stdErr);
}

void shellSendEndpointLoad(void){
    CLS1_SendStr((unsigned char*)"endpoint load hit\r\n", CLS1_GetStdio()->stdErr);
}

void shellSendShootFinished(void) {
    CLS1_SendStr((unsigned char*)"shoot finished\r\n", CLS1_GetStdio()->stdErr);
}
