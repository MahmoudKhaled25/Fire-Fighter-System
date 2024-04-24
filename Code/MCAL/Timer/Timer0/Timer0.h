/*
 * Timer0.h
 *
 * Created: 4/14/2024 3:27:35 PM
 *  Author: Mahmoud Khaled
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utilities.h"

/*************************************************** Macros section **********************************************************/
#define Timer0_Read()          TCNT0	/**< Macro to read the value of Timer/Counter0 register */
#define Timer0_Write(t)        TCNT0=t	/**< Macro to write a value to Timer/Counter0 register */
#define Timer0_OutCompRead()   OCR0		/**< Macro to read the value of Timer/Counter0 Output Compare register */
#define Timer0_OutCompWrite(t) OCR0=t	/**< Macro to write a value to Timer/Counter0 Output Compare register */

/************************************************** Typedef section **********************************************************/
typedef enum {
    TIMER0_NORMAL_MODE=0,		/**< Timer0 operates in normal mode */
    TIMER0_CTC_MODE,			/**< Timer0 operates in Clear Timer on Compare (CTC) mode */
    TIMER0_FAST_PWM_MODE,		/**< Timer0 operates in fast PWM mode */
	TIMER0_PHASE_CORRECT_MODE	/**< Timer0 operates in phase correct mode */
}TIMER0_OperationMode_type;
    
typedef enum {
    TIMER0_NO_CLOCK=0,	/**< Timer0 is not clocked */
    TIMER0_NO_SCALER,	/**< Timer0 operates with no prescaling */
    TIMER0_SCALER_8,	/**< Timer0 operates with 8 prescaler */
    TIMER0_SCALER_64,	/**< Timer0 operates with 64 prescaler */
    TIMER0_SCALER_256,	/**< Timer0 operates with 256 prescaler */
    TIMER0_SCALER_1024, /**< Timer0 operates with 1024 prescaler */
	TIMER0_T0_EX_CLK_FALLING,	/**< Timer0 operates with External clock on T0 (Falling edge trigger) */
	TIMER0_T0_EX_CLK_RISING		 /**< Timer0 operates with External clock on T0 (Rising edge trigger) */
}TIMER0_Prescaler_type;

typedef enum {
    TIMER0_OC0_DISCONNECTED=0,	/**< Timer0 Output Compare pin disconnected */
    TIMER0_OC0_TOGGLE,			/**< Timer0 Output Compare pin toggles on compare match */
    TIMER0_OC0_CLEAR,			/**< Timer0 Output Compare pin clears on compare match */
    TIMER0_OC0_SET,				/**< Timer0 Output Compare pin sets on compare match */
    TIMER0_OC0_NON_INVERTING,	/**< Timer0 Output Compare pin behaves as non-inverting mode */
    TIMER0_OC0_INVERTING		/**< Timer0 Output Compare pin behaves as inverting mode */
}TIMER0_OC0_PinMode_type;

/************************************************ Function declaration *******************************************************/
/**
 * @brief Initializes Timer0 with specified operation mode and prescaler.
 *
 * @param mode Operation mode of Timer0.
 * @param prescaler Prescaler value for Timer0.
 */
void Timer0_Init(TIMER0_OperationMode_type mode, TIMER0_Prescaler_type prescaler);

/**
 * @brief Enables Timer0 overflow interrupt.
 */
void Timer0_OVF_InterruptEnable();

/**
 * @brief Disables Timer0 overflow interrupt.
 */
void Timer0_OVF_InterruptDisable();

/**
 * @brief Enables Timer0 compare match interrupt.
 */
void Timer0_COMP_InterruptEnable();

/**
 * @brief Disables Timer0 compare match interrupt.
 */
void Timer0_COMP_InterruptDisable();

/**
 * @brief Sets the mode of Timer0 Output Compare pin (OC0).
 *
 * @param PinMode Mode of Timer0 Output Compare pin.
 */
void Timer0_OC0_PinMode(TIMER0_OC0_PinMode_type PinMode);

/**
 * @brief Sets a callback function to be executed upon Timer0 overflow interrupt.
 *
 * @param LocalPtr Pointer to the callback function.
 */
void Timer0_OVF_SetCallback(CallBackPtr_type LocalPtr);

/**
 * @brief Sets a callback function to be executed upon Timer0 compare match interrupt.
 *
 * @param LocalPtr Pointer to the callback function.
 */
void Timer0_COMP_SetCallback(CallBackPtr_type LocalPtr);

#endif /* TIMER0_H_ */
