/*
 * dio_driver.h
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
    channel0_ID=0,
    channel1_ID=1,
    channel2_ID=2,
    channel3_ID=3,
    channel4_ID=4,
    channel5_ID=5,
    channel6_ID=6,
    channel7_ID=7,
    /*PORTB IDS*/
    channel8_ID=8,
    channel9_ID=9,
    channel10_ID=10,
    channel11_ID=11,
    channel12_ID=12,
    channel13_ID=13,
    channel14_ID=14,
    channel15_ID=15,
    /*PORTC IDS*/
    channel16_ID=16,
    channel17_ID=17,
    channel18_ID=18,
    channel19_ID=19,
    cahnnel20_ID=20,
    channel21_ID=21,
    channel22_ID=22,
    channel23_ID=23,
    /*PORTD IDS*/
    channel24_ID=24,
    channel25_ID=25,
    channel26_ID=26,
    channel27_ID=27,
    channel28_ID=28,
    channel29_ID=29,
    channel30_ID=30,
    cahnnel31_ID=31,
    /*PORTE IDS*/
    channel32_ID=32,
    channel33_ID=33,
    channel34_ID=34,
    channel35_ID=35,
    channel36_ID=36,
    channel37_ID=37,
    /*PORTF IDS*/
    channel38_ID=40,
    channel39_ID=41,
    channel40_ID=42,
    cahnnel41_ID=43,
    channel42_ID=44,
};

/*Defines IDS For Ports*/
enum
{
    PORTA_ID=0,
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
