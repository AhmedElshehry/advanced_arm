/*
 * clock.c
 *
 *  Created on: Aug 17, 2022
 *      Author: Ahmed Elshehry
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  clock.c
 *        \brief  RCC REST clock control system
 *
 *      \details  The Driver Configure Source of system and crystal value and frequency need
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "clock_interface.h"
#include "tm4c123gh6pmxxx.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern Clock_handler_t clock_data;
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
* \Syntax          : void Clock_Init_System(void)
* \Description     : initialize clock system respect to the Configuration
*                    we need
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Clock_Init_System(void)
{

	//Calculator system divtion
	uint8_t SYSDIV = (400/clock_data.required_freq)-1;

	//used  RCC2 register by set bit USEERCC2
	SET_BIT(RCC2_CLOCK_REG,31);

	//the by pass PLL by set bit bypass
	SET_BIT(RCC2_CLOCK_REG,11)
	// select the value crystal
	RCC_CLOCK_REG = (RCC_CLOCK_REG&(0xFFFFF83F))|((clock_data.crystal<<6));
	//Configure source clock internal or external
	RCC2_CLOCK_REG = (RCC2_CLOCK_REG&~((1<<4)|(1<<5)))|(clock_data.source_clock<<4);

	//enable PLL by clear bit PWRDN2 in RCC2 register
	CLR_BIT(RCC2_CLOCK_REG,13);

	//to use 400MHZ PLL set DIV400 bit 30 in RCC2
	SET_BIT(RCC2_CLOCK_REG,30);

	//put the required system divine bit 23 to 28 in RCC2
	RCC2_CLOCK_REG = (RCC2_CLOCK_REG&0xE07FFFFF)|(SYSDIV<<23);

	// wait  PLL is stable and lock by waiting polling   PLLRIS bit  in RIS register is high
	while((RIS_CLOCK_REG&(1<<6)) == 0);

	//enable the PLL
	CLR_BIT(RCC2_CLOCK_REG,11);
}

/**********************************************************************************************************************
 *  END OF FILE: clock.c
 *********************************************************************************************************************/
