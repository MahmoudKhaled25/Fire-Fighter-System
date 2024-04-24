/**
 * @file EX_Interrupt.h
 * @brief Header file for External Interrupt Driver
 * @date 4/7/2024
 * @author Mahmoud Khaled
 */ 

#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

/*************************************** Include Section *******************************/
#include "MemoryMap.h"
#include "StdTypes.h"
#include "Utilities.h"

/*************************************** Types Section ********************************/
typedef enum
{
    EX_INT0, // External Interrupt 0
    EX_INT1, // External Interrupt 1
    EX_INT2  // External Interrupt 2
} EXI_Source_type; // Define enumeration for external interrupt sources

typedef enum
{
    FALLING_EDGE, // Triggering edge on falling edge
    RISING_EDGE   // Triggering edge on rising edge
} EXI_TriggerEdge_type; // Define enumeration for trigger edge types
	
/************************************** Function declaration **************************/
/**
 * @brief Initialize the External Interrupt module all with falling trigger edge
 */
void EXI_Init(void);

/**
 * @brief Enable the specified external interrupt
 * @param Interrupt: The external interrupt source to be enabled
 */
void EXI_Enable(EXI_Source_type Interrupt);

/**
 * @brief Disable the specified external interrupt
 * @param Interrupt: The external interrupt source to be disabled
 */
void EXI_Disable(EXI_Source_type Interrupt);

/**
 * @brief Set the triggering edge for the specified external interrupt
 * @param Interrupt: The external interrupt source
 * @param Edge: The triggering edge (FALLING_EDGE or RISING_EDGE)
 */
void EXI_TriggerEdge(EXI_Source_type Interrupt, EXI_TriggerEdge_type Edge);

/**
 * @brief Set the callback function for the specified external interrupt
 * @param Interrupt: The external interrupt source
 * @param LocalPtr: Pointer to the callback function
 */
void EXI_SetCallBack(EXI_Source_type Interrupt, CallBackPtr_type LocalPtr);

#endif /* EX_INTERRUPT_H_ */
