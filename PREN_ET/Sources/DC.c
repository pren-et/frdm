/*
 * DC.c
 *
 *      Author: daniw
 */

/* Include shared modules, which are used for whole project */

#include "DC.h"
#include "PWM1.h"
#include "DIR.h"
#include "Events.h"
#include <string.h>
#include <stdio.h>

#define DC_DUTY_MIN 0
#define DC_DUTY_MAX 100

uint8_t duty = 0;

void DC_init(void) {
}

static uint8_t PrintStatus(const CLS1_StdIOType *io)
{
    CLS1_SendStatusStr((unsigned char*)"DC Status",(unsigned char*)"\r\n", io->stdOut);

    return ERR_OK;
}

static uint8_t PrintHelp(const CLS1_StdIOType *io)
{
    CLS1_SendHelpStr((unsigned char*)"DC", (unsigned char*)"Group of DC commands\r\n", io->stdOut);
    CLS1_SendHelpStr((unsigned char*)"  help", (unsigned char*)"Print help\r\n", io->stdOut);
    CLS1_SendHelpStr((unsigned char*)"  on|off", (unsigned char*)"Turns it on or off\r\n", io->stdOut);
    CLS1_SendHelpStr((unsigned char*)"  setduty n", (unsigned char*)"Sets duty to n\r\n", io->stdOut);
    return ERR_OK;
}

byte DC_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io)
{
    uint8_t res = ERR_OK;
    unsigned char message[64] = { '\0'};
    int32_t val;
    const unsigned char *p;

    if (UTIL1_strcmp((char*)cmd, CLS1_CMD_HELP) == 0 || UTIL1_strcmp((char*)cmd, "DC help") == 0)
    {
        *handled = TRUE;
        return PrintHelp(io);
    }
    else if ((UTIL1_strcmp((char*)cmd, CLS1_CMD_STATUS) == 0) || (UTIL1_strcmp((char*)cmd, "DC status") == 0))
    {
        *handled = TRUE;
        return ERR_OK;
    }
    else if (UTIL1_strcmp((char*)cmd, "shoot") == 0)
    {
        *handled = TRUE;
        PWM1_SetDutyUS(83);
        PWM1_Enable();
        DC_timer_cnt = 23;
        return ERR_OK;
    }
    else if (UTIL1_strcmp((char*)cmd, "DC on") == 0)
    {
        *handled = TRUE;
        PWM1_Enable();
        DC_timer_cnt = 22;
        return ERR_OK;
    }
    else if (UTIL1_strcmp((char*)cmd, "DC off") == 0)
    {
        *handled = TRUE;
        PWM1_Disable();
        return ERR_OK;
    }
    else if (UTIL1_strcmp((char*)cmd, "DC dir f") == 0)
    {
        DIR_SetVal();
        *handled = TRUE;
        return ERR_OK;
    }
    else if (UTIL1_strcmp((char*)cmd, "DC dir r") == 0)
    {
        DIR_ClrVal();
        *handled = TRUE;
        return ERR_OK;
    }
    else if (UTIL1_strncmp((char*)cmd, "DC setduty ", sizeof("DC setduty")-1) == 0)
    {
        p = cmd+sizeof("DC setduty");
        if (UTIL1_xatoi(&p, &val) == ERR_OK && val >= DC_DUTY_MIN && val <= DC_DUTY_MAX)
        {
            duty = val;
            PWM1_SetDutyUS(duty);
            *handled = TRUE;
        }
        else
        {
            sprintf(message, "Wrong argument, must be in range %i to %i", DC_DUTY_MIN, DC_DUTY_MAX);
            CLS1_SendStr((unsigned char*)message, io->stdErr);
        }
    }
    return ERR_OK;
}
