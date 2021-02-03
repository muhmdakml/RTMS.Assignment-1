// 
// Smpl_GPIO_LED1 : GPC12 to control on-board LEDs
//                  low-active output to control Red LEDs
//
#include <stdio.h>
#include "NUC1xx.h"
#include "SYS.h"
#include "GPIO.h"

void Init_LED() // Initialize GPIO pins
{
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT); // GPC12 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 12);            // Goutput Hi to turn off LED
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT); // GPC13 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 13);            // Goutput Hi to turn off LED
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT); // GPC14 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 14);            // Goutput Hi to turn off LED
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT); // GPC15 pin set to output mode
	DrvGPIO_SetBit(E_GPC, 15);            // Goutput Hi to turn off LED
}

int main (void)
{
	UNLOCKREG();			    // unlock register for programming
  DrvSYS_Open(50000000);// set System Clock to run at 48MHz 
	                      // 12MHz crystal input, PLL output 48MHz
	LOCKREG();				    // lock register from programming

  Init_LED();        // Initialize LEDs (four on-board LEDs below LCD panel)	

	while (1)				   // forever loop to keep flashing four LEDs one at a time
	{
	DrvGPIO_ClrBit(E_GPC, 12); // output Low to turn on LED
	DrvSYS_Delay(300000);	   // delay 
	DrvGPIO_SetBit(E_GPC, 12); // output Hi to turn off LED	
	DrvSYS_Delay(300000);	   // delay	
		
	DrvGPIO_ClrBit(E_GPC, 13); // output Low to turn on LED
	DrvSYS_Delay(300000);	   // delay 
	DrvGPIO_SetBit(E_GPC, 13); // output Hi to turn off LED	
	DrvSYS_Delay(300000);	   // delay	
		
	DrvGPIO_ClrBit(E_GPC, 14); // output Low to turn on LED
	DrvSYS_Delay(300000);	   // delay 
	DrvGPIO_SetBit(E_GPC, 14); // output Hi to turn off LED	
	DrvSYS_Delay(300000);	   // delay
		
	DrvGPIO_ClrBit(E_GPC, 15); // output Low to turn on LED
	DrvSYS_Delay(300000);	   // delay 
	DrvGPIO_SetBit(E_GPC, 15); // output Hi to turn off LED	
	DrvSYS_Delay(300000);	   // delay
		
	}
}
