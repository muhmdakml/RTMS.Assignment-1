//
// Smpl_GPIO_Buzz5: Buzz 5 times
// GPB11 low-active output control Buzzer
// Note: Nu-LB-NUC140 R1 should be 0 ohm
//
#include <stdio.h>
#include "NUC1xx.h"
#include "SYS.h"
#include "GPIO.h"

// Function: input the number of buzz
void Buzz(int number)
{
	int i;
	for (i=0; i<number; i++) {
	  DrvGPIO_ClrBit(E_GPB,11); // GPB11 = 0 to turn on Buzzer
	  DrvSYS_Delay(100000);	 // Delay 
	  DrvGPIO_SetBit(E_GPB,11); // GPB11 = 1 to turn off Buzzer	
	  DrvSYS_Delay(100000);	 // Delay 
	}
}

int main (void)
{					   
	int n = 5;			//Set variable to n to run 5 times
	while (n > 0)		//Run program 5 times with n is reduced by one per iteration 
	{
	UNLOCKREG();	   // unlock register for programming
	DrvSYS_Open(50000000);// set System Clock to run at 48MHz
	LOCKREG();		   // lock register from programming

	DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); // initial GPIO pin GPB11 for controlling Buzzer

	Buzz(5);	// Buzz 5 times
	DrvSYS_Delay(300000);	//Delay 
	n--; //Reduce n until n = 0 and break loop
	}
}