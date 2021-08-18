/***************************************************************************************************
                                   BuildStorm.com
 ****************************************************************************************************
 * File:   lib_debug.h
 * Version: 1.0
 * Author: Saheblal Bagwan
 * Description: This file provides the API for serial debugging.
                - Supports runtime configuration of debug logs.
                - Rx is handled by interrupts/DMA
                - Tx is Polling

Copyright © 2021 BuildStorm Private Limited <admin@buildstorm.com>

The software is liscensed to you under End-User License Agreement (EULA) of BuildStorm Software and Firmware Libraries.
A copy of EULA is available for you https://buildstorm.com/eula
**************************************************************************************************/

/***************************************************************************************************
                             Revision History
 ****************************************************************************************************
1.0: Initial version
 ***************************************************************************************************/
#ifndef LIB_DEBUG_H_
#define LIB_DEBUG_H_

#include "stdutils.h"
#include "stm32f4xx_hal.h"

#define GLOBAL_LOG_LEVEL 1
typedef enum
{
    PRINT_LEVEL_NONE = 0,
    PRINT_LEVEL_ERROR = 1,
    PRINT_LEVEL_INFO = 2,
    PRINT_LEVEL_DEBUG = 3,
    PRINT_LEVEL_MAX = 4
} logLevels_et;

#define LOG_LEVEL_MAPPING  \
    {                      \
        'n', 'e', 'i', 'd' \
    }
#define LOG_PASS_CODE "[12345678]"

typedef enum
{
    LIB_MODULE_MAIN_MENU,
    LIB_MODULE_APP_MAIN,
    LIB_MODULE_FLASH,
    LIB_MODULE_OTA,
    LIB_MODULE_SYSTEM,
    LIB_MODULE_MAX
} menusLibModule_et;

#define DEFAULT_LOG_LEVELS {       \
    3, /* LIB_MODULE_MAIN_MENU */  \
    3, /* LIB_MODULE_APP_MAIN  */  \
    2, /* LIB_MODULE_FLASH     */  \
    2, /* LIB_MODULE_OTA     */    \
    3  /* LIB_MODULE_SYSTEM     */   \
};

/***************************************************************************************************
                             Commonly used UART macros/Constants
 ***************************************************************************************************/
#define C_DefaultDigitsToTransmit_U8 0xffu                               // Will transmit the exact digits in the number
#define C_MaxDigitsToTransmit_U8 10u                                     // Max decimal/hexadecimal digits to be transmitted
#define C_NumOfBinDigitsToTransmit_U8 16u                                // Max bits of a binary number to be transmitted
#define C_MaxDigitsToTransmitUsingPrintf_U8 C_DefaultDigitsToTransmit_U8 /* Max dec/hexadecimal digits to be displayed using printf */
/**************************************************************************************************/

extern uint8_t LoggingEnabled_b8;
extern uint8_t LogLevelTable_a8[LIB_MODULE_MAX];
extern uint8_t GlobalLogLevel_u8;

/***************************************************************************************************
                             Function Prototypes
 ***************************************************************************************************/

void UART_rbInit();
void UART_rxIntrWrite(uint8_t ch);
void UART_printf(const char *argList, ...);
void serial_clear();
uint16_t serial_available();
uint8_t serial_read();
void print_sync();
void print_flush();
void print_setLogLevel(uint8_t libModule, uint8_t logLevel);
void print_serial(menusLibModule_et libModule, logLevels_et e_logLevel, const char *funName, const char *argList, ...);

#define print_verbose(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_ERROR, __func__, var_arg_list)
#define print_error(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_ERROR, __func__, var_arg_list)
#define print_info(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_INFO, __func__, var_arg_list)
#define print_debug(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_DEBUG, __func__, var_arg_list)

#define print_verbose_raw(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_ERROR, NULL, var_arg_list)
#define print_error_raw(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_ERROR, NULL, var_arg_list)
#define print_info_raw(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_INFO, NULL, var_arg_list)
#define print_debug_raw(var_arg_list...) print_serial(thisModule, PRINT_LEVEL_DEBUG, NULL, var_arg_list)

/**************************************************************************************************/

#endif /* LIB_DEBUG_H_ */
