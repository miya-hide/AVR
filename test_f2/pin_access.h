/*
 * pin_access.h
 *
 * Created: 2014/05/09 10:23:40
 *  Author: h-miyazaki
 */ 


#ifndef PIN_ACCESS_H_
#define PIN_ACCESS_H_

typedef union{
	//レジスタ一括
	uint8_t byte:8;
	
	//ビット
	struct {
		uint8_t b0:1;
		uint8_t b1:1;
		uint8_t b2:1;
		uint8_t b3:1;
		uint8_t b4:1;
		uint8_t b5:1;
		uint8_t b6:1;
		uint8_t b7:1;
	} bit;
}bit_map;

typedef struct{
	bit_map PIN;
	bit_map DDR;
	bit_map PORT;
	#if defined (__AVR_ATtiny10__)
	bit_map PUE;
	#endif
}pin_st;








#if defined (__AVR_ATtiny10__)
	#define PB (*(volatile pin_st *)0x00)
#endif


#if defined (__AVR_ATtiny13A__)
	#define PB (*(volatile pin_st *)0x36)
#endif


#if defined (__AVR_ATtiny2313__)
	#define PA (*(volatile pin_st *)0x39)
	#define PB (*(volatile pin_st *)0x36)
	#define PD (*(volatile pin_st *)0x30)
#endif


#if defined (__AVR_ATtiny861A__)
	#define PA (*(volatile pin_st *)0x39)
	#define PB (*(volatile pin_st *)0x36)
#endif









#if defined (__AVR_ATmega88__)
	#define PB (*(volatile pin_st *)0x23)
	#define PC (*(volatile pin_st *)0x26)
	#define PD (*(volatile pin_st *)0x29)
#endif


#if defined (__AVR_ATmega164P__)
	#define PA (*(volatile pin_st *)0x20)
	#define PB (*(volatile pin_st *)0x23)
	#define PC (*(volatile pin_st *)0x26)
	#define PD (*(volatile pin_st *)0x29)
#endif

#endif /* PIN_ACCESS_H_ */