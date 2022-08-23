/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  Interrupt  Control                                                    */
/*  version    :  V01                                                 */
/*  DATA       : 21/8/2022                                            */
/*********************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  IntCtrll .c
 *      \brief Interrupt  Control
 *
 *      \details  The Driver Configure Interrupt  Control
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*   include lib */
#include "tm4c123gh6pmxxx.h" 
#include "BIT_MATH.h"
 /* include drive */
#include "IntCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
 static uint32_t Key = 0x05FA0000;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern IntCtrl IntCtrl_Config [Interrupts_Max_IRQNumberConfig];
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
 *     the APIs supported by this driver  for  more information about the APIs check the function definitions
 */

/******************************************************************************
* \Syntax          : void IntCtrl_init (void)
* \Description     : initialize  the interrupt from chose the file configuration
*                     Disable the interrupt and enable interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void IntCtrl_init (void)
{
   uint8_t local_Interrupt_number=0,local_EN_OR_DIS=0,local_Groub_Priority=0,local_Sub_Groub_Priority=0,localRegister_ID=0,localsecation_ID,local_Priority_regs=0,local_Priority_section=0;
   uint16_t  Priority_mode=0;
   uint32_t priority=0;
   for(uint8_t i=0; i<Interrupts_Max_IRQNumberConfig;i++)
   {
   	   local_Interrupt_number =  IntCtrl_Config[i].Interrupt_name;
       local_EN_OR_DIS=          IntCtrl_Config[i].EN_OR_DIS;
   	   local_Groub_Priority=     IntCtrl_Config[i].Groub_Priority;
   	   local_Sub_Groub_Priority= IntCtrl_Config[i].Sub_Groub_Priority;
   	   /* to enable or disable ISR  */
   	  localRegister_ID = local_Interrupt_number/32;
   	  localsecation_ID = local_Interrupt_number%32;
   	  if(local_EN_OR_DIS==ENABLE)
   	  {  /* Enable the interrupt */
   	     SET_BIT((NVIC_ENABLE(localRegister_ID)),localsecation_ID);
   	  }
   	  else
   	  {  /*Disable the interrupt */
   	     SET_BIT(NVIC_DISABLE(localRegister_ID),localsecation_ID);
   	  }

   	/* *******************  set configuration priority **************************** */

   	//to configuration number of groub and sub groub respect to file configuration
              /* 1- 0x00 "XXX" ---> GROUB_priorities =8 ,Sub Groub priorties =1
               2- 0x05 "XXY" ---> GROUB_priorities =4 ,Sub Groub priorties =2
               3- 0X06 "XYY" ---> GROUB_priorities =2 ,Sub Groub priorties =4
               4- 0x07 "YYY" ---> GROUB_priorities =1 ,Sub Groub priorties =8  */
   	  SCB_AIRCR|= Key;
   	  Priority_mode = Interrupt_Priority_Levels;
   	  Priority_mode  = (Priority_mode << 8);
   	  SCB_AIRCR |= Priority_mode;

   	  local_Priority_regs    = (local_Interrupt_number/4);
   	  local_Priority_section =(local_Interrupt_number%32)*8 + 5;
   	  priority = local_Groub_Priority;
   	  priority = priority << local_Priority_section;
         NVIC_PRI( local_Priority_regs) |= priority ;
   }

}
/**********************************************************************************************************************
 *  END OF FILE: Intrctrl.c
 *********************************************************************************************************************/
