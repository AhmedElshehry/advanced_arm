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

 }else
 {   //to disable port
	 if(pGPIOx==GPIOA)
	 	 {
	 		 GPIOA_PCLK_DI();

	 	 }else if (pGPIOx==GPIOB)
	 	 {
	 		 GPIOB_PCLK_DI();

	 	 }else if (pGPIOx==GPIOC)
	 	 {
	 		 GPIOC_PCLK_DI();

	 	 }else if (pGPIOx==GPIOD)
	 	 {
	 		 GPIOD_PCLK_DI();

	 	 }else if (pGPIOx==GPIOE)
	 	 {
	 		 GPIOE_PCLK_DI();

	 	 }else if (pGPIOx==GPIOF)
	 	 {
	 		 GPIOF_PCLK_DI();

	 	 }
 }
}

/******************************************************************************
* \Syntax          : void  GPIOPin_Init(GPIO_Handle_t *configPtr)
* \Description     : initialize  the Configuration of pin in GPIO port
*
* \Sync\Async      : Synchronous
* \Reentrancy      :  non Reentrant
* \Parameters (in) : None
* \Parameters (out): configPtr
* \Return value:   : None
*******************************************************************************/
void  GPIOPin_Init(GPIO_Handle_t *pGPIO_Handle)
{
/* can configure the pin will be unlock respect to pin number   */
	pGPIO_Handle-> pGPIOx-> LOCK = LOCK_REG_VALUE;
	pGPIO_Handle-> pGPIOx-> CR |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);

	/*to cheek mode type DIO or other peripheral*/

	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinModeType <= GPIO_MODE_TYPE_DIO)
	{
		/* PIN MODE GPIO PERIPHERAL */
		pGPIO_Handle-> pGPIOx->AFSEL &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number  that the setting configure

	}
	else
	{
		/* PIN MODE  NOT GPIO PERIPHERAL and will be AF peripheral select  */
		pGPIO_Handle-> pGPIOx->AFSEL &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number  can be write it
		pGPIO_Handle-> pGPIOx->AFSEL |=(1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number  that the setting configure to work signal peripheral
	}
/*
 * Configuration the pin diction input or output
 * */
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinDirectionType == GPIO_DRICTION_IN)
	{
		/* PIN dercition as input */
		pGPIO_Handle-> pGPIOx->DIR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number that the setting configure
	}
	else
	{
		/* PIN dercition as output */
		pGPIO_Handle-> pGPIOx->DIR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number can be write it
		pGPIO_Handle-> pGPIOx->DIR  |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number that the setting configuration
	}
/*
 * Configuration the pin Pull up or Pull down Control or not ;
 * */
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == GPIO_PU)
	{
		/* PIN configure pull up   */
		pGPIO_Handle-> pGPIOx->PUR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
		pGPIO_Handle-> pGPIOx->PUR  |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting pull up resistance
	}
	else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == GPIO_PD)
	{
		/* PIN configure pull down  */
				pGPIO_Handle-> pGPIOx->PDR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
				pGPIO_Handle-> pGPIOx->PDR  |=  (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting pull up resistance
	}
	else
	{
		/* PIN configure not pull up and not pull down pin as floating    */
				pGPIO_Handle-> pGPIOx->PDR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number to setting no pull down resistance
				pGPIO_Handle-> pGPIOx->PUR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number to setting no pull up resistance
	}

/*
 * Configuration the pin Drive Current Control  ;
 * */
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinDriveCurrent == DRIVE_CURRENT_2M)
	{
		/* PIN configure DRIVE CURRENT 2M */

		pGPIO_Handle-> pGPIOx->DR2R  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
		pGPIO_Handle-> pGPIOx->DR2R  |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting  Drive Current 2mm

	}
	else if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl == DRIVE_CURRENT_4M)
	{
		/* PIN configure DRIVE CURRENT 4M */
		pGPIO_Handle-> pGPIOx->DR4R  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
		pGPIO_Handle-> pGPIOx->DR4R  |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting  Drive Current 4mm
	}
	else
	{
		/* PIN configure DRIVE CURRENT 4M */
		pGPIO_Handle-> pGPIOx->DR8R  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
		pGPIO_Handle-> pGPIOx->DR8R  |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting  Drive Current 8mm

	}
/*
 * Configuration the pin OPEN DRINE active
 * */
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPENDRINE == GPIO_PinOPENDRINE_ENABLE)
	{
		/* PIN configure OPEN DRINE active */
        pGPIO_Handle-> pGPIOx->ODR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number
		pGPIO_Handle-> pGPIOx->ODR  |= (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //set bit respect to pin number to setting  OPEN DRINE active
	}
	else
	{
		/* PIN configure OPEN DRINE  not active */
		pGPIO_Handle-> pGPIOx->ODR  &= ~ (1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber); //clearing bit respect to pin number not active open drine
	}

}
/**********************************************************************************************************************
 *  END OF FILE: port_driver.c
 *********************************************************************************************************************/

