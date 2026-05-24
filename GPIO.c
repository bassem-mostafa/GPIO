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

typedef struct GPIO_Context
{
} GPIO_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static GPIO_Status_t GPIO_Context_Initialize( void );
static GPIO_Status_t GPIO_Context_Cycle( void );
static GPIO_Status_t GPIO_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static GPIO_Context_t GPIO_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static GPIO_Status_t GPIO_Context_Initialize( void )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( GPIO_Context );
    }
    while ( 0 );

    return Status;
}

static GPIO_Status_t GPIO_Context_Cycle( void )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( GPIO_Context );
    }
    while ( 0 );

    return Status;
}

static GPIO_Status_t GPIO_Context_DeInitialize( void )
{
    GPIO_Status_t Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( GPIO_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GPIO_Status_t GPIO_Initialize( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_Context_Initialize( ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_Initialize( GPIO_x ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Cycle( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_Context_Cycle( ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_Cycle( GPIO_x ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_DeInitialize( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_DeInitialize( GPIO_x ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }

        if ( ( Status = GPIO_Context_DeInitialize( ) ) != GPIO_Status_Success )
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
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Configuration={Mode=%d, Function=%d, Pull=%d} )", __FUNCTION__, GPIOx, Configuration.Mode, Configuration.Function, Configuration.Pull );

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_Configure( GPIO_x, &Configuration ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetOnInterrupt( GPIO_t GPIOx, GPIO_OnInterrupt_t OnInterrupt )
{
    GPIO_Status_t Status = GPIO_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, OnInterrupt={Callback=%p, Context=%p} )", __FUNCTION__, GPIOx, OnInterrupt.Callback, OnInterrupt.Context );

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_SetOnInterrupt( GPIO_x, &OnInterrupt ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetOnEvent( GPIO_t GPIOx, GPIO_OnEvent_t OnEvent )
{
    GPIO_Status_t Status = GPIO_Status_Success;
    GPIO_Status_t GPIO_Status = GPIO_Status_Success;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, OnEvent={Callback=%p, Context=%p} )", __FUNCTION__, GPIOx, OnEvent.Callback, OnEvent.Context );

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            if ( ( GPIO_Status = GPIO_Port_SetOnEvent( GPIO_x, &OnEvent ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
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

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Port_Write( GPIO_x, Value ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
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

        if ( Value == NULL )
        {
            Status = GPIO_Status_ArgumentInvalid;
            break;
        }

        if ( GPIOx == GPIO_All )
        {
            // TODO Is it required to define a criteria to read all pins?
            Status = GPIO_Status_NotSupported;
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Port_Read( GPIO_x, Value ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char GPIO_VERSION[] = "0.0.0.v20260524-1454";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
