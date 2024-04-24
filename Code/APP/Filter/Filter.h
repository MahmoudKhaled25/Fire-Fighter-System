/**
 * @file Filter.h
 * @brief Header file for Temperature Filter Module
 * @date 4/9/2024
 * @author Mahmoud Khaled
 */ 

#ifndef FILTER_H_
#define FILTER_H_

#include "Sensors.h"
#include "StdTypes.h" 

/**
 * @brief Initialize the temperature filter module with collecting 10 initial reads
 */
void TEMP_FilterInit(void);

/**
 * @brief Execute the temperature filtering process
 */
void TEMP_FilterRunnable(void);

/**
 * @brief Get the filtered temperature value
 *
 * @return The filtered temperature value
 */
u16 TEMP_FilterGetter(void);

#endif /* FILTER_H_ */
