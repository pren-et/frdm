/*
 * shell.h
 *
 *  Created on: Mar 7, 2015
 *      Author: Nino
 */

#ifndef UC_HOST_H_
#define UC_HOST_H_

#define PL_HAS_SHELL (1)

/*! \brief Serial driver initialization */
void SHELL_Init(void);

void shellSendDone(void);

#endif /* UC_HOST_H_ */
