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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "GPIO.h"
#include "GPIO_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GPIO_Status_t GPIO_Mode_IsValid( GPIO_Mode_t Mode )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( Mode=%d )", __FUNCTION__, Mode );

        switch ( Mode )
        {
            case GPIO_Mode_Input:
            case GPIO_Mode_Output:
            case GPIO_Mode_OutputOpenDrain:
            case GPIO_Mode_Interrupt:
            case GPIO_Mode_InterruptRising:
            case GPIO_Mode_InterruptFalling:
            case GPIO_Mode_Event:
            case GPIO_Mode_EventRising:
            case GPIO_Mode_EventFalling:
            case GPIO_Mode_AlternateFunction:
            case GPIO_Mode_AlternateFunctionOpenDrain:
                Status = GPIO_Status_Success;
                break;

            default:
                Status = GPIO_Status_ArgumentInvalid;
                break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Pull_IsValid( GPIO_Pull_t Pull )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( Pull=%d )", __FUNCTION__, Pull );

        switch ( Pull )
        {
            case GPIO_Pull_None:
            case GPIO_Pull_Up:
            case GPIO_Pull_Down:
                Status = GPIO_Status_Success;
                break;

            default:
                Status = GPIO_Status_ArgumentInvalid;
                break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Instance_SetCallbackOnInterrupt( GPIO_Instance_t * Instance, GPIO_CallbackOnInterrupt_t * Callback, GPIO_ContextOnInterrupt_t * Context )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( Instance=%p, Callback=%p, Context=%p )", __FUNCTION__, Instance, Callback, Context );

        Instance->OnInterrupt = Callback;
        Instance->OnInterruptContext = Context;
        Status = GPIO_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
