/*
 * main.c

 *
 *  Created on: May 18, 2022
 *      Author: weza
 */
#include"../LIB/STD_TYPES.h"
#include"../MCAL/DIO/DIO_int.h"
#include"../MCAL/SPI/MSPI_Int.h"
#include"../HAL/LCD/LCD_int.h"
#include <string.h>
#include<util/delay.h>
#define SLAVE 0
#define MASTER 1
#define SELECT SLAVE

//U16 L_READVALUE=0;
//U16  L_READ_ANALOG=0;
//U16  L_TEMP=0;
//int main(void){
//	HLCD_voidInit();
//	MUART_voidInit();
//	DIO_vWrtPinDir(DIO_PORTD,DIO_PIN1,DIO_OUTPUT);
//	DIO_vWrtPinDir(DIO_PORTD,DIO_PIN0,DIO_INPUT);
//	DIO_vWrtPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
//	while(1){
//		MUART_voidTransmit('a');
//		u16 x=MUART_voidRecieve();
//		if(x=='a'){
//			DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
//		}
//		else DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);
//	}
//
//return 0;
//}
#if SELECT==MASTER
void main(void){
	MSPIMstrVoidInit();
	    DIO_vWrtPinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN6,DIO_INPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);
		DIO_vWrtPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
		 DIO_vWrtPinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
		 DIO_vWrtPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
		U8 COUNT=0;
		U8 *ptr;
		U8 ARR[20]="hadeer";
		u8 value=0;
			while(1){
		ptr=MSPIVoidTransRecString(ARR,&COUNT);
		for(int i=0;i<COUNT;i++){
			if(ARR[i]==*ptr){
				value++;
			}
			ptr++;
		}
		if (value==COUNT){

		DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
						}
		else 	DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);
	}
}
#elif SELECT==SLAVE
void main(void){
	MSPISLVVoidInit();
        DIO_vWrtPinDir(DIO_PORTB,DIO_PIN4,DIO_INPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN5,DIO_INPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);
		DIO_vWrtPinDir(DIO_PORTB,DIO_PIN7,DIO_INPUT);
		DIO_vWrtPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
		DIO_vWrtPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
		U8 COUNT=0;
		U8 *ptr;
		U8 ARR[20]="hadeer";
		u8 value=0;
	while(1){
ptr=MSPIVoidTransRecString(ARR,&COUNT);
for(int i=0;i<COUNT;i++){ //instead of stringcompare
	if(ARR[i]==*ptr){
		value++;
	}
	ptr++;
}
if (value==COUNT){

DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_HIGH);
				}
else DIO_vWrtPinVal(DIO_PORTA,DIO_PIN0,DIO_LOW);

	}

}
#endif










