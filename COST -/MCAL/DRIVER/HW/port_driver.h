/*
 * port_driver.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Ahmed Elshehry
 */

#ifndef INC_PORT_DRIVER_H_
#define INC_PORT_DRIVER_H_
#include "tm4c123gh6pmxxx.h"
/*
 * @GPIO_PIN_NUMBER
 * this  macro GPIO pin number
 */
#define GPIO_PIN_NO_0           0
#define GPIO_PIN_NO_1           1
#define GPIO_PIN_NO_2           2
#define GPIO_PIN_NO_3           3
#define GPIO_PIN_NO_4           4
#define GPIO_PIN_NO_5           5
#define GPIO_PIN_NO_6           6
#define GPIO_PIN_NO_7           7

/*
 * @GPIO_PIN_MODE_TYPES
 * this  macro possible mode of pin
 */
#define GPIO_MODE_TYPE_DIO        0
#define GPIO_MODE_TYPE_OTHER      1

/*
 * @GPIO_PIN_DRICTION_TYPE
 * this  macro possible GPIO Data Direction of pin
 */

#define GPIO_DRICTION_IN         0
#define GPIO_DRICTION_OUTPUT     1

/*
 * @GPIO_PIN_PULL_UP_DOWN_NO
 * this  macro GPIO pull up  and Pull down
 */
#define GPIO_NO_PU_PD        0
#define GPIO_PU              1
#define GPIO_PD              2

/*
 * @GPIO_PinOPENDRINE
 * this  macro possible output type  pin
 * */
#define  GPIO_PinOPENDRINE_ENABLE               1
#define  GPIO_PinOPENDRINE_DISABLE              0

/*
 * @DRIVE_CURRENT
 * this  macro possible output speed  pin
 */
#define DRIVE_CURRENT_2M 			0
#define DRIVE_CURRENT_4M			1
#define DRIVE_CURRENT_8M			2


 /*
  * the struct pin configure  gpio pin
  */
typedef struct{
	uint8_t GPIO_PinNumber;                      /*  possible values from @GPIO_PIN_NUMBER */
	uint8_t GPIO_PinModeType ;                   /*  possible values from @GPIO_PIN_MODE_TYPES */
	uint8_t GPIO_PinDirectionType;               /*  possible values from @GPIO_PIN_DRICTION_TYPE */
	uint8_t GPIO_PinPuPdControl;                 /*  possible values from @GPIO_PIN_PULL_UP_DOWN_NO  */
	uint8_t GPIO_PinDriveCurrent;                    /*  possible values from @DRIVE_CURRENT  */
	uint8_t GPIO_PinOPENDRINE;                    /*  possible values from @GPIO_PinOPENDRINE  */
}GPIO_PinConfig_t;

/*
 * this is a handle structure for a gpio pin
 */
typedef struct
{
	// pointer to hold the base addresses of gpio peripheral
	GPIO_RegDef_t *pGPIOx; //pointer to hold the base addresses of gpio  port x
    GPIO_PinConfig_t  GPIO_PinConfig ;

}GPIO_Handle_t;

/*-------------------Functions Prototypes----------------------*/

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx ,uint8_t EnorDi );

void GPIOPin_Init(GPIO_Handle_t *pGPIO_Handle);

#endif /* INC_PORT_DRIVER_H_ */
