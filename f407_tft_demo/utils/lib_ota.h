/***************************************************************************************************
                                   BuildStorm.com
 ****************************************************************************************************
 * File:   lib_ota.h
 * Version: 1.0
 * Author: Saheblal Bagwan
 * Description: This module hanldes the firmware update over Serial and HTTP/MQTT.
                

Copyright © 2021 BuildStorm Private Limited <admin@buildstorm.com>

The software is liscensed to you under End-User License Agreement (EULA) of BuildStorm Software and Firmware Libraries.
A copy of EULA is available for you https://buildstorm.com/eula
**************************************************************************************************/

#ifndef LIB_OTA_H_
#define LIB_OTA_H_

#include "stdutils.h"
#include "lib_flash.h"

#define MAX_APP_SIZE (0x1FFFFF) // ( 0x0807FFFF - 0x08010000)

void OTA_init();
void OTA_start(firmUpdateType_et e_updateType);
void OTA_getFirmwarePackets();
firmUpdateType_et OTA_getOtaReqType();
void OTA_sync();
void OTA_saveStatus(otaConfig_st *s_config_p);
uint8_t OTA_getProgressPercentage();

#endif /* LIB_OTA_H_ */
