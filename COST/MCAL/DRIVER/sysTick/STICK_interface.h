/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  SYS TICK                                                     */
/*  version    :  V01                                                 */
/*  DATA       : 25/1/2022                                            */
/*********************************************************************/
#ifndef   STICK_INTERFACE_H
#define   STICK_INTERFACE_H
#include "STD_TYPES.h"

 
/* the function  Init the clock of systick from choose the file configuration and initalition system timer */
void MSTICK_voidInit(void );

/* the  synchonious function counter timer  the value that as  delay  */
void MSTICK_voidSetBusyWait( uint32_t capy_u32Ticks );

// the  Asynchonious function counter timer  the value that as  delay by one shoot not repated
void MSTICK_voidSetIntervalSingle(uint32_t capy_u32Ticks, void (*capy_ptr)(void));

// the  Asynchonious function counter timer the value that as delay by repated
void MSTICK_voidSetIntervalPeriodic(uint32_t capy_u32Ticks, void (*capy_ptr)(void));
//the function to stop time 
void MSTICK_voidStopTimer(void);
// the function to get value of ticks elapsed form start
uint32_t  MSTICK_u32GetElapsedTime(void );
// the function to get value of ticks to action interrupt  flag
uint32_t  MSTICK_u32GetRemainingTime(void );
void SysTick_Handler(void);
#endif 
