/*
 * MemoryMap.h
 *
* Created: 11/13/2021
* Author : Mahmoud Elkot
*/


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

// PortA Registers
#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA  *((volatile unsigned char *)0x3A)
#define PINA  *((volatile unsigned char *)0x39)

// PortB Registers
#define PORTB *((volatile unsigned char *)0x38)
#define DDRB  *((volatile unsigned char *)0x37)
#define PINB  *((volatile unsigned char *)0x36)

// PortC Registers
#define PORTC *((volatile unsigned char *)0x35)
#define DDRC  *((volatile unsigned char *)0x34)
#define PINC  *((volatile unsigned char *)0x33)

// PortD Registers
#define PORTD *((volatile unsigned char *)0x32)
#define DDRD  *((volatile unsigned char *)0x31)
#define PIND  *((volatile unsigned char *)0x30)


#endif /* MEMORYMAP_H_ */