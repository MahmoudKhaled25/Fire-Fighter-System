/*
 * DIO_Private.h
 *
 * Created: 12/8/2023 2:49:26 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


extern DIO_PinStatues_type const Pin_Statues[TOTAL_PIN];
static void DIO_InitPin(DIO_Pin_type pin ,DIO_PinStatues_type statues);


#endif /* DIO_PRIVATE_H_ */