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
    GPIO_Instance_t Instance[ GPIO_Count ];
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
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            GPIO_Context.Instance[ GPIO_x ].GPIOx = GPIO_x;
        }

        Status = GPIO_Status_Success;
    }
    while ( 0 );

    return Status;
}

static GPIO_Status_t GPIO_Context_Cycle( void )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        Status = GPIO_Status_Success;
    }
    while ( 0 );

    return Status;
}

static GPIO_Status_t GPIO_Context_DeInitialize( void )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( void )", __FUNCTION__ );

        Status = GPIO_Status_Success;
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_GetInstance( GPIO_t GPIOx, GPIO_Instance_t ** Instance )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d, Instance=%p )", __FUNCTION__, GPIOx, Instance );

        if ( Instance == NULL )
        {
            Status = GPIO_Status_ArgumentInvalid;
            break;
        }

        *Instance = &GPIO_Context.Instance[ GPIOx ];

        Status = GPIO_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

GPIO_Status_t GPIO_Initialize( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

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

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_Initialize( &GPIO_Context.Instance[ GPIO_x ] ) ) != GPIO_Status_Success )
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
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

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

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_Cycle( &GPIO_Context.Instance[ GPIO_x ] ) ) != GPIO_Status_Success )
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
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIOx=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_DeInitialize( &GPIO_Context.Instance[ GPIO_x ] ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }

        Status = GPIO_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetMode( GPIO_t GPIOx, GPIO_Mode_t Mode )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Mode=%d )", __FUNCTION__, GPIOx, Mode );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        if ( ( Status = GPIO_Mode_IsValid( Mode ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_SetMode( &GPIO_Context.Instance[ GPIO_x ], Mode ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetFunction( GPIO_t GPIOx, GPIO_Function_t Function )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Function=%d )", __FUNCTION__, GPIOx, Function );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        if ( ( Status = GPIO_Function_IsValid( Function ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_SetFunction( &GPIO_Context.Instance[ GPIO_x ], Function ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetPull( GPIO_t GPIOx, GPIO_Pull_t Pull )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Pull=%d )", __FUNCTION__, GPIOx, Pull );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        if ( ( Status = GPIO_Pull_IsValid( Pull ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_SetPull( &GPIO_Context.Instance[ GPIO_x ], Pull ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_SetCallbackOnInterrupt( GPIO_t GPIOx, GPIO_CallbackOnInterrupt_t Callback, GPIO_ContextOnInterrupt_t Context )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIO=%d, Callback=%p, Context=%p )", __FUNCTION__, GPIOx, Callback, Context );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_SetCallbackOnInterrupt( &GPIO_Context.Instance[ GPIO_x ], Callback, Context ) ) != GPIO_Status_Success )
            {
                Status = GPIO_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

GPIO_Status_t GPIO_Commit( GPIO_t GPIOx )
{
    GPIO_Status_t Status = GPIO_Status_Error;

    do
    {
        GPIO_Trace( "%s( GPIO=%d )", __FUNCTION__, GPIOx );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_Commit( &GPIO_Context.Instance[ GPIO_x ] ) ) != GPIO_Status_Success )
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
    GPIO_Status_t Status = GPIO_Status_Error;
    do
    {
        GPIO_Trace( "%s( GPIO=%d, Value=%d )", __FUNCTION__, GPIOx, Value );

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        // TODO Is it required to add GPIO Value Validation `GPIO_Value_IsValid(...)`

        for ( GPIO_t GPIO_x = GPIO_Null; GPIO_x < GPIO_Count; ++GPIO_x )
        {
            if ( GPIOx != GPIO_All && GPIOx != GPIO_x )
            {
                continue;
            }

            GPIO_Status_t GPIO_Status = GPIO_Status_Success;
            if ( ( GPIO_Status = GPIO_Instance_Write( &GPIO_Context.Instance[ GPIO_x ], Value ) ) != GPIO_Status_Success )
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
    GPIO_Status_t Status = GPIO_Status_Error;
    do
    {
        GPIO_Trace( "%s( GPIO=%d, Value=%p )", __FUNCTION__, GPIOx, Value );

        if ( Value == NULL )
        {
            Status = GPIO_Status_ArgumentInvalid;
            break;
        }

        if ( ( Status = GPIO_IsValid( GPIOx ) ) != GPIO_Status_Success )
        {
            break;
        }

        if ( GPIOx == GPIO_All )
        {
            // TODO Is it required to define a criteria to read all pins ?
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
            if ( ( GPIO_Status = GPIO_Instance_Read( &GPIO_Context.Instance[ GPIO_x ], Value ) ) != GPIO_Status_Success )
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

const char GPIO_VERSION[] = "0.0.0.v20260124-1234";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
