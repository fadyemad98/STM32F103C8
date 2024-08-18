/*
 * STM32_F103C6_SYSTICK_DRIVER.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Fady Emad
 *      Author: George Emad
 */

#ifndef INC_STM32_F103C6_SYSTICK_DRIVER_H_
#define INC_STM32_F103C6_SYSTICK_DRIVER_H_

//---------------------------------------------------------
//Includes
//---------------------------------------------------------
#include "STM32F103x6.h"


//---------------------------------------------------------
//User type definitions (structures)
//---------------------------------------------------------

typedef struct
{	uint8_t CLKSOURCE;						// Clock source selection @ref:CLKSOURCE
	uint8_t SYSTICK_INT;					// SysTick exception request enable  @ref:SYSTICK_INT
	void (*pSystick_Call_back)(void);
}Systick_Config_t;


//---------------------------------------------------------
//Macros Configuration References
//---------------------------------------------------------

/*@ref:CLKSOURCE
 */
#define CLKSOURCE_AHB_8				0
#define CLKSOURCE_AHB				1

/*@ref:SYSTICK_INT
 */
#define SYSTICK_INT_disable 		0
#define SYSTICK_INT_enable		    1


/*
 * =============================================== *
 * APIs Supported by "MCAL SYSTICK DRIVER"
 * =============================================== */

/**================================================================
 * @Fn				- MCAL_SYSTICK_Init
 * @brief 			- Initialize the Systick according to the specified parameters
 * @param [in] 		- Systick_Config_t* pSystickConfig where Systick_Config_t is config struct
 * @retval 			- none
 * Note				- This only initialize Systick and doesn't start
 */
void MCAL_SYSTICK_Init(Systick_Config_t* pSystickConfig );
/**================================================================
 * @Fn				- MCAL_SYSTICK_disable
 * @brief 			- Disable Systick
 * @param [in] 		- none
 * @retval 			- none
 * Note				- none
 */
void MCAL_SYSTICK_disable(void);
/**================================================================
 * @Fn				- MCAL_SYSTICK_delay_ms
 * @brief 			- Generates systick delay in millisec.
 * @param [in] 		- ms: delay time required in milliseconds
 * @retval 			- none
 * Note				- none
 */
void MCAL_SYSTICK_delay_ms(uint32_t ms );
/**================================================================
 * @Fn				- MCAL_SYSTICK_delay_us
 * @brief 			- Generates systick delay in microsec.
 * @param [in] 		- ms: delay time required in microseconds
 * @retval 			- none
 * Note				- none
 */
void MCAL_SYSTICK_delay_us(uint32_t us);

#endif /* INC_STM32_F103C6_SYSTICK_DRIVER_H_ */

