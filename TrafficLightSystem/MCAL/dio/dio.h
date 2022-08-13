/*
 * dio.h
 *
 * Created: 22/08/11 04:58:02 PM
 *  Author: Ziad
 */ 


#ifndef DIO_H_
#define DIO_H_

// all internal typedef
// all driver macros
// all driver function prototype

#include "utilities/memorymap.h"
#include "utilities/datatypes.h"
#include "utilities/bit_manipulation.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Direction defines
#define IN 0
#define OUT 1
// Values defines
#define LOW 0
#define HIGH 1

//Pins defines
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*
This function to Initial the DIO Pin
Input : Port(A,B,C,D) - PIN (0->7) - Direction ( INPUT, OUTPUT)
Output : return an error or Ok
*/
extern ERROR_H DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);

/*
This function to Write data to dio
Input : Port(A,B,C,D) - PIN (0->7) - value ( HIGH, LOW)
Output : return an error or Ok
*/
extern ERROR_H DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);

/*
This function to toggle Pin data
Input : Port(A,B,C,D) - PIN (0->7)
Output : return an error or Ok
*/
extern ERROR_H DIO_toggle(uint8_t portNumber, uint8_t pinNumber);

/*
This function to read dio data
Input : Port(A,B,C,D) - PIN (0->7) - pointer to address to hold the data
Output : return an error or Ok
*/
extern ERROR_H DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value);

/*
This function to Write data to port
Input : Port(A,B,C,D) - value ( HIGH, LOW)
Output : return an error or Ok
*/
extern ERROR_H DIO_Port_Write(uint8_t portNumber, uint8_t value);

/*
This function to read PORT data
Input : Port(A,B,C,D) - pointer to address to hold the data
Output : return an error or Ok
*/
extern ERROR_H DIO_Port_Read(uint8_t portNumber, uint8_t *value);

/*
This function to Initial the DIO PORT
Input : Port(A,B,C,D)  - Direction ( INPUT, OUTPUT)
Output : return an error or Ok
*/
extern ERROR_H DIO_Port_Direction(uint8_t portNumber, uint8_t direction);





#endif /* DIO_H_ */