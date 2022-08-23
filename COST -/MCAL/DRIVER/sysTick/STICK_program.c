/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  SYStem Timer                                                      */
/*  version    :  V01                                                 */
/*  DATA       : 21/8/2022                                            */
/*********************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**     \file  stick_program.c
 *      \brief  System Timer systick  
 *
 *      \details  The Driver Configure  System Timer 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
/*   include lib */
#include "tm4c123gh6pmxxx.h"
#include "BIT_MATH.h"

 /* include drive */
 
#include  "STICK_interface.h"
#include  "STICK_private.h"
#include  "STICK_config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//the define the Galobal in the file STICk_mode_interval 
static uint8_t  STICk_u8ModeInterval ; 
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
//the define call back  globel variable    (pointer to function)  
static void (* STICK_CallBack)(void);
/*******************************************************************************************************************************
 *     the APIs supported by this driver  for  more information about the APIs check the function definitions
 */

/******************************************************************************
* \Syntax          : void MSTICK_voidInit(void )
* \Description     : initialize  the clock of systick from choise the file configration 
*                     Disable the sys tick system & Disable  interrupt the sys tick 
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : NOna     
* \Parameters (out): nona
* \Return value:   : None
*******************************************************************************/

void MSTICK_voidInit(void )
{
	
	#if CLOCK_SYS_TICK== STICK_AHB
	    
	   //set bit 2 to enable seclect the clock AHB 
	   //clear bit 0 to disable the sys tick  
	   //clear bit 1 to disable interrupt sys tick
        STICK -> STK_CTRL =0x00000004;	
       //difrent mathoud way
       //SET_BIT(STICK -> STK_CTRL, 2 );   
       //CLR_BIT(STICK -> STK_CTRL, 0 );   
       //CLR_BIT(STICK -> STK_CTRL, 1 );   
	
	
	#elif CLOCK_SYS_TICK == STICK_AHB_DIV_4
	   //clear bit 2 to enable seclect the clock AHB/4 
	   //clear bit 0 to disable the sys tick  
	   //clear bit 1 to disable interrupt sys tick
        STICK -> STK_CTRL =0x00000000;	
        //difrent mathoud way
        //CLR_BIT(STICK -> STK_CTRL, 2 );   
        //CLR_BIT(STICK -> STK_CTRL, 0 );   
        //CLR_BIT(STICK -> STK_CTRL, 1 ); 
	#else 
		#error "the error choise to file config "
	
	
	#endif 
}                       

/******************************************************************************
* \Syntax          : void MSTICK_voidSetBusyWait( uint32_t capy_u32Ticks )
* \Description     : the synchonious function counter timer  the value that as  delay 
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : capy_u32Ticks     
* \Parameters (out): nona
* \Return value:   : None
*******************************************************************************/
void MSTICK_voidSetBusyWait( uint32_t capy_u32Ticks )
{
	//move value tick  to register load 
	STICK -> STK_LOAD = capy_u32Ticks;
	
	//enable the counter to count 
	SET_BIT(STICK -> STK_CTRL, 0 ); 
	
	//Wait the flag can be 1 the counter finshed  
	while( ( GET_BIT(STICK -> STK_CTRL, 16 ) )==0);
	//disable the counter to count 
	CLR_BIT(STICK -> STK_CTRL, 0 );
	// clear the register load and value 
	STICK -> STK_LOAD=0;
	STICK -> STK_CURRENT =0;
	
}
/******************************************************************************
* \Syntax          : void MSTICK_voidSetIntervalSingle(uint32_t capy_u32Ticks, void (*capy_ptr)(void))
* \Description     : the  Asynchonious function counter timer  the value that as  delay by one shoot not repated 
*             
* \Sync\Async      : ASynchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : capy_u32Ticks     
* \Parameters (out): void (*capy_ptr)(void)
* \Return value:   : None
*******************************************************************************/
void MSTICK_voidSetIntervalSingle(uint32_t capy_u32Ticks, void (*capy_ptr)(void))
{
    //set STICk Mode Interval 
	STICk_u8ModeInterval= STICk_ModeIntervalSingal;
	//move value tick  to register load 
	STICK -> STK_LOAD = capy_u32Ticks;
	
	//enable the counter to start count 
	SET_BIT(STICK -> STK_CTRL, 0 );
	
	//pass address the funcatio to call back and save 
	STICK_CallBack = capy_ptr;
    //enable the interrupt 
	SET_BIT(STICK -> STK_CTRL, 1 );
	
}
/******************************************************************************
* \Syntax          : void MSTICK_voidSetIntervalPeriodic(uint32_t capy_u32Ticks, void (*capy_ptr)(void))
* \Description     : the Asynchonious function counter timer  the value that as  delay by repated 
*             
* \Sync\Async      : ASynchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : capy_u32Ticks     
* \Parameters (out): void (*capy_ptr)(void)
* \Return value:   : None
*******************************************************************************/
void MSTICK_voidSetIntervalPeriodic(uint32_t capy_u32Ticks, void (*capy_ptr)(void))
{
	//set STICk ModeIntervalPeriodic 
	STICk_u8ModeInterval= STICk_ModeIntervalPeriodic;
	//move value tick  to register load 
	STICK -> STK_LOAD = capy_u32Ticks;
	
	//enable the counter to start count 
	SET_BIT(STICK -> STK_CTRL, 0 );
	
	//pass address the funcatio to call back and save 
	STICK_CallBack = capy_ptr;
	
	//enable the interrupt 
	SET_BIT(STICK -> STK_CTRL, 1 );
}
/******************************************************************************
* \Syntax          : void MSTICK_voidStopTimer(void)
* \Description     : the synchonious function the function to stop time 
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : none    
* \Parameters (out): none
* \Return value:   : None
*******************************************************************************/
void MSTICK_voidStopTimer(void)
{       
     //disable the interrupt 
	 CLR_BIT((STICK -> STK_CTRL), 1 ); 
	 //disable counter 
	 CLR_BIT(STICK -> STK_CTRL, 0 );
	
	 // clear the register load and value 
	 STICK -> STK_LOAD=0;
	 STICK -> STK_CURRENT =0;
}
/******************************************************************************
* \Syntax          : uint32_t  MSTICK_u32GetElapsedTime(void )
* \Description     : the synchonious function to get value of ticks elapsed form start 
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : none    
* \Parameters (out): none
* \Return value:   : uint32_t  value ElapsedTime
*******************************************************************************/
uint32_t  MSTICK_u32GetElapsedTime(void )
{
	uint32_t local_u32returnvalue =((STICK -> STK_LOAD)-(STICK -> STK_CURRENT ));
	// return the value ElapsedTime
	return local_u32returnvalue;
}
/******************************************************************************
* \Syntax          : uint32_t  MSTICK_u32GetRemainingTime(void )
* \Description     : the synchonious function to get value of ticks to action interrupt  flag 
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : none    
* \Parameters (out): none
* \Return value:   : uint32_t  value of CURRENT timer
*******************************************************************************/
uint32_t  MSTICK_u32GetRemainingTime(void )
{
	uint32_t local_u32returnvalue =((STICK -> STK_CURRENT ));
	return local_u32returnvalue;
}

/******************************************************************************
* \Syntax          : uint32_t  MSTICK_u32GetRemainingTime(void )
* \Description     : the  function to handler ISR system timer sys_Tick
*             
*
* \Sync\Async      : Synchronous
* \Reentrancy      : non Reentrant
* \Parameters (in) : none    
* \Parameters (out): none
* \Return value:   : none
*******************************************************************************/
void SysTick_Handler(void)
{
	uint8_t local_flag=0;
	if(STICk_u8ModeInterval == STICk_ModeIntervalSingal)
	{
		//disable the interrupt 
		CLR_BIT(STICK -> STK_CTRL, 1 );   
        
		//disable the counter to count 
		// stop timer val & load 0 
	    CLR_BIT(STICK -> STK_CTRL, 0 );
	    // clear the register load and value 
	    STICK -> STK_LOAD=0;
	    STICK -> STK_CURRENT =0;
	}
	// call the nafication function 
	STICK_CallBack();
	// the clear flag form read 
	local_flag=(GET_BIT(STICK -> STK_CTRL, 16 ));
}
/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/
