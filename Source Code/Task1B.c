// 
// Smpl_GPIO_LED4 : GPA12 ~ 14 to control on-board RGB LEDs
//                  low-active output 
//
#include <stdio.h>
#include "NUC1xx.h"
#include "GPIO.h"
#include "SYS.h"

// Initial GPIO pins (GPA 12,13,14) to Output mode  
void Init_LED()
{
	// initialize GPIO pins
	DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT); // GPA12 pin set to output mode
	DrvGPIO_Open(E_GPA, 13, E_IO_OUTPUT); // GPA13 pin set to output mode
	DrvGPIO_Open(E_GPA, 14, E_IO_OUTPUT); // GPA14 pin set to output mode
	// set GPIO pins to output Low
	DrvGPIO_SetBit(E_GPA, 12); // GPA12 pin output Hi to turn off LED
	DrvGPIO_SetBit(E_GPA, 13); // GPA13 pin output Hi to turn off LED
	DrvGPIO_SetBit(E_GPA, 14); // GPA14 pin output Hi to turn off LED
}

int main (void)
{
	UNLOCKREG();			    // unlock register for programming
  DrvSYS_Open(50000000);// set System Clock to run at 48MHz 
	                      // 12MHz crystal input, PLL output 48MHz
	LOCKREG();				    // lock register from programming

  Init_LED();  // Initialize LEDs (RGB LEDs below LCD panel)
 
	while (1)	   // forever loop to keep flashing RGB LEDs one at a time
	{
		DrvGPIO_ClrBit(E_GPA, 12); // output Low to turn on RED LED
	  DrvSYS_Delay(300000);	     // delay 
	  DrvGPIO_SetBit(E_GPA, 12); // output Hi to turn off RED LED
	  DrvSYS_Delay(300000);	     // delay
	  DrvGPIO_ClrBit(E_GPA, 13); // output Low to turn on GREEN LED
	  DrvSYS_Delay(300000);	     // delay 
	  DrvGPIO_SetBit(E_GPA, 13); // output Hi to turn off GREEN LED
	  DrvSYS_Delay(300000);	     // delay
	  DrvGPIO_ClrBit(E_GPA, 14); // output Low to turn on BLUE LED
	  DrvSYS_Delay(300000);	     // delay 
	  DrvGPIO_SetBit(E_GPA, 14); // output Hi to turn off BLUE LED
	  DrvSYS_Delay(300000);	     // delay
	}
}