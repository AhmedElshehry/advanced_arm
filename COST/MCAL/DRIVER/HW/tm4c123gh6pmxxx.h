/*
 * tm4c123gh6pm.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Ahmed Elshehry
 */

#ifndef INC_TM4C123GH6PMxxx_H_
#define INC_TM4C123GH6PMxxx_H_

/*the include to used  */

#include <stdint.h>

//the macro initiation value
#define __vo volatile
#define __I volatile const
#define    ENABLE            1
#define    DISABLE           0
#define   SET                ENABLE
#define   RESET              DISABLE
#define   GPIO_PIN_SET       SET
#define   GPIO_PIN_RESET     RESET
/*
 ***************************START :Processor Specific Details ********************************
 *
 * ARM Cortex Mx processor NVIC ISRRX pointer  register Addresses
 */

#define  SCB_AIRCR         (*(( __vo uint32_t * )0xE000ED0C) )

#define NVIC_ENABLE(x)     (*(( __vo uint32_t *)(0xE000E100+(x*4))))
#define NVIC_DISABLE(x)    (*(( __vo uint32_t *)(0xE000E180+(x*4))))
#define NVIC_PRI(x)        (*(( __vo uint32_t *)(0xE000E400+(x*4))))
/*
 * that macro addresses of  memory Flash and SRAM
 */
#define   FLASH_BASEADDR                 0x00000000U
#define   SRAM_BIT_BAND_EDBASEADDR       0x20000000U        //Base Address of SRAM bit_band
#define   SRAM_BIT_BAND_ALIASBASEADDR    0x22000000U        //Base Address of SRAM alias band


/************************************************************************/
/**Peripherals Bit Banding**/
#define BITBAND_PERIPHREAL_BASE 0x40000000 // Base Address of peripheral bit-band
#define ALIAS_PERIPHERAL_BASE   0x42000000 // base address of peripheral bit band alias

/***this formula to use bit banding on peripherals that as pointer to register ***********/
#define BITBAND_PERI(PERI_ADDRESS,BIT)  (*((__vo uint32_t *)( ALIAS_PERIPHERAL_BASE + (((uint32_t )PERI_ADDRESS - BITBAND_PERIPHREAL_BASE)*32) +(BIT*4)) ))
/***this formula to use bit banding on SRAM***/
#define BITBAND_SRAM(SRAM_ADDRESS,BIT)	(*((__vo uint32_t*)( SRAM_BIT_BAND_ALIASBASEADDR + (((uint32_t )SRAM_ADDRESS - SRAM_BIT_BAND_EDBASEADDR)*32) + (BIT*4)) ))
//set value
//#define SET_BIT_BITBAND_PERI(PERI_ADDRESS,BIT)   ((*((__vo uint32_t *)( ALIAS_PERIPHERAL_BASE + (((uint32_t )(PERI_ADDRESS) - BITBAND_PERIPHREAL_BASE)*32) +(BIT*4))))=SET)
//clear value
//#define clear_BIT_BITBAND_PERI(PERI_ADDRESS,BIT)   ((*((__vo uint32_t *)( ALIAS_PERIPHERAL_BASE + (((uint32_t )(PERI_ADDRESS) - BITBAND_PERIPHREAL_BASE)*32) +(BIT*4))))=RESET)
/***this formula to use bit banding on SRAM***/
//#define SET_BIT_BITBAND_SRAM(SRAM_ADDRESS,BIT)	 ((*((__vo uint32_t *)( SRAM_BIT_BAND_ALIASBASEADDR + (((uint32_t )(SRAM_ADDRESS) - BITBAND_PERIPHREAL_BASE)*32) +(BIT*4))))=SET)
/************************************************************************/
/*
 * Base addresses of peripherals which are hanging on AHB1 Bus
 * that all the peripherals in the Bus
 */

// the base addresses in APB BUS
#define GPIOA_BASEADDR                             ( 0x40004000U )
#define GPIOB_BASEADDR                             ( 0x40005000U )
#define GPIOC_BASEADDR                             ( 0x40006000U )
#define GPIOD_BASEADDR                             ( 0x40007000U )
#define GPIOE_BASEADDR                             ( 0x40024000U )
#define GPIOF_BASEADDR                             ( 0x40025000U )
#define GPIOOFFSET_DATA                             ( 0x3FC )


/************************************************************************/

/**************peripheral register definition structures****************/
/*
 * note : register of peripheral are specification to MCU
 * Definition the structures GPIO Register    */

typedef struct
{
	__vo uint32_t RESERVED0[255];
	__vo uint32_t DATA;// that the address data of data register to used write data all pin  3FC
	__vo uint32_t DIR;
	__vo uint32_t IS;
	__vo uint32_t IBE;
	__vo uint32_t IEV;
	__vo uint32_t IM;
	__vo uint32_t RIS;
	__vo uint32_t MIS;
	__vo uint32_t ICR;
	__vo uint32_t AFSEL;
	__vo  uint32_t RESERVED1[55];
	__vo uint32_t DR2R;
	__vo uint32_t DR4R;
	__vo uint32_t DR8R;
	__vo uint32_t ODR;
	__vo uint32_t PUR;
	__vo uint32_t PDR;
	__vo uint32_t SLR;
	__vo uint32_t DEN;
	__vo uint32_t LOCK;
	__vo uint32_t CR;
	__vo uint32_t AMSEL;
	__vo uint32_t PCTL;
	__vo uint32_t ADCCTL;
	__vo uint32_t DMACTL;

}GPIO_RegDef_t;

/*
 *  Definition the struct EXTI Register
 */

/*
 * peripheral definitions Base address  */
/*
 *    GPIOx peripheral
 */
//Pointer of struct at  the Base address APB
#define GPIOA      ((GPIO_RegDef_t *)GPIOA_BASEADDR )
#define GPIOB      ((GPIO_RegDef_t *)GPIOB_BASEADDR )
#define GPIOC      ((GPIO_RegDef_t *)GPIOC_BASEADDR )
#define GPIOD      ((GPIO_RegDef_t *)GPIOD_BASEADDR )
#define GPIOE      ((GPIO_RegDef_t *)GPIOE_BASEADDR )
#define GPIOF      ((GPIO_RegDef_t *)GPIOF_BASEADDR )

 /*
  *    RCC peripheral
 */
/*the macro define  some the register RCC */
#define RIS_CLOCK_REG   (*((__vo uint32_t *)0x400FE050))
#define RCC_CLOCK_REG   (*((__vo uint32_t *)0x400FE060))
#define RCC2_CLOCK_REG  (*((__vo uint32_t *)0x400FE070))

#define RCGCGPIO_EN_CLOCK_REG    (*((__vo uint32_t *)0x400FE608))



/*the vector table interrupt handalr*/
#define GPIO_Port_A               0
#define GPIO_Port_B               1
#define GPIO_Port_C               2
#define GPIO_Port_D               3
#define GPIO_Port_E               4
#define UART0                     5
#define UART1                     6
#define SSI0                      7
#define I2C0                      8 
#define PWM0_Fault                9
#define PWM0_Generator_0          10
#define PWM0_Generator_1          11 
#define PWM0_Generator_2          12
#define QEI0                      13
#define ADC0_Sequence_0           14
#define ADC0_Sequence_1           15
#define ADC0_Sequence_2           16
#define ADC0_Sequence_3           17
#define Watchdog_Timers_0         18
#define Timer_0A                  19          
#define Timer_0B                  20
#define Timer_1A                  21
#define Timer_1B                  22
#define Timer_2A                  23
#define Timer_2B                  24
#define Analog_Comparator_0       25
#define Analog_Comparator_1       26
#define System_Control            27
#define Flash_Memory_Control      28
#define GPIO_Port_F               29
#define UART2                     30
#define SSI1                      31
#define Timer_3A                  32
#define Timer_3B                  33
#define I2C1                      34
#define QEI1                      35
#define CAN0                      36
#define CAN1                      37
#define Hibernation_Module        38
#define USB                       39
#define PWM_Generator_3           40
#define ADC1_Sequence_3           46
#define SSI2                      47
#define SSI3                      48
#define UART3                     49
#define UART4                     50
#define UART5                     51
#define UART6                     52
#define UART7                     53
#define I2C2                      54
#define I2C3                      55
#define Timer_4A                  56
#define Timer_4B                  57
#define Timer_5A                  58
#define Timer_5B                  59
#define Timer0A                  60
#define Timer0B                  61
#define Timer1A                  62
#define Timer1B                  63
#define Timer2A                  64
#define Timer2B                  65
#define Timer3A                  66
#define Timer3B                  67
#define Timer4A                  68
#define Timer4B                  69
#define Timer5A                  70
#define Timer5B                  71
#define PWM1_Generator_0          72
#define PWM1_Generator_1          73
#define PWM1_Generator_2          74
#define PWM1_Generator_3          75
#define PWM1_Fault                76

///*
// *    EXTI  peripheral
// */
//#define EXTI      ((EXTI_RegDef_t *)EXTI_BASEADDR)
//
///*
// *    SYSCFG  peripheral
// */
//#define SYSCFG     ((SYSCFG_RegDef_t *)SYSCFG_BASEADDR)

/*
 * Clock enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<0) )
#define GPIOB_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<1) )
#define GPIOC_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<2) )
#define GPIOD_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<3) )
#define GPIOE_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<4) )
#define GPIOF_PCLK_EN()       (RCGCGPIO_EN_CLOCK_REG|=(1<<5) )


/*
 * Clock Disable Macros for GPIOx peripherals
 */
 
#define GPIOA_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<0) ))
#define GPIOB_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<1) ))
#define GPIOC_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<2) ))
#define GPIOD_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<3) ))
#define GPIOE_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<4) ))
#define GPIOF_PCLK_DI()      ((RCGCGPIO_EN_CLOCK_REG)&=(~(1<<5) ))


/*
 * returns port core for given  GPIOx Base address
 */
#define GPIO_BASEADDS_TO_CODE(x)      ((x==GPIOA) ? 0 : \
		                                   (x==GPIOB) ? 1 : \
                                       (x==GPIOC) ? 2 : \
                                       (x==GPIOD) ? 3 : \
                                       (x==GPIOE) ? 4 : \
                                       (x==GPIOF) ? 5 :0) 



#endif /* INC_TM4C123GH6PMxxx_H_ */
