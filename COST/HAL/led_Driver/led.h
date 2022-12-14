/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  LED Driver                                        */
/*  version    :  V01                                                 */
/*  DATA       : 22/9/2022                                          */
/*********************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  LED.harderr
 *      \brief  led.h
 *
 *      \details  The Driver Configure   LED Driver
 *
 *********************************************************************************************************************/

#ifndef LED_H
#define LED_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef  Dio_ChannelType Led_ChannelType ;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/******************************************************************************
 * \Syntax             : void Led_TurnOn(Led_ChannelType LedID)
 * \Description        : Function to Turn On the specified led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : LedID  -> ID of Led  
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Led_TurnOn(Led_ChannelType LedID);

/******************************************************************************
 * \Syntax             : void Led_TurnOff(Led_ChannelType LedID)
 * \Description        : Function to Turn off the specified led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : LedID  -> ID of Led  
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Led_TurnOff(Led_ChannelType LedID);

/******************************************************************************
 * \Syntax             : void Led_Toggle(Led_ChannelType LedID)
 * \Description        : Function to Toggle the specified led.
 * \Sync\Async         : Synchronous.
 * \Reentrancy         : NonReentrant.
 * \Parameters (in)    : LedID  -> ID of Led  
 * \Parameters (inout) : None.
 * \Parameters (out)   : None.
 * \Return value:      : None.
 *******************************************************************************/
void Led_Toggle(Led_ChannelType LedID);

 
#endif  /* LED_H */

/**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************/