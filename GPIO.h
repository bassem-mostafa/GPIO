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

/**
 *  @file
 *
 *  @brief Platform GPIO Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_GPIO GPIO
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_GPIO_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef GPIO_H_
    #define GPIO_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "GPIO_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief GPIO Operation Status
     *
     *  @enum GPIO_Status_t
     */
    typedef enum GPIO_Status
    {
        GPIO_Status_Success = 0,     ///< Success
        GPIO_Status_ArgumentInvalid, ///< Argument Invalid
        GPIO_Status_NotSupported,    ///< Not Supported
        GPIO_Status_Error,           ///< General Error
        GPIO_Status_Busy,            ///< Busy
        GPIO_Status_Timeout,         ///< Timeout
    } GPIO_Status_t;

    /**
     *  @brief GPIO Mode
     *
     *  @enum GPIO_Mode_t
     */
    typedef enum GPIO_Mode
    {
        GPIO_Mode_Default = 0,                ///< Default
        GPIO_Mode_Input,                      ///< Input (High Impedance)
        GPIO_Mode_Output,                     ///< Output (Push-Pull)
        GPIO_Mode_OutputOpenDrain,            ///< Output (Open-Drain)
        GPIO_Mode_Interrupt,                  ///< Interrupt (On Change)
        GPIO_Mode_InterruptRising,            ///< Interrupt (On Rising)
        GPIO_Mode_InterruptFalling,           ///< Interrupt (On Falling)
        GPIO_Mode_Event,                      ///< Event (On Change)
        GPIO_Mode_EventRising,                ///< Event (On Rising)
        GPIO_Mode_EventFalling,               ///< Event (On Falling)
        GPIO_Mode_AlternateFunction,          ///< Alternate Function (Push-Pull)
        GPIO_Mode_AlternateFunctionOpenDrain, ///< Alternate Function (Open-Drain)
    } GPIO_Mode_t;

    /**
     *  @brief GPIO Pull
     *
     *  @enum GPIO_Pull_t
     */
    typedef enum GPIO_Pull
    {
        GPIO_Pull_None = 0, ///< No Pull
        GPIO_Pull_Up,       ///< Pull-Up
        GPIO_Pull_Down,     ///< Pull-Down
    } GPIO_Pull_t;

    /**
     *  @brief GPIO Value
     *
     *  @enum GPIO_Value_t
     */
    typedef enum GPIO_Value
    {
        GPIO_Value_Low = 0, ///< Low
        GPIO_Value_High,    ///< High
    } GPIO_Value_t;

    /**
     *  @brief GPIO Callback Context
     */
    typedef void GPIO_CallbackContext_t;

    /**
     *  @brief GPIO Callback
     */
    typedef GPIO_Status_t( GPIO_Callback_t )( GPIO_t GPIOx, GPIO_CallbackContext_t * Context );

    /**
     *  @brief GPIO On Interrupt Configuration
     *
     *  @struct GPIO_OnInterrupt_t
     */
    typedef struct GPIO_OnInterrupt
    {
        GPIO_Callback_t * Callback;
        GPIO_CallbackContext_t * Context;
    } GPIO_OnInterrupt_t;

    /**
     *  @brief GPIO On Event Configuration
     *
     *  @struct GPIO_OnEvent_t
     */
    typedef struct GPIO_OnEvent
    {
        GPIO_Callback_t * Callback;
        GPIO_CallbackContext_t * Context;
    } GPIO_OnEvent_t;

    /**
     *  @brief GPIO Configuration
     *
     *  @struct GPIO_Configuration_t
     */
    typedef struct GPIO_Configuration
    {
        GPIO_Mode_t Mode;         ///< Mode
        GPIO_Function_t Function; ///< Function
        GPIO_Pull_t Pull;         ///< Pull
    } GPIO_Configuration_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize hardware pin
     *
     *  @note MUST BE called before using any GPIO API
     *
     *  @param[in] GPIOx Pin
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_Initialize( GPIO_t GPIOx );

    /**
     *  @brief Cycle hardware pin
     *
     *  @param[in] GPIOx Pin
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_Cycle( GPIO_t GPIOx );

    /**
     *  @brief DeInitialize hardware pin
     *
     *  @param[in] GPIOx Pin
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_DeInitialize( GPIO_t GPIOx );

    /**
     *  @brief Configure hardware pin
     *
     *  @param[in] GPIOx         Pin
     *  @param[in] Configuration Configuration
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_Configure( GPIO_t GPIOx, GPIO_Configuration_t Configuration );

    /**
     *  @brief Set on-interrupt of hardware pin
     *
     *  @param[in] GPIOx       Pin
     *  @param[in] OnInterrupt On-interrupt configuration
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_SetOnInterrupt( GPIO_t GPIOx, GPIO_OnInterrupt_t OnInterrupt );

    /**
     *  @brief Set on-event of hardware pin
     *
     *  @param[in] GPIOx   Pin
     *  @param[in] OnEvent On-event configuration
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_SetOnEvent( GPIO_t GPIOx, GPIO_OnEvent_t OnEvent );

    /**
     *  @brief Write value to hardware pin
     *
     *  @param[in] GPIOx Pin
     *  @param[in] Value Value to be written
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_Write( GPIO_t GPIOx, GPIO_Value_t Value );

    /**
     *  @brief Read value from hardware pin
     *
     *  @param[in]  GPIOx Pin
     *  @param[out] Value Value to be read pointer
     *
     *  @return GPIO_Status_t
     */
    GPIO_Status_t GPIO_Read( GPIO_t GPIOx, GPIO_Value_t * Value );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char GPIO_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* GPIO_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
