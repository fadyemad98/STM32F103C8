/*
 * STM32_F103C6_SYSTICK_DRIVER.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Fady Emad
 *      Author: George Emad
 */


//Includes
#include "STM32F103x6.h"
#include "STM32_F103C6_SYSTICK_DRIVER.h"
#include "BIT_MATH.h"

//=============================


/*
 * =======================================================================================
 * 							Global Variables
 * =======================================================================================
 */

static uint8_t systick_clk =1;


/*
 * ===============================================
 * * APIs Supported by "MCAL SYSTICK DRIVER"
 * ===============================================
 */



/**================================================================
 * @Fn				- MCAL_SYSTICK_Init
 * @brief 			- Initializes the SYSTICK peripheral according to the specified parameters in the Systick_Config_t
 * @param [in] 		- *pSystickConfig point to structure that holds configuration of systick timer.
 * @retval 			- none
 * Note				- none
 */
void MCAL_SYSTICK_Init(Systick_Config_t* pSystickConfig ){
	//SYSTICK_STK_CTRL = 0x0000;
	SYSTICK->STK_CTRL = 0x0000;
	if(pSystickConfig->CLKSOURCE == CLKSOURCE_AHB){
		SYSTICK->STK_CTRL |= (1<<2);
		//SYSTICK_STK_CTRL |= (1<<2);
		systick_clk =8; // assume HSI is used

	}else if(pSystickConfig->CLKSOURCE == CLKSOURCE_AHB_8){
		SYSTICK->STK_CTRL&= ~(1<<2);
		//SYSTICK_STK_CTRL &= ~(1<<2);
		systick_clk=1;
	}

	if(pSystickConfig->SYSTICK_INT == SYSTICK_INT_enable){
		SYSTICK->STK_CTRL|= (1<<1);
	//	SYSTICK_STK_CTRL |= (1<<1);
		//todo
	}
	else if(pSystickConfig->SYSTICK_INT == SYSTICK_INT_disable){
		SYSTICK->STK_CTRL &= ~(1<<1);
		//SYSTICK_STK_CTRL &= ~(1<<1);
		//todo
	}
}

void MCAL_SYSTICK_disable(void){
	SYSTICK->STK_CTRL= 0x0000;
	//SYSTICK_STK_CTRL = 0x0000;
}

void MCAL_SYSTICK_delay_ms(uint32_t ms){
	SET_BIT(SYSTICK->STK_CTRL,0);
	//SET_BIT(SYSTICK_STK_CTRL,0);
	SYSTICK->STK_LOAD= ((ms*1000)*systick_clk-1);
	//SYSTICK_STK_LOAD= ((ms*1000)*systick_clk-1);
	/*if(GET_BIT(SYSTICK_STK_CTRL,1) == 0){
		while(SYSTICK_STK_VAL != 0 );
	}*/
	if(GET_BIT(SYSTICK->STK_CTRL,1) == 0){
			while(SYSTICK->STK_VAL != 0 );
		}
	MCAL_SYSTICK_disable();

}
void MCAL_SYSTICK_delay_us(uint32_t us){
	SET_BIT(SYSTICK->STK_CTRL,0);
	SYSTICK->STK_LOAD= ((us)*systick_clk-1);
	if(GET_BIT(SYSTICK->STK_CTRL,1) == 0){
			while(SYSTICK->STK_VAL != 0 );
		}
	MCAL_SYSTICK_disable();
}




