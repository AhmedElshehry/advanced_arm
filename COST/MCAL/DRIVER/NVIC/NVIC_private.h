/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  NVIC                                                    */
/*  version    :  V01                                                 */
/*  DATA       : 16/8/2022                                            */
/**************************************************************************/
/**************************************************************************/

#ifndef NVIC_PRIVATE_H 
#define NVIC_PRIVATE_H

// 0xE000E000  --> base address of peripheral 
//the register to enable interrupt
//#define   NVIC_ISER0           (*(( __vo uint32_t * )0xE000E100))//enable interrupt peripheral from 0--->31
#define   NVIC_ISER0           *((__vo uint32_t * )0xE000E100)
#define   NVIC_ISER1           (*(( __vo uint32_t * )0xE000E104))//enable interrupt peripheral from 32--->63
#define   NVIC_ISER2           (*(( __vo uint32_t * )0xE000E108))//enable interrupt peripheral from 64--->95
#define   NVIC_ISER3           (*(( __vo uint32_t * )0xE000E10C))//enable interrupt peripheral from 96--->127
#define   NVIC_ISER4           (*(( __vo uint32_t * )0xE000E110))//enable interrupt peripheral from 128--->159

//register to disable or clear  interrupt peripheral
#define   NVIC_ICER0           (*(( __vo uint32_t * )0xE000E180))//DISable interrupt peripheral from 0--->31
#define   NVIC_ICER1           (*(( __vo uint32_t * )0xE000E184))//DISable interrupt peripheral from 32--->63
#define   NVIC_ICER2           (*(( __vo uint32_t * )0xE000E188))//DISable interrupt peripheral from 64--->95
#define   NVIC_ICER3           (*(( __vo uint32_t * )0xE000E18C))//DISable interrupt peripheral from 96--->127
#define   NVIC_ICER4           (*(( __vo uint32_t * )0xE000E190))//DISable interrupt peripheral from 128--->159
//the register to set pending flag 
#define   NVIC_ISPR0           (*(( __vo uint32_t * )0xE000E200))// Register to set pending flag peripheral from 0--->31
#define   NVIC_ISPR1           (*(( __vo uint32_t * )0xE000E204))// Register to set pending flag peripheral from 32--->63
#define   NVIC_ISPR2           (*(( __vo uint32_t * )0xE000E208))// Register to set pending flag peripheral from 64--->95
#define   NVIC_ISPR3           (*(( __vo uint32_t * )0xE000E20C))// Register to set pending flag peripheral from 96--->127
#define   NVIC_ISPR4           (*(( __vo uint32_t * )0xE000E210))// Register to set pending flag peripheral from 128--->159
//the register to clear  pending flag 
#define   NVIC_ICPR0           (*(( __vo uint32_t * )0xE000E280))// Register to clear pending flag peripheral from 0--->31
#define   NVIC_ICPR1           (*(( __vo uint32_t * )0xE000E284))// Register to clear pending flag peripheral from 32--->63
#define   NVIC_ICPR2           (*(( __vo uint32_t * )0xE000E288))// Register to clear pending flag peripheral from 64--->95
#define   NVIC_ICPR3           (*(( __vo uint32_t * )0xE000E28C))// Register to clear pending flag peripheral from 96--->127
#define   NVIC_ICPR4           (*(( __vo uint32_t * )0xE000E290))// Register to clear pending flag peripheral from 128--->159
//the register to read active flag 
#define   NVIC_IABR0           (*(( __vo uint32_t * )0xE000E300)) //the register to read active flag peripheral from 0--->31
#define   NVIC_IABR1           (*(( __vo uint32_t * )0xE000E304)) //the register to read active flag peripheral from 32--->63
#define   NVIC_IABR2           (*(( __vo uint32_t * )0xE000E308)) //the register to read active flag peripheral from 64--->95
#define   NVIC_IABR3           (*(( __vo uint32_t * )0xE000E30C)) //the register to read active flag peripheral from 96--->127
#define   NVIC_IABR4           (*(( __vo uint32_t * )0xE000E310)) //the register to read active flag peripheral from 128--->159

//pointer u8 to  register to set priority of interrupt at the NVIC
#define        NVIC_IPR           (*(( __vo uint8_t * )0xE000E500))

//register to selection  priority of interrupt at the NVIC for the GROUP priority and sub priority
// the base address 0xE000ED00 // offset address 0x0c
#define       SCB_AIRCR             (*(( __vo uint32_t * )0xE000ED0C) )

// MACRO the number of group priority and number sub priority (number of peripheral at group)
#define       GROUP_4_SUB_0          0X05FA0300
#define       GROUP_3_SUB_1          0X05FA0400
#define       GROUP_2_SUB_2          0X05FA0500
#define       GROUP_1_SUB_3          0X05FA0600
#define       GROUP_0_SUB_4          0X05FA0700



#endif 
