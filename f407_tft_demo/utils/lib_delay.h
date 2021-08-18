/***************************************************************************************************
                                   BuildStorm.com
 ****************************************************************************************************
 * File:   lib_delay.h
 * Version: 1.0
 * Author: Saheblal Bagwan
 * Description: This file provides the delay() and millis() API for synchronization.
                - Systick has to be configured to 1ms as this module uses the same for delay calculation.

Copyright © 2021 BuildStorm Private Limited <admin@buildstorm.com>

The software is liscensed to you under End-User License Agreement (EULA) of BuildStorm Software and Firmware Libraries.
A copy of EULA is available for you https://buildstorm.com/eula
**************************************************************************************************/

#ifndef LIB_DELAY_H_
#define LIB_DELAY_H_

#define millis() (HAL_GetTick())

void delay(uint32_t waitTime);

#endif /* LIB_DELAY_H_ */
