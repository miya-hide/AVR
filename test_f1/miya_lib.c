#include <avr/io.h>
#include "miya_lib.h"
#include "pin_access.h"

/* master main edit */
void time_delay32(volatile uint32_t time)
{
	do
	{
		time--;
	} while (time);
}

/**********************************************
 tiny13A
 time1:44clock
 time+1:17clock+
 Ex. time:50 44 + 17*49 = 877clock
**********************************************/
void time_delay16(volatile uint16_t time)
{
	do 
	{
		time--;
	} while (time);
}


//time_delay08
/**********************************************
 tiny13A
 time1:33clock
 time+1:10clock+
 Ex. time:255 33 + 10*253 = 2573clock
 
2016.03.05 modify
 time--; to (--time)
 2byte size down
 if you want 10clock time, use time-- code.(up to 2byte)
 
 time1:31clock
 time1+1:8clock
**********************************************/
void time_delay08(volatile uint8_t time)
{
	//do
	//{
		//time--;
	//} while (time);
	
	while (--time);
}


