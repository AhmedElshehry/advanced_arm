/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  SYS TICK                                                     */
/*  version    :  V01                                                 */
/*  DATA       : 25/1/2022                                            */
/*********************************************************************/
#ifndef   STICK_PRIVETE_H
#define   STICK_PRIVETE_H
#include "STD_TYPES.h"
// the  struct definition system timer 
typedef struct 
{    
	__vo  uint32_t  STK_CTRL  ;
	__vo  uint32_t  STK_LOAD  ;
	__vo  uint32_t  STK_CURRENT   ;
}STICK_I ;
//pointer to sturct STICK_I
#define     STICK    ((STICK_I *)0xE000E010)



//the macro choise opation of clock sys tick 
#define   STICK_AHB             0
#define   STICK_AHB_DIV_4       1

// the micro of mode Interval  1- Singal 2-Periodic

#define     STICk_ModeIntervalSingal         0
#define     STICk_ModeIntervalPeriodic       1

#endif 
