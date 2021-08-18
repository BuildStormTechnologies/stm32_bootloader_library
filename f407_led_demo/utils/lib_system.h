/***************************************************************************************************
                                   BuildStorm.com
 ****************************************************************************************************
 * File:   lib_system.h
 * Version: 1.0
 * Author: Saheblal Bagwan
 * Description: Manages the library functnailty.
                - Takes care of initialization of the library modules.
                - System_init has to be called before calling any library modules.
                - System_sync has be called for managing the library functionality.
                

Copyright © 2021 BuildStorm Private Limited <admin@buildstorm.com>

The software is liscensed to you under End-User License Agreement (EULA) of BuildStorm Software and Firmware Libraries.
A copy of EULA is available for you https://buildstorm.com/eula
**************************************************************************************************/

#ifndef UTILS_LIB_SYSTEM_H_
#define UTILS_LIB_SYSTEM_H_

#include "stdutils.h"
#include "lib_flash.h"

#define LIB_VERSION "1.0.0"

typedef enum
{
    DEVICE_STATE_IDLE,
    DEVICE_STATE_CONFIG,
    DEVICE_STATE_NORMAL,
    DEVICE_STATE_OTA,
    DEVICE_STATE_MAX
} deviceState_et;

void SYSTEM_init();
void SYSTEM_sync();
void SYSTEM_startFirmwareUpdate(firmUpdateType_et e_type);
void SYSTEM_restart();
deviceState_et SYSTEM_getmode();

#endif /* UTILS_LIB_SYSTEM_H_ */
