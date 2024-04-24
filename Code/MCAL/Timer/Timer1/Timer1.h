/*
 * Timer1.h
 *
 * Created: 4/17/2024 4:48:35 AM
 *  Author: Mahmoud Khaled
 */ 

#ifndef TIMER1_H_
#define TIMER1_H_

/************************************************** Include section **********************************************************/
#include "StdTypes.h"       /**< Standard data types header file */
#include "MemoryMap.h"      /**< Memory mapping header file */
#include "Utilities.h"      /**< Utility functions header file */

/*************************************************** Macros section **********************************************************/
#define Timer1_Read()           TCNT1      /**< Macro to read Timer1 count register */
#define Timer1_Write(T)         TCNT1=T    /**< Macro to write a value to Timer1 count register */
#define Timer1_OutCompARead()   OCR1A      /**< Macro to read Timer1 output compare A register */
#define Timer1_OutCompAWrite(T) OCR1A=T    /**< Macro to write a value to Timer1 output compare A register */
#define Timer1_OutCompBRead()   OCR1B      /**< Macro to read Timer1 output compare B register */
#define Timer1_OutCompBWrite(T) OCR1B=T    /**< Macro to write a value to Timer1 output compare B register */
#define Timer1_InCaptRead()     ICR1       /**< Macro to read Timer1 input capture register */
#define Timer1_InCaptWrite(T)   ICR1=T     /**< Macro to write a value to Timer1 input capture register */

/************************************************** Typedef section **********************************************************/
typedef enum {
    TIMER1_NORMAL_MODE=0,                                /**< Normal mode */
    TIMER1_PHASE_CORRECT_8BIT_MODE,                      /**< Phase correct PWM, 8-bit */
    TIMER1_PHASE_CORRECT_9BIT_MODE,                      /**< Phase correct PWM, 9-bit */
    TIMER1_PHASE_CORRECT_10BIT_MODE,                     /**< Phase correct PWM, 10-bit */
    TIMER1_CTC_OCR1ATOP_MODE,                            /**< Clear Timer on Compare Match (CTC) mode, OCR1A as top */
    TIMER1_FAST_PWM_8BIT_MODE,                           /**< Fast PWM, 8-bit */
    TIMER1_FAST_PWM_9BIT_MODE,                           /**< Fast PWM, 9-bit */
    TIMER1_FAST_PWM_10BIT_MODE,                          /**< Fast PWM, 10-bit */
    TIMER1_PHASE_FREQUENCY_CORRECT_ICR1TOP_MODE,         /**< Phase and frequency correct PWM, ICR1 as top */
    TIMER1_PHASE_FREQUENCY_CORRECT_OCR1ATOP_MODE,        /**< Phase and frequency correct PWM, OCR1A as top */
    TIMER1_PHASE_CORRECT_ICR1TOP_MODE,                   /**< Phase correct PWM, ICR1 as top */
    TIMER1_PHASE_CORRECT_OCR1ATOP_MODE,                  /**< Phase correct PWM, OCR1A as top */
    TIMER1_CTC_ICR1TOP_MODE,                             /**< Clear Timer on Compare Match (CTC) mode, ICR1 as top */
    TIMER1_FAST_PWM_ICR1TOP_MODE=14,                     /**< Fast PWM, ICR1 as top */
    TIMER1_FAST_PWM_OCR1A_MODE,                          /**< Fast PWM, OCR1A as top */
} TIMER1_OperationMode_type;

typedef enum {
    TIMER1_NO_CLOCK=0,        /**< No clock source */
    TIMER1_NO_SCALER,          /**< No prescaler */
    TIMER1_SCALER_8,           /**< Clock divided by 8 */
    TIMER1_SCALER_64,          /**< Clock divided by 64 */
    TIMER1_SCALER_256,         /**< Clock divided by 256 */
    TIMER1_SCALER_1024,        /**< Clock divided by 1024 */
    TIMER1_T1_EX_CLK_FALLING,  /**< External clock source, falling edge */
    TIMER1_T1_EX_CLK_RISING,   /**< External clock source, rising edge */
} TIMER1_Prescaler_type;

typedef enum {
    TIMER1_OC1A_OC1B_DISCONNECTED=0,     /**< Output pins OC1A and OC1B disconnected */
    TIMER1_OC1A_OC1B_TOGGLE,              /**< Toggle OC1A and OC1B on compare match */
    TIMER1_OC1A_OC1B_CLEAR,               /**< Clear OC1A/OC1B on compare match */
    TIMER1_OC1A_OC1B_SET,                 /**< Set OC1A/OC1B on compare match */
    TIMER1_OC1A_TOGGLE_OC1B_DISCONNECTED, /**< Toggle OC1A, disconnect OC1B */
    TIMER1_OC1A_OC1B_NON_INVERTING,       /**< Non-inverting mode for OC1A, OC1B disconnected */
    TIMER1_OC1A_OC1B_INVERTING            /**< Inverting mode for OC1A, OC1B disconnected */
} TIMER1_OC1_PinMode_type;

typedef enum {
    ICU_FALLING_EDGE,  /**< Triggering edge on falling edge */
    ICU_RISING_EDGE    /**< Triggering edge on rising edge */
} TIMER1_ICU_TriggerEdge_type;

/************************************************ Function declaration *******************************************************/
/**
 * @brief Initializes Timer1 with specified operation mode and prescaler.
 *
 * @param mode Operation mode of Timer1
 * @param prescaler Prescaler value for Timer1
 */
void Timer1_Init(TIMER1_OperationMode_type mode, TIMER1_Prescaler_type prescaler);

/**
 * @brief Enables overflow interrupt for Timer1.
 */
void Timer1_OVF_InterruptEnable();

/**
 * @brief Disables overflow interrupt for Timer1.
 */
void Timer1_OVF_InterruptDisable();

/**
 * @brief Enables Compare Match A interrupt for Timer1.
 */
void Timer1_COMPA_InterruptEnable();

/**
 * @brief Disables Compare Match A interrupt for Timer1.
 */
void Timer1_COMPA_InterruptDisable();

/**
 * @brief Enables Compare Match B interrupt for Timer1.
 */
void Timer1_COMPB_InterruptEnable();

/**
 * @brief Disables Compare Match B interrupt for Timer1.
 */
void Timer1_COMPB_InterruptDisable();

/**
 * @brief Enables Input Capture interrupt for Timer1.
 */
void Timer1_CAPT_InterruptEnable();

/**
 * @brief Disables Input Capture interrupt for Timer1.
 */
void Timer1_CAPT_InterruptDisable();

/**
 * @brief Enables noise canceler for Timer1 Input Capture.
 */
void Timer1_CAPTNoiseCancler_Enable();

/**
 * @brief Disables noise canceler for Timer1 Input Capture.
 */
void Timer1_CAPTNoiseCancler_Disable();

/**
 * @brief Sets the output compare pin mode for Timer1.
 *
 * @param PinMode Desired output compare pin mode
 */
void Timer1_OC1_PinMode(TIMER1_OC1_PinMode_type PinMode);

/**
 * @brief Sets the trigger edge for Timer1 Input Capture Unit.
 *
 * @param Edge Desired trigger edge
 */
void Timer1_ICU_TriggerEdge(TIMER1_ICU_TriggerEdge_type Edge);

/**
 * @brief Sets the callback function for Timer1 overflow interrupt.
 *
 * @param LocalPtr Pointer to the callback function
 */
void Timer1_OVF_SetCallback(CallBackPtr_type LocalPtr);

/**
 * @brief Sets the callback function for Timer1 Compare Match A interrupt.
 *
 * @param LocalPtr Pointer to the callback function
 */
void Timer1_COMPA_SetCallback(CallBackPtr_type LocalPtr);

/**
 * @brief Sets the callback function for Timer1 Compare Match B interrupt.
 *
 * @param LocalPtr Pointer to the callback function
 */
void Timer1_COMPB_SetCallback(CallBackPtr_type LocalPtr);

/**
 * @brief Sets the callback function for Timer1 Input Capture interrupt.
 *
 * @param LocalPtr Pointer to the callback function
 */
void Timer1_CAPT_SetCallback(CallBackPtr_type LocalPtr);

#endif /* TIMER1_H_ */
