/*
 * MemoryMap.h
 *
 * Created: 12/5/2023 9:32:04 PM
 *  Author: Mahmoud Khaled
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

/*********************************** CPU Registers ************************************/
#define SREG (*((volatile unsigned char*) 0x5F) )
#define SPH  (*((volatile unsigned char*) 0x5E) )
#define SPL  (*((volatile unsigned char*) 0x5D) )
#define SP   (*((volatile unsigned short*) 0x5D) )

/*********************************** DIO Register ************************************/
// address of PORTA
#define DDRC (*((volatile unsigned char*) 0x34) )
#define PORTC (*((volatile unsigned char*) 0x35) )
#define PINC (*((volatile unsigned char*)0X33))

// address of PORTA
#define DDRB (*((volatile unsigned char*) 0x37) )
#define PORTB (*((volatile unsigned char*) 0x38) )
#define PINB (*((volatile unsigned char*)0X36))

// address of PORTA
#define DDRA (*((volatile unsigned char*) 0x3A) )
#define PORTA (*((volatile unsigned char*) 0x3B) )
#define PINA (*((volatile unsigned char*)0X39))

// address of PORTD
#define DDRD (*((volatile unsigned char*) 0x31) )
#define PORTD (*((volatile unsigned char*) 0x32) )
#define PIND (*((volatile unsigned char*)0X30))

/*********************************** ADC Register **********************************/

// ADMUX Register
#define ADMUX  (*((volatile unsigned char*)0X27))
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4  4
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0

// ADCSRA Register
#define ADCSRA (*((volatile unsigned char*)0X26))
#define ADEN   7
#define ADSC   6
#define ADATE  5
#define ADIF   4
#define ADIE   3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0

// ADDATA Register
#define ADCH   (*((volatile unsigned char*)0X25))
#define ADCL   (*((volatile unsigned char*)0X24))

/***************************** External Interrupt Register ***************************/
/* MCU Control Register */
#define MCUCR  (*((volatile unsigned char*)0x55))
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3

/* MCU Control and Status Register */
#define MCUCSR (*((volatile unsigned char*)0x54))
#define ISC2   6

/* General Interrupt Control Register */
#define GICR   (*((volatile unsigned char*)0x5B))
#define	INT2   5
#define	INT0   6
#define	INT1   7

/* General Interrupt Flag Register */
#define GIFR   (*((volatile unsigned char*)0x5A))
#define INTF2  5
#define INTF0  6
#define INTF1  7

/********************************** ISR defination *********************************/

#define ISR_NOBLOCK __attribute__((interrupt))
#define ISR_NAKED	__attribute__((naked))

/* Context Switching Attribute */
#define ISR(vector, ...)	void vector (void) __attribute__((signal))__VA_ARGS__;	\
							void vector (void)
							
/* Global Interrupt Control Instructions */
#define SEI()  __asm__ __volatile__("sei"::)  // Global Interrupt Enable
#define CLI()  __asm__ __volatile__("cli"::)  // Global Interrupt Disable
#define RETI() __asm__ __volatile__("reti"::) // Return from Interrupt
#define RET()  __asm__ __volatile__("ret"::)  // Return from Function

#define BAD_vect			__vector_default										
#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3
#define TIMER2_COMP_vect	__vector_4
#define TIMER2_OVF_vect		__vector_5
#define TIMER1_CAPT_vect	__vector_6
#define TIMER1_COMPA_vect	__vector_7
#define TIMER1_COMPB_vect	__vector_8
#define TIMER1_OVF_vect		__vector_9
#define TIMER0_COMP_vect	__vector_10
#define TIMER0_OVF_vect		__vector_11
#define SPI_STC_vect		__vector_12
#define USART_RX_vect		__vector_13
#define USART_UDRE_vect		__vector_14
#define USART_TX_vect		__vector_15
#define ADC_vect			__vector_16
#define EE_READY_vect		__vector_17
#define ANALOG_COMP_vect	__vector_18
#define TWI_vect			__vector_19
#define SPM_READY_vect		__vector_20

/************************************ NVM Register ***********************************/

/* Address Register */
#define EEAR (*((volatile unsigned short*)0X3E))

/* Data Register */
#define EEDR (*((volatile unsigned char*)0X3D))

/* Control Register */
#define EECR (*((volatile unsigned char*)0X3C))

/*********************************** Timer resgister **********************************/

//------------------------------------- Timer0 -------------------------------------// 
#define TCCR0 (*((volatile unsigned char*)0X53))
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7

#define TCNT0 (*((volatile unsigned char*)0X52))

#define OCR0  (*((volatile unsigned char*)0X5C))
//------------------------------------- Timer2 -------------------------------------//
#define TCCR1A (*((volatile unsigned char*)0X4F))
#define WGM10  0
#define WGM11  1
#define FOC1B  2
#define FOC1A  3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B (*((volatile unsigned char*)0X4E))
#define CS10  0
#define CS11  1
#define CS12  2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCNT1H (*((volatile unsigned char*)0X4D))
#define TCNT1L (*((volatile unsigned char*)0X4C))
#define TCNT1  (*((volatile unsigned short*)0X4C))

#define OCR1AH (*((volatile unsigned char*)0X4B))
#define OCR1AL (*((volatile unsigned char*)0X4A))
#define OCR1A  (*((volatile unsigned short*)0X4A))

#define OCR1BH (*((volatile unsigned char*)0X49))
#define OCR1BL (*((volatile unsigned char*)0X48))
#define OCR1B  (*((volatile unsigned short*)0X48))

#define ICR1H  (*((volatile unsigned char*)0X47))
#define ICR1L  (*((volatile unsigned char*)0X46))
#define ICR1   (*((volatile unsigned short*)0X46))
//------------------------------------- Timer1 -------------------------------------//
#define TCCR2 (*((volatile unsigned char*)0X45))
#define CS20  0
#define CS21  1
#define CS22  2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2  7

#define TCNT2 (*((volatile unsigned char*)0X44))

#define OCR2  (*((volatile unsigned char*)0X43))

//-------------------------------- Timer Interrupt ---------------------------------//
#define TIMSK (*((volatile unsigned char*)0X59))
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7

#define TIFR (*((volatile unsigned char*)0X58))
#define TOV0  0
#define OCF0  1
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5
#define TOV2  6
#define OCF2  7


#endif /* MEMORYMAP_H_ */

