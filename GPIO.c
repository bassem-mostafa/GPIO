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

GPIO_Status_t GPIO_Initialize( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_Port_Initialize( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Cycle( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_Port_Cycle( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_DeInitialize( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_Port_DeInitialize( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Configure( GPIO_t GPIOx, GPIO_Configuration_t Configuration )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Configuration={Mode=%d, Function=%d, Pull=%d} )", __FUNCTION__, GPIOx, Configuration.Mode, Configuration.Function, Configuration.Pull );

        if ( ( Status = GPIO_Port_Configure( GPIOx, &Configuration ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetOnInterrupt( GPIO_t GPIOx, GPIO_OnInterrupt_t OnInterrupt )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, OnInterrupt={Callback=%p, Context=%p} )", __FUNCTION__, GPIOx, OnInterrupt.Callback, OnInterrupt.Context );

        if ( ( Status = GPIO_Port_SetOnInterrupt( GPIOx, &OnInterrupt ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Write( GPIO_t GPIOx, GPIO_Value_t Value )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Value=%d )", __FUNCTION__, GPIOx, Value );

        if ( ( Status = GPIO_Port_Write( GPIOx, Value ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Read( GPIO_t GPIOx, GPIO_Value_t * Value )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Value=%p )", __FUNCTION__, GPIOx, Value );

        if ( ( Status = GPIO_Port_Read( GPIOx, Value ) ) != GPIO_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char GPIO_VERSION[] = "0.0.0.v20260913-1832";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
