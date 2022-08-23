/*
 * port_driver.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Ahmed Elshehry
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  portdrive.c
 *        \brief  GPIO General propose input output
 *
 *      \details  The Driver Configure GPIO PIN  port of mode ,direction , alternate function   ,  interrupts pin mode
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "port_driver.h"
#include "tm4c123gh6pmxxx.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define LOCK_REG_VALUE   (uint32_t)(0x4C4F434B)
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
/*******************************************************************************************************************************
 *          the APIs supported by this driver  for  more information about the APIs check the function definitions
 */
/**************************************************************************************************/

/******************************************************************************
* \Syntax          : void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx ,uint8_t EnorDi )
* \Description     : initialize  the Configuration clock  of  GPIO PORT
*                    this function enable and disable peripheral clock given GPIO port
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : EnorDi       the macro Enable and disable the peripheral
* \Parameters (out):   GPIO_RegDef_t refer to GPIO (a,b,c,d,,f,e) that the base address of the GPIO peripheral
* \Return value:   : None
*******************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx ,uint8_t EnorDi )
{
	//to enable port
 if(EnorDi==ENABLE)
 {
	 if(pGPIOx==GPIOA)
	 {
		 GPIOA_PCLK_EN();

	 }else if (pGPIOx==GPIOB)
	 {
		 GPIOB_PCLK_EN();

	 }else if (pGPIOx==GPIOC)
	 {
		 GPIOC_PCLK_EN();

	 }else if (pGPIOx==GPIOD)
	 {
		 GPIOD_PCLK_EN();

	 }else if (pGPIOx==GPIOE)
	 {
		 GPIOE_PCLK_EN();

	 }else if (pGPIOx==GPIOF)
	 {
		 GPIOF_PCLK_EN();

	 }

 }
else
{   //to disable port
	 if(pGPIOx==GPIOA)
	 	 {
	 		 GPIOA_PCLK_DI();

	 	 }else if(pGPIOx==GPIOB)
	 	 {
	 		 GPIOB_PCLK_DI();

	 	 }else if(pGPIOx==GPIOC)
	 	 {
	 		 GPIOC_PCLK_DI();

	 	 }else if(pGPIOx==GPIOD)
	 	 {
	 		 GPIOD_PCLK_DI();

	 	 }else if(pGPIOx==GPIOE)
	 	 {
	 		 GPIOE_PCLK_DI();

	 	 }else if(pGPIOx==GPIOF)
	 	 {
	 		 GPIOF_PCLK_DI();

	 	 }
 }
}

/******************************************************************************
* \Syntax          : void  GPIOPin_Init(GPIO_Handle_t *configPtr)
* \Description     : initialize  the Configuration of pin in GPIO pin and enable clock
*                    the function using bit band ails not read modify write
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): configPtr
* \Return value:   : None
*******************************************************************************/
void GPIOPin_Init(GPIO_Handle_t *pGPIO_Handle)
{	
		/*activate clock for this Pin*/
	BITBAND_PERI( &RCGCGPIO_EN_CLOCK_REG   , GPIO_BASEADDS_TO_CODE(pGPIO_Handle-> pGPIOx) )=ENABLE;
	
	/* can configure the pin will be unlock respect to pin number   */
	pGPIO_Handle-> pGPIOx-> LOCK = LOCK_REG_VALUE;
	BITBAND_PERI( & pGPIO_Handle-> pGPIOx-> CR ,pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET;

	/*to cheek mode type DIO or other peripheral  */
	/* if    0-----> PIN MODE GPIO PERIPHERAL */
	 /*if    1----->  NOT GPIO PERIPHERAL and will be AF peripheral select  */
	 BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->AFSEL , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=pGPIO_Handle->GPIO_PinConfig.GPIO_PinModeType;

/*
 * Configuration the pin diction input ----> 0   output-----> 1
*/
	 BITBAND_PERI( & pGPIO_Handle-> pGPIOx->DIR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=pGPIO_Handle->GPIO_PinConfig.GPIO_PinDirectionType;

/*
 * Configuration the pin Pull up or Pull down Control or not ;
 */
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == GPIO_PU)
	{
		/* PIN configure pull up   */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->PUR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin number to setting pull up resistance

	}
	else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == GPIO_PD)
	{
		/* PIN configure pull down  */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->PDR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin to setting pull down resistance
	}
	else
	{
		/* PIN configure not pull up and not pull down pin as floating    */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->PUR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=RESET; //Write 0 in bit respect to  register pin number to setting  not pull up resistance
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->PDR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=RESET; //Write 0 in bit respect to  register pin to setting not  pull down resistance
	}

/*
 * Configuration the pin Drive Current Control  ;
*/
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinDriveCurrent == DRIVE_CURRENT_2M)
	{
		/* PIN configure DRIVE CURRENT 2M */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->DR2R , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin to setting Drive Current 2mm
	}
	else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == DRIVE_CURRENT_4M)
	{
		/* PIN configure DRIVE CURRENT 4M */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->DR4R , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin to setting Drive Current 4mm
	}
	else
	{
		/* PIN configure DRIVE CURRENT 8M */
		BITBAND_PERI( &pGPIO_Handle-> pGPIOx->DR8R , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin to setting Drive Current 8mm
	}
/*
 * Configuration the pin OPEN DRINE active
*/
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPENDRINE == GPIO_PinOPENDRINE_ENABLE)
	{
		/* PIN configure OPEN DRINE active */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->ODR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=SET; //Write 1 in bit respect to  register pin to setting  OPEN DRINE active

	}
	else
	{
		/* PIN configure OPEN DRINE  not active */
		BITBAND_PERI(  &pGPIO_Handle-> pGPIOx->ODR , pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber )=RESET; //Write 0 in bit respect to  register pin to setting  OPEN DRINE  not active
	}

}
/**********************************************************************************************************************
 *  END OF FILE: port_driver.c
 *********************************************************************************************************************/

