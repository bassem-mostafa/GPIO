// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef GPIO_INTERNAL_H_
    #define GPIO_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "GPIO_Port.h"
    #include "driver/STM32L496VGT6P/GPIO_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef GPIO_TIM
        #define GPIO_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef GPIO_LOG
        #define GPIO_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define GPIO_NAME       "GPIO"
    #define GPIO_LOG_PREFIX UTIL_StringConcatenateConstant( GPIO_NAME, "> " )

    #ifdef DEBUG
        #define GPIO_Raw( Level, Format, ... ) LOG_Raw( GPIO_LOG, Level, Format, ##__VA_ARGS__ )
        #define GPIO_Trace( Format, ... )      LOG_Trace( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GPIO_Debug( Format, ... )      LOG_Debug( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GPIO_Info( Format, ... )       LOG_Info( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GPIO_Warning( Format, ... )    LOG_Warning( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GPIO_Error( Format, ... )      LOG_Error( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define GPIO_Fatal( Format, ... )      LOG_Fatal( GPIO_LOG, UTIL_StringConcatenateConstant( GPIO_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define GPIO_Raw( Level, Format, ... )
        #define GPIO_Trace( Format, ... )
        #define GPIO_Debug( Format, ... )
        #define GPIO_Info( Format, ... )
        #define GPIO_Warning( Format, ... )
        #define GPIO_Error( Format, ... )
        #define GPIO_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum GPIO_Type
    {
        GPIO_Type_Unknown = 0,
        GPIO_Type_STM32L496VGT6P,
    } GPIO_Type_t;

    typedef struct GPIO_Instance
    {
        GPIO_Type_t Type;

        union
        {
            GPIO_STM32L496VGT6P_t STM32L496VGT6Px;
        };
    } GPIO_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    GPIO_Status_t GPIO_Mode_IsValid( GPIO_Mode_t Mode );
    GPIO_Status_t GPIO_Pull_IsValid( GPIO_Pull_t Pull );

    GPIO_Status_t GPIO_Instance_SetCallbackOnInterrupt( GPIO_t GPIOx, GPIO_CallbackOnInterrupt_t * Callback, GPIO_ContextOnInterrupt_t * Context );

    // The following APIs MUST be provided by the port
    GPIO_Status_t GPIO_IsValid( GPIO_t GPIOx );
    GPIO_Status_t GPIO_Function_IsValid( GPIO_Function_t Function );

    GPIO_Status_t GPIO_Instance_Initialize( GPIO_t GPIOx );
    GPIO_Status_t GPIO_Instance_Cycle( GPIO_t GPIOx );
    GPIO_Status_t GPIO_Instance_DeInitialize( GPIO_t GPIOx );

    GPIO_Status_t GPIO_Instance_SetMode( GPIO_t GPIOx, GPIO_Mode_t Mode );
    GPIO_Status_t GPIO_Instance_SetFunction( GPIO_t GPIOx, GPIO_Function_t Function );
    GPIO_Status_t GPIO_Instance_SetPull( GPIO_t GPIOx, GPIO_Pull_t Pull );

    GPIO_Status_t GPIO_Instance_Commit( GPIO_t GPIOx );

    GPIO_Status_t GPIO_Instance_Write( GPIO_t GPIOx, GPIO_Value_t Value );
    GPIO_Status_t GPIO_Instance_Read( GPIO_t GPIOx, GPIO_Value_t * Value );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* GPIO_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
