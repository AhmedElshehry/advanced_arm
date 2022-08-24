/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  NVIC                                                    */
/*  version    :  V01                                                 */
/*  DATA       : 16/8/2022                                            */
/**************************************************************************/

#ifndef NVIC_INTERFACE_H 
#define NVIC_INTERFACE_H



// the function to enable  interrupt peripheral at NVIC
 void MNVIC_voidEnableInterrupt( uint8_t capy_u8IntNumber);
 // the function to Disable interrupt peripheral at NVIC
 void MNVIC_voidDisableInterrupt(uint8_t capy_u8IntNumber);
 // the function to enable pending flag  peripheral at NVIC
 void MNVIC_voidSetPendingFalg(uint8_t capy_u8IntNumber);
 // the function to disable pending flag  peripheral at NVIC
 void MNVIC_voidClearPendingFalg(uint8_t capy_u8IntNumber);
 // the function to read active flag  peripheral at NVIC to cheek the interrupt in running out
 uint8_t MNVIC_u8GetActiveFalg(uint8_t capy_u8IntNumber);
 
 //the function to set priority group and sub priority
 void MNVIC_voidSetPrioirty(uint8_t capy_u8IntID ,uint8_t capy_u8GroupPirorty,uint8_t capy_u8SubPirorty ); 
 
 
#endif 
