/*
 * dio_driver.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Ahmed Elshehry
 */

#ifndef INC_DIO_DRIVER_H_
#define INC_DIO_DRIVER_H_
#include "tm4c123gh6pmxxx.h"

/*
 * DIO Channel Type Typedef that defines which pin number
*/
typedef uint8_t Dio_ChannelType;

/*
 * Dio_PortLevelType Typedef that defines which port value
*/
typedef  uint8_t Dio_PortLevelType ;

/*
 * Dio_LevelType Typedef that defines  which pin value  to high or low
*/
typedef  uint8_t Dio_LevelType ;

/*
 * Dio_PortType Typedef that defines  which number  port id
 *
*/
typedef  uint8_t Dio_PortType  ;

// enum channels IDs of pin GPIO port
enum Channels_IDS
{
    /*PORTA IDS*/
    channel0_ID,
    channel1_ID,
    channel2_ID,
    channel3_ID,
    channel4_ID,
    channel5_ID,
    channel6_ID,
    channel7_ID,
    /*PORTB IDS*/
    channel8_ID,
    channel9_ID,
    channel10_ID,
    channel11_ID,
    channel12_ID,
    channel13_ID,
    channel14_ID,
    channel15_ID,
    /*PORTC IDS*/
    channel16_ID,
    channel17_ID,
    channel18_ID,
    channel19_ID,
    cahnnel20_ID,
    channel21_ID,
    channel22_ID,
    channel23_ID,
    /*PORTD IDS*/
    channel24_ID,
    channel25_ID,
    channel26_ID,
    channel27_ID,
    channel28_ID,
    channel29_ID,
    channel30_ID,
    cahnnel31_ID,
    /*PORTE IDS*/
    channel32_ID,
    channel33_ID,
    channel34_ID,
    channel35_ID,
    channel36_ID,
    channel37_ID,
    /*PORTF IDS*/
    channel38_ID,
    channel39_ID,
    channel40_ID,
    cahnnel41_ID,
    channel42_ID,
    cahnnel43_ID,
};

/*Defines IDS For Ports*/
enum
{
    PORTA_ID,
    PORTB_ID,
    PORTC_ID,
    PORTD_ID,
    PORTE_ID,
    PORTF_ID
};

/*******************************************************************************************************************************
 *          the APIs supported by this driver  for  more information about the APIs check the function definitions
 */

/* the function DIO Read Channel Value of pin   high or low */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* the function DIO Write Channel value of pin  high or low */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* the function DIO Read Port value  Definition*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* the function DIO Write Port value Definition*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* the function Dio_FlipChannel  to used togal pin channel */
void Dio_FlipChannel(Dio_ChannelType Channels_IDS);

#endif /* INC_DIO_DRIVER_H_ */
