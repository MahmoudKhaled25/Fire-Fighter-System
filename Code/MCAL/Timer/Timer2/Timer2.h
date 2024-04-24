/*
 * Timer2.c
 *
 * Created: 4/17/2024 9:50:08 PM
 *  Author: Mahmoud Khaled
 */ 

#ifndef TIMER2_H_
#define TIMER2_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"
#include "MemoryMap.h"
#include "Utilities.h"

/*************************************************** Macros section **********************************************************/
#define Timer2_Read()          TCNT2	/**< Macro to read the value of Timer/Counter2 register */
#define Timer2_Write(t)        TCNT2=t	/**< Macro to write a value to Timer/Counter2 register */
#define Timer2_OutCompRead()   OCR2		/**< Macro to read the value of Timer/Counter2 Output Compare register */
#define Timer2_OutCompWrite(t) OCR2=t	/**< Macro to write a value to Timer/Counter2 Output Compare register */

/************************************************** Typedef section **********************************************************/
typedef enum {
    TIMER2_NORMAL_MODE=0,		/**< Timer2 operates in normal mode */
    TIMER2_CTC_MODE,			/**< Timer2 operates in Clear Timer on Compare (CTC) mode */
    TIMER2_FAST_PWM_MODE,		/**< Timer2 operates in fast PWM mode */
	TIMER2_PHASE_CORRECT_MODE	/**< Timer2 operates in phase correct mode */
}TIMER2_OperationMode_type;
    
typedef enum {
    TIMER2_NO_CLOCK=0,	/**< Timer2 is not clocked */
    TIMER2_NO_SCALER,	/**< Timer2 operates with no prescaling */
    TIMER2_SCALER_8,	/**< Timer2 operates with 8 prescaler */
    TIMER2_SCALER_32,	/**< Timer2 operates with 32 prescaler */
    TIMER2_SCALER_64,	/**< Timer2 operates with 64 prescaler */
    TIMER2_SCALER_128,	/**< Timer2 operates with 128 prescaler */
    TIMER2_SCALER_256,	/**< Timer2 operates with 256 prescaler */
    TIMER2_SCALER_1024,	/**< Timer2 operates with 1024 prescaler */
}TIMER2_Prescaler_type;

typedef enum {
    TIMER2_OC2_DISCONNECTED=0,	/**< Timer2 Output Compare pin disconnected */
    TIMER2_OC2_TOGGLE,			/**< Timer2 Output Compare pin toggles on compare match */
    TIMER2_OC2_CLEAR,			/**< Timer2 Output Compare pin clears on compare match */
    TIMER2_OC2_SET,				/**< Timer2 Output Compare pin sets on compare match */
    TIMER2_OC2_NON_INVERTING,	/**< Timer2 Output Compare pin behaves as non-inverting mode */
    TIMER2_OC2_INVERTING		/**< Timer2 Output Compare pin behaves as inverting mode */
}TIMER2_OC2_PinMode_type;

/************************************************ Function declaration *******************************************************/
/**
 * @brief Initializes Timer2 with specified operation mode and prescaler.
 *
 * @param mode Operation mode of Timer2.
 * @param prescaler Prescaler value for Timer2.
 */
void Timer2_Init(TIMER2_OperationMode_type mode, TIMER2_Prescaler_type prescaler);

/**
 * @brief Enables Timer2 overflow interrupt.
 */
void Timer2_OVF_InterruptEnable();

/**
 * @brief Disables Timer2 overflow interrupt.
 */
void Timer2_OVF_InterruptDisable();

/**
 * @brief Enables Timer2 compare match interrupt.
 */
void Timer2_COMP_InterruptEnable();

/**
 * @brief Disables Timer2 compare match interrupt.
 */
void Timer2_COMP_InterruptDisable();

/**
 * @brief Sets the mode of Timer2 Output Compare pin (OC2).
 *
 * @param PinMode Mode of Timer2 Output Compare pin.
 */
void Timer2_OC2_PinMode(TIMER2_OC2_PinMode_type PinMode);

/**
 * @brief Sets a callback function to be executed upon Timer2 overflow interrupt.
 *
 * @param LocalPtr Pointer to the callback function.
 */
void Timer2_OVF_SetCallback(CallBackPtr_type LocalPtr);

/**
 * @brief Sets a callback function to be executed upon Timer2 compare match interrupt.
 *
 * @param LocalPtr Pointer to the callback function.
 */
void Timer2_COMP_SetCallback(CallBackPtr_type LocalPtr);

#endif /* TIMER2_H_ */
