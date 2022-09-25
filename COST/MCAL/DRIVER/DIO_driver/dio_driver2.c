/*
 * dio_driver.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Ahmed Elshehry
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio_driver.c
 *        \brief  DIO driver  Controller Driver GPIO port
 *
 *      \details  The Driver read and write data  All  channel pin and gpio port  in MCU
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/


#include "dio_driver.h"
#include "tm4c123gh6pmxxx.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MIN_NUM_CHANNELS 0
#define MAX_NUM_CHANNELS 43
#define MAX_NUM_PIN      8
#define MIN_NUM_PORTS    0
#define MAX_NUM_PORTS    6
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
* \Description     : read data from channel pin
*                    the function DIO Read Channel Value of pin   high or low
*
*notes :            the function work effect in simulation that develop implement using bit mask address
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId     (u8 data type)
* \Parameters (out): None
* \Return value:   : Dio_LevelType (u8 data type)
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType Channels_IDS)
{
	Dio_LevelType localData_channel=0;
	uint8_t localPort_id=Channels_IDS/8;
    uint8_t localPin_id=Channels_IDS % 8;

    if(localPort_id==PORTA_ID)
    {/*  pointer to pin register BITBAND_PERI*/
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOA_BASEADDR+ GPIOOFFSET_DATA),localPin_id);

    }else if(localPort_id==PORTB_ID)
    {
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOB_BASEADDR+ GPIOOFFSET_DATA),localPin_id);

    }else if(localPort_id==PORTC_ID)
    {
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOC_BASEADDR+ GPIOOFFSET_DATA),localPin_id);
    }else if(localPort_id==PORTD_ID)
    {
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOD_BASEADDR+ GPIOOFFSET_DATA),localPin_id);
    }else if(localPort_id==PORTE_ID)
    {
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOE_BASEADDR+ GPIOOFFSET_DATA),localPin_id);
    }else if(localPort_id==PORTF_ID)
    {
    	localData_channel=(uint8_t) BITBAND_PERI((GPIOF_BASEADDR+ GPIOOFFSET_DATA),localPin_id);
    }
    return localData_channel;

}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
* \Description     : write data in channel pin
*                    the function DIO write Channel Value of pin   high or low
*
*notes :            the function work effect in simulation that develop implement using bit mask address
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in1) : ChannelId   (u8 data type)
* \Parameters (in2) : Level       (u8 data type)
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Dio_WriteChannel(Dio_ChannelType Channels_IDS, Dio_LevelType Level)
{
	uint8_t localPort_id=Channels_IDS/8;
    uint8_t localPin_id=Channels_IDS % 8;

    if(localPort_id==PORTA_ID)
    {
        BITBAND_PERI((GPIOA_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;

    }else if(localPort_id==PORTB_ID)
    {
        BITBAND_PERI((GPIOB_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;
    }else if(localPort_id==PORTC_ID)
    {
    	BITBAND_PERI((GPIOC_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;
    }else if(localPort_id==PORTD_ID)
    {
    	BITBAND_PERI((GPIOD_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;
    }else if(localPort_id==PORTE_ID)
    {
        BITBAND_PERI((GPIOE_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;
    }else if(localPort_id==PORTF_ID)
    {
        BITBAND_PERI((GPIOF_BASEADDR+ GPIOOFFSET_DATA),localPin_id)=Level;
    }
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
* \Description     : read data value  from gpio port and return
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId             (u8 data type)
* \Parameters (out): None
* \Return value:   : Dio_PortLevelType  (u8 data type)
*******************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	/* local value */
	Dio_PortType localPort_Data=0;
	if(PortId>=MIN_NUM_PORTS&& PortId<MAX_NUM_PORTS)
	{
        switch (PortId)
        {
        case 0:
        	localPort_Data =(uint8_t)(GPIOA->DATA);
            break;
        case 1:
        	localPort_Data =(uint8_t)(GPIOB->DATA);
            break;
        case 2:
        	localPort_Data =(uint8_t) (GPIOC->DATA);
            break;
        case 3:
        	localPort_Data =(uint8_t) (GPIOD->DATA);
            break;
        case 4:
        	localPort_Data =(uint8_t) (GPIOE->DATA);
            break;
        case 5:
        	localPort_Data =(uint8_t) (GPIOF->DATA);
            break;
        default:
            break;
        }
        return localPort_Data;
	}
//	else
	//{
	//	/* #error error to used function or return not ok if using autosar */
//	}
	 return localPort_Data;
}
/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
* \Description     : write data value  in gpio port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId             (u8 data type)
* \Parameters (in) : Level              (u8 data type)
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{

	if(PortId>=MIN_NUM_PORTS&& PortId<=MAX_NUM_PORTS)
	{
	   switch (PortId)
	   {
	   case 0:
	   	 GPIOA->DATA=Level;
	       break;
	   case 1:
	   	 GPIOB->DATA=Level;
	       break;
	   case 2:
	   	 GPIOC->DATA =Level;
	       break;
	   case 3:
	   	 GPIOD->DATA =Level;
	       break;
	   case 4:
	   	 GPIOE->DATA =Level;
	       break;
	   case 5:
	   	 GPIOF->DATA =Level;
	       break;
	   default:
	       break;
	        }
	  }
	  else
	  {
		  /* no thing and return error*/
		/*#error error to used function ;*/
	  }
}

/******************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelId);
* \Description     : togel channel pin in gpio port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId             (u8 data type)
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Dio_FlipChannel(Dio_ChannelType Channels_IDS)
{
    uint8_t localPort_id=Channels_IDS/8;
    uint8_t PinNumber=Channels_IDS % 8;

 switch (localPort_id)
	   {
	   case 0:
	   	 GPIOA->DATA^=(1<<PinNumber);
	       break;
	   case 1:
	   	 GPIOB->DATA^=(1<<PinNumber);
	       break;
	   case 2:
	   	 GPIOC->DATA ^=(1<<PinNumber);
	       break;
	   case 3:
	   	 GPIOD->DATA ^=(1<<PinNumber);
	       break;
	   case 4:
	   	 GPIOE->DATA ^=(1<<PinNumber);
	       break;
	   case 5:
	   	 GPIOF->DATA ^=(1<<PinNumber);
	       break;
	   default:
	       break;
	   }


}
/**********************************************************************************************************************
 *  END OF FILE: dio_drive.c
 *********************************************************************************************************************/
