/*
 * clock_interface.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Ahmed Elshehry
 */

#ifndef INC_CLOCK_INTERFACE_H_
#define INC_CLOCK_INTERFACE_H_

// the option crystal external or internal
typedef enum{	EXTERNAL_CRYSTAL = 0x0,INTERNAL_OSC = 0x1}clock_source_system;
//there are more crystal option
typedef enum{MH_3_579545=0x4,MH_3_6864=0x5,MH_4 = 0x6,MH_4_096= 0x7,MH_16 = 0x15}Crystal_value ;  //there are more crystal option

// the strut to configuration handler clock system
typedef struct
{
	clock_source_system source_clock;
	Crystal_value crystal;
	//unit8_t required_freq;

}Clock_handler_t;

extern Clock_handler_t clock_data ;

/******************************************the prototype function************************************************************************* */

void Clock_Init_System(void);


#endif /* INC_CLOCK_INTERFACE_H_ */
