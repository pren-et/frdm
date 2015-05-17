/*
 * DC.h
 *
 *      Author: daniw
 */

#ifndef DC_H_
#define DC_H_

#include "FRTOS1.h"

void DC_init(void);

byte DC_ParseCommand(const unsigned char *cmd, bool *handled, const CLS1_StdIOType *io);

#endif /* DC_H_ */
