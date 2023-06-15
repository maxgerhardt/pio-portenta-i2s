#ifndef _I2C_INIT_H
#define _I2C_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"
extern I2S_HandleTypeDef hi2s1;

void MX_GPIO_Init(void);
void MX_I2S1_Init(void);

#ifdef __cplusplus
}
#endif

#endif