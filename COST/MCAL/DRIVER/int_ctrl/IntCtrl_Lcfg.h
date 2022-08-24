/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Lcfg.h
 *       Module:  
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef IntCtrl_Lcfg_H
#define IntCtrl_Lcfg_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "tm4c123gh6pmxxx.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* the user configuration the IRQ handler ********************* */

#define Interrupts_Max_IRQNumberConfig          3

/* the level  configuration GROUP Pirority and SUb group pirorty  */
/* An x denotes a group priority field bit, and a y denotes a subpriority field bit. */
/*the opation : 1- 0x00 "XXX" ---> GROUB_priorities =8 ,Sub Groub priorties =1 
                2- 0x05 "XXY" ---> GROUB_priorities =4 ,Sub Groub priorties =2
                3- 0X06 "XYY" ---> GROUB_priorities =2 ,Sub Groub priorties =4
                4- 0x07 "YYY" ---> GROUB_priorities =1 ,Sub Groub priorties =8  */
#define Interrupt_Priority_Levels     0x07             

/* **************************************************************** */
#define NVIC_EN(x)         (*((volatile uint32*)(0xE000E100+(x*4))))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
	uint8_t Interrupt_name;
	uint8_t EN_OR_DIS;
	uint8_t Groub_Priority;
	uint8_t Sub_Groub_Priority;

}IntCtrl;
/**********************************************************************************************************************/
/* configration the ISR priority
static IntCtrl IntCtrl_Config [Interrupts_Max_IRQNumberConfig] =
{
/*  {Interrupt ,EN_OR_DIS , Groub_priorirt , Sub_groub_priority}

	{  GPIO_Port_A    , ENABLE   ,   1       ,   0          },
	{  GPIO_Port_B    , ENABLE   ,   2       ,   1          },
	{  Timer_0A       , ENABLE   ,   3       ,   1          }
	
};                  */

static IntCtrl IntCtrl_Config [Interrupts_Max_IRQNumberConfig] =
{
/*  {Interrupt ,EN_OR_DIS , Groub_priorirt , Sub_groub_priority} */

	{  GPIO_Port_A    , ENABLE   ,   1       ,   0          },
	{  GPIO_Port_B    , ENABLE   ,   2       ,   1          },
	{  Timer_0A       , ENABLE   ,   3       ,   1          }

};

#endif  /* INTCTRL_LCG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_lcfg.h
 *********************************************************************************************************************/



