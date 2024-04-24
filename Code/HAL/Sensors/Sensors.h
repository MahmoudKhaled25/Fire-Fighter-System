/*
 * sensors.h
 *
 * Created: 3/17/2024 3:08:55 AM
 *  Author: Mahmoud Khaled
 *
 * @file sensors.h
 * @brief Header file for sensor interface functions.
 *
 * This file contains the declarations of functions used for interfacing with various sensors,
 * including LM35 temperature sensor, MPX4115 pressure sensor, and MPX4250 pressure sensor.
 */

#ifndef SENSORS_H_
#define SENSORS_H_

/*********************************************** Include Section *****************************************/
#include "ADC_Interface.h"   /**< Include the ADC interface for sensor readings */
#include "Sensors_cfg.h"     /**< Include the sensor configuration file */
#include "StdTypes.h"        /**< Include standard data types definitions */

/*********************************************** Function declaration ************************************/

/**
 * @brief Read temperature from LM35 sensor.
 *
 * @return Temperature read from LM35 sensor in tenths of degrees Celsius (10*C).
 */
u16 sensor_ReadTemp_LM35(void);

/**
 * @brief Read pressure from MPX4115 sensor.
 *
 * @return Pressure read from MPX4115 sensor in tenths of kilopascals (10*KPa).
 */
u16 sensor_ReadPressure_MPX4115(void);

/**
 * @brief Read pressure from MPX4250 sensor.
 *
 * @return Pressure read from MPX4250 sensor in tenths of kilopascals (10*KPa).
 */
u16 sensor_ReadPressure_MPX4250(void);

#endif /* SENSORS_H_ */