/*
 * STM32_F103C6_USART_Driver.h
 *
 *  Created on: Jun 4, 2024
 *      Author: Fady Emad
 */

#ifndef INC_STM32_F103C6_ADC_DRIVER_H_
#define INC_STM32_F103C6_ADC_DRIVER_H_

//includes
#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Driver.h"




typedef enum Analog_watchdog_State{
	Analog_watchdog_ON,
	Analog_watchdog_OFF
}Analog_watchdog_State_t;

typedef struct{
	Analog_watchdog_State_t state;
	uint16_t high_threshold;
	uint16_t low_threshold;
}Analog_watchdog_Config_t;


//Configuration structure
typedef struct
{
	uint8_t   					ChannelNumber;
	uint8_t 					conversion_mode;					//Set ADC conversion_mode  @ref ADC_conversion_mode_define
	uint8_t 					sample_time;						//Set ADC sample time  @ref ADC_sample_time_define
	uint8_t 					Data_alignment;						//Set ADC_Data_alignment  @ref ADC_Data_alignment_define
	Analog_watchdog_Config_t    Analog_watchdog;					//Set ADC watchdog  @ref ADC_Analog_watchdog_define
	uint8_t 					Calibration;						//Set ADC Calibration  @ref ADC_Calibration_define
	uint8_t						IRQ_Enable;							//enable or disable ADC IRQ @ref ADC_IRQ_Enable_define


	void                        (* P_IRQ_CallBack)(void) ;			//Set the C Function() which will be called once the IRQ  Happen

}ADC_Config_t;



// * =======================================================================================
//Reference Macros
// * =======================================================================================




//@ref ADC_conversion_mode_define
/* Bit 1 CONT: Continuous conversion
This bit is set and cleared by software. If set conversion takes place continuously till this bit is
reset.
0: Single conversion mode
1: Continuous conversion mode */
#define Single_conversion					~(0<<1)
#define Continuous_conversion				 (1<<1)


//@ref ADC_sample_time_define
#define  _1.5_cycles		0
#define  _7.5_cycles		1
#define  _13.5_cycles		2
#define	 _28.5_cycles		3
#define  _41.5_cycles		4
#define  _55.5_cycles		5
#define  _71.5_cycles		6
#define  _239.5_cycles		7

//@ref ADC_Data_alignment_define
/*Bit 11 ALIGN: Data alignment
This bit is set and cleared by software. Refer to Figure 27.and Figure 28.
0: Right Alignment
1: Left Alignment    */

#define Right Alignment 			~(0<<11)
#define Left Alignment				 (1<<11)


// @ref ADC_Calibration_define

/*Bit 2 CAL: A/D Calibration
This bit is set by software to start the calibration. It is reset by hardware after calibration is
complete.
0: Calibration completed
1: Enable calibration          */

#define Disable_calibration			0
#define Enable_calibration			(1<<2)


// * =======================================================================================

/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL ADC DRIVER"
 * =======================================================================================
 */
void ADC_init(ADC_TypeDef *ADCx, ADC_Config_t* ADC_Config);





#endif /* INC_STM32_F103C6_ADC_DRIVER_H_ */
