//#include "BIT_MATH.h"
//#include "tm4c123gh6pmxxx.h"
#include "led.h"
#include "port_driver.h"
#include "STICK_interface.h"


#define TIMEE_COUNTMS 0XB71B00  /*the macro to configuration the timer 1 sec */
static uint32_t Timer_on=  6;// time by secend
static uint32_t Timer_off= 6;// time by secend
void control_Led(void);//call back function control led 

int main(void)
 { 
	/* configration pin led */
	GPIO_Handle_t led ;
	led.pGPIOx=GPIOF;
	led.GPIO_PinConfig.GPIO_PinNumber=GPIO_PIN_NO_2;
	led.GPIO_PinConfig.GPIO_PinModeType=GPIO_MODE_TYPE_DIO;
	led.GPIO_PinConfig.GPIO_PinDirectionType=GPIO_DRICTION_OUTPUT;
	led.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_NO_PU_PD;
	led.GPIO_PinConfig.GPIO_PinDriveCurrent=DRIVE_CURRENT_2M;
	led.GPIO_PinConfig.GPIO_PinOPENDRINE=GPIO_PinOPENDRINE_DISABLE;
  GPIOPin_Init(&led);
	 /*initialtion timer sys tick clock =16 mhz */
	 MSTICK_voidInit();
	 /* enable timer to work */
   MSTICK_voidSetIntervalPeriodic(TIMEE_COUNTMS,control_Led);
  while(1)/*soupper loop */
  {
		
  }
  return 0;
}
 
void control_Led(void)
{
	static uint8_t current_value_timer_on =0,current_value_timer_off=0,stute_led=1;
	/*time on statues */
	if(current_value_timer_on<Timer_on && stute_led==1)
{
	current_value_timer_on++;
	Led_TurnOn(channel40_ID);

}
else if(current_value_timer_off<Timer_off && stute_led==0) /*time on statues */
{
	current_value_timer_off++;
	Led_TurnOff(channel40_ID);
}
if(current_value_timer_on==Timer_on)
{
	stute_led=0;
	current_value_timer_on=0;
}
	if(current_value_timer_off==Timer_off)
{
	stute_led=1;
	current_value_timer_off=0;
}
}
