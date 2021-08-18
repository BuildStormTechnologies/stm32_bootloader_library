/***************************************************************************************************
                                   BuildStorm.com
 ****************************************************************************************************
 * File:   lib_flash.h
 * Version: 1.0
 * Author: Saheblal Bagwan
 * Description: This file provides the API for flash data handling.

Copyright © 2021 BuildStorm Private Limited <admin@buildstorm.com>

The software is liscensed to you under End-User License Agreement (EULA) of BuildStorm Software and Firmware Libraries.
A copy of EULA is available for you https://buildstorm.com/eula
**************************************************************************************************/

#ifndef LIB_FLASH_H_
#define LIB_FLASH_H_

#include "stdutils.h"
/*************************************************************
 *                    ENUMS
 *************************************************************/

#define FLASH_DEFAULT_CONFIG 0x99999999
#define FLASH_VALID_CONFIG 0x55555555

typedef enum
{
    PARTITION_BOOT,
    PARTITION_CONFIG,
    PARTITION_APP1,
    PARTITION_APP2,
    PARTITION_MAX
} flashPartition_et;

typedef enum
{
    OTA_UPDATE_TYPE_NONE,
    OTA_UPDATE_TYPE_INTERNAL,
    OTA_UPDATE_TYPE_SERIAL,
    OTA_UPDATE_TYPE_MAX
} firmUpdateType_et;

typedef enum
{
    OTA_STATUS_READY,
    OTA_STATUS_SUCCESS,
    OTA_STATUS_INTERNAL_UPDATE,
    OTA_STATUS_WRONG_CRC,
    OTA_STATUS_TIMEDOUT,
    OTA_STATUS_FALSH_ERROR,
    OTA_STATUS_MAX
} flashOtaStatus_et;

typedef enum
{
    FLASH_STATUS_TYPE_ALL,
    FLASH_STATUS_TYPE_CHECK,
    FLASH_STATUS_TYPE_FIRMWARE_CRC,
    FLASH_STATUS_TYPE_FIRMWARE_SIZE,
    FLASH_STATUS_TYPE_BOOT_PARTITION,
    FLASH_STATUS_TYPE_OTA_CONFIG,
    FLASH_STATUS_TYPE_MAX
} flashStatusType_et;

/**********************************************************************/

typedef struct
{
    uint32_t firmwareCrc_u32;
    uint32_t firmwareSize_u32;
    flashPartition_et e_bootPartition;
    flashOtaStatus_et e_lastOtaStatus;
    uint8_t bootCount_u8;
} otaConfig_st;

void FLASH_init();
HAL_StatusTypeDef FLASH_erase(uint32_t startSector_u32, uint32_t nbSectors_u32, uint8_t eraseRetries_u8);
void FLASH_sync();
void FLASH_saveConfig();
uint8_t FLASH_getConfig(flashStatusType_et e_type, void *dest_p);
void FLASH_updateConfig(flashStatusType_et e_type, void *config_p);
uint32_t FLASH_getAppSize();

const char *FLASH_getPartitionString(flashPartition_et e_partition);
void FLASH_jumpToApplication();
uint32_t FLASH_getPartitionAddress(flashPartition_et e_partition);
uint32_t FLASH_getSectorIndex(flashPartition_et e_partition);
uint32_t FLASH_getNumOfSectors(flashPartition_et e_partition);

uint8_t FLASH_verfiyAppCrc(uint32_t appStartAddress_u32, uint32_t appSize_u32);
uint32_t FLASH_getStoredCrc(uint32_t appStartAddress_u32, uint32_t appSize_u32);
uint32_t FLASH_calculateAppCrc(uint32_t appStartAddress_u32, uint32_t appSize_u32);

#endif /* LIB_FLASH_H_ */
