/*
 * dio_driver.c
 *
 *  Created on: Aug 15, 2022
 *      Author: Ahmed Elshehry
 */
/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  DIO DRIVER                                          */
/*  version    :  V01                                                 */
/*  DATA       : 15/8/2022                                            */
/*********************************************************************/
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
#include"tm4c123gh6pm.h"
#include "dio_driver.h"
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
 const uint16_t MASk[MAX_NUM_PIN]={0x004,0x008,0x010,0x020,0x040,0x080,0x100,0x200};
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
    {//   pointer to pin register *((u32 *)GPIOA_BASEADDR+MASk[localPin_id])
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOA_BASEADDR+MASk[localPin_id]));
    }else if(localPort_id==PORTB_ID)
    {
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOB_BASEADDR+MASk[localPin_id]));
    }else if(localPort_id==PORTC_ID)
    {
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOC_BASEADDR+MASk[localPin_id]));
    }else if(localPort_id==PORTD_ID)
    {
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOD_BASEADDR+MASk[localPin_id]));
    }else if(localPort_id==PORTE_ID)
    {
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOE_BASEADDR+MASk[localPin_id]));
    }else if(localPort_id==PORTF_ID)
    {
    	localData_channel=(uint8_t)(*(__vo uint32_t*)(GPIOF_BASEADDR+MASk[localPin_id]));
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
    	//*((u32 *)0x40021000)
    	(*(__vo uint32_t*)(GPIOA_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;

    }else if(localPort_id==PORTB_ID)
    {
    	(*(__vo uint32_t*)(GPIOB_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;
    }else if(localPort_id==PORTC_ID)
    {
    	(*(__vo uint32_t*)(GPIOC_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;
    }else if(localPort_id==PORTD_ID)
    {
    	(*(__vo uint32_t*)(GPIOD_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;
    }else if(localPort_id==PORTE_ID)
    {
    	(*(__vo uint32_t*)(GPIOE_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;
    }else if(localPort_id==PORTF_ID)
    {
    	(*(__vo uint32_t*)(GPIOF_BASEADDR+MASk[localPin_id]))=(uint32_t)Level;
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
	if(PortId>=MIN_NUM_PORTS&& PortId<=MAX_NUM_PORTS)
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
	else
	{
		///#error error to used function or return not ok if using autosar
	}
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
	   	 GPIOA->DATA=(uint32_t)Level;
	       break;
	   case 1:
	   	 GPIOB->DATA=(uint32_t)Level;
	       break;
	   case 2:
	   	 GPIOC->DATA =(uint32_t) Level;
	       break;
	   case 3:
	   	 GPIOD->DATA =(uint32_t) Level;
	       break;
	   case 4:
	   	 GPIOE->DATA =(uint32_t) Level;
	       break;
	   case 5:
	   	 GPIOF->DATA =(uint32_t) Level;
	       break;
	   default:
	       break;
	        }
	  }
	  else
	  {
		///#error error to used function ;
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

void Dio_FlipChannel(Dio_ChannelType ChannelId)
{

}
/**********************************************************************************************************************
 *  END OF FILE: dio_drive.c
 *********************************************************************************************************************/
