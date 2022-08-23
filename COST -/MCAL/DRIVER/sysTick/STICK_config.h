/**********************************************************************/
/*  name       : Ahmed elshehry                                       */
/*  SW         :  SYS TICK                                                     */
/*  version    :  V01                                                 */
/*  DATA       : 25/1/2022                                            */
/*********************************************************************/
#ifndef   STICK_CONFIG_H
#define   STICK_CONFIG_H

 /*  Options clock_sys_tick :
                              1-  STICK_AHB     
                              2-  STICK_AHB_DIV_4     */   
/*STICK_AHB -> that system clock  microcontrol 
*STICK_AHB_DIV_4  ->that system clock  internal 16Mhz      that clock will be =4 mhz */

#define    CLOCK_SYS_TICK   STICK_AHB

#endif
