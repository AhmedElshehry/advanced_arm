/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  NVIC                                                    */
/*  version    :  V01                                                 */
/*  DATA       : 16/8/2022                                            */
/**************************************************************************/
// include from lib 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
  
// include from drive  
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

//Function to enable interrupt from NVIC
void MNVIC_voidEnableInterrupt(uint8_t capy_u8IntNumber)
 {
	 if(capy_u8IntNumber<=31)
	 {
		 //SET_BIT(NVIC_ISER0,capy_u8IntNumber);
		 NVIC_ISER0 |= (1 << capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=63)
	 {   capy_u8IntNumber=capy_u8IntNumber-32;
		 //SET_BIT(NVIC_ISER1,capy_u8IntNumber);
		 NVIC_ISER1 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=95)
	 {   capy_u8IntNumber-=64;
		 //SET_BIT(NVIC_ISER2,capy_u8IntNumber);
		 NVIC_ISER2 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=127)
	 {   capy_u8IntNumber-=96;
		 //SET_BIT(NVIC_ISER3,capy_u8IntNumber);
		 NVIC_ISER3 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=159)
	 {   capy_u8IntNumber-=128;
		 //SET_BIT(NVIC_ISER4,capy_u8IntNumber);
		 NVIC_ISER4 |= (1<<capy_u8IntNumber);
	 }
	 else
	 {
		 //return error 
	 }	 
	  
 }
 
 //Function to disable interrupt from NVIC
 void MNVIC_voidDisableInterrupt(uint8_t capy_u8IntNumber)
 {
	 if(capy_u8IntNumber<=31)
	 {
		 //SET_BIT(NVIC_ICER0,capy_u8IntNumber);
		 NVIC_ICER0 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=63)
	 {   capy_u8IntNumber-=32;
		 //SET_BIT(NVIC_ICER1,capy_u8IntNumber);
		 NVIC_ICER1 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=95)
	 {   capy_u8IntNumber-=64;
		 //SET_BIT(NVIC_ICER2,capy_u8IntNumber);
		 NVIC_ICER2 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=127)
	 {   capy_u8IntNumber-=96;
		 //SET_BIT(NVIC_ICER3,capy_u8IntNumber);
		 NVIC_ICER3 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=159)
	 {   capy_u8IntNumber-=128;
		 //SET_BIT(NVIC_ICER4,capy_u8IntNumber);
		 NVIC_ICER4 |=(1<<capy_u8IntNumber);
	 }
	 else
	 {
		 //return error 
	 }	 
 }
 
// Function to set Panding flag if want to testing ISR with out peripheral
 void MNVIC_voidSetPendingFalg(uint8_t capy_u8IntNumber)
 {
	 if(capy_u8IntNumber<=31)
	 {
		 NVIC_ISPR0 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=63)
	 {  
         capy_u8IntNumber-=32;
		 NVIC_ISPR1 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=95)
	 {   
         capy_u8IntNumber-=64;
		 NVIC_ISPR2 |= (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=127)
	 {  
         capy_u8IntNumber-=96;
		 NVIC_ISPR1 = (1<<capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=159)
	 {   
         capy_u8IntNumber-=128;
		 NVIC_ISPR2 |= (1<<capy_u8IntNumber);
	 }
	 else
	 {
		 //return error 
	 }	 
	  
 }
 // Funcation clear panding flag 
 void MNVIC_voidClearPendingFalg(uint8_t capy_u8IntNumber)
 {
	 if(capy_u8IntNumber<=31)
	 {
		 NVIC_ICPR0 = 1<<capy_u8IntNumber;
	 }
	 else if(capy_u8IntNumber<=63)
	 {   
         capy_u8IntNumber-=32;
		 NVIC_ICPR1 = 1<<capy_u8IntNumber;
	 }
	 else if(capy_u8IntNumber<=95)
	 {   capy_u8IntNumber-=64;
		 NVIC_ICPR2 = 1<<capy_u8IntNumber;
	 }
	 else if(capy_u8IntNumber<=127)
	 {   
         capy_u8IntNumber-=96;
		 NVIC_ICPR3 = 1<<capy_u8IntNumber;
	 }
	 else if(capy_u8IntNumber<=159)
	 {   
         capy_u8IntNumber-=128;
		 NVIC_ICPR4 = 1<<capy_u8IntNumber;
	 }
	 else
	 {
		 //return error 
	 }	 
	  
 }
 //funcation read active flag
 uint8_t MNVIC_u8GetActiveFalg(uint8_t capy_u8IntNumber)
 {
	 uint8_t local_flag_status;
	 if(capy_u8IntNumber<=31)
	 {
		local_flag_status =GET_BIT(NVIC_IABR0,capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=63)
	 {   capy_u8IntNumber-=32;
		local_flag_status =GET_BIT(NVIC_IABR1,capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=95)
	 {   capy_u8IntNumber-=64;
		local_flag_status =GET_BIT(NVIC_IABR2,capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=127)
	 {   capy_u8IntNumber-=96;
		local_flag_status =GET_BIT(NVIC_IABR3,capy_u8IntNumber);
	 }
	 else if(capy_u8IntNumber<=159)
	 {   capy_u8IntNumber-=128;
		local_flag_status =GET_BIT(NVIC_IABR4,capy_u8IntNumber);
	 }
	 else
	 {
		 //return error 
	 }	 
	 return local_flag_status;
 }
 
 void MNVIC_voidSetPrioirty(uint8_t capy_u8IntIRQ ,uint8_t capy_u8GroupPirorty,uint8_t capy_u8SubPirorty )
  {
 // value of capy_u8SubPirorty | shift value capy_u8GroupPirorty  << number of sub priolaty and group bit
   uint8_t local_priorty=(capy_u8SubPirorty|(capy_u8GroupPirorty<<(((NUMBER_OF_GROUP_SUB)-(GROUP_4_SUB_0))/256)));

 	//cheek the core peripreral
 	if(capy_u8IntIRQ <0)
 	{
 		//code
 	}
	
 	//cheek the external peripheral
 	else if(capy_u8IntIRQ<60)
 	{
 		NVIC_IPR[capy_u8IntIRQ]= local_priortyb << 4;
 	}

 	SCB_AIRCR=NUMBER_OF_GROUP_SUB;
  }

