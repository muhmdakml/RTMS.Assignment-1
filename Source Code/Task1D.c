//
// Smpl_7seg : counting from 0 to 9999 and display on 7-segment LEDs
//
#include <stdio.h>																											 
#include "NUC1xx.h"
#include "SYS.h"
#include "Seven_Segment.h"

// display an integer on four 7-segment LEDs
void seg_display(int16_t value)
{
  int8_t digit;
	digit = value / 1000;
	close_seven_segment();
	show_seven_segment(3,digit);
	DrvSYS_Delay(5000);
			
	value = value - digit * 1000;
	digit = value / 100;
	close_seven_segment();
	show_seven_segment(2,digit);
	DrvSYS_Delay(5000);

	
//DISABLE TWO REAR 7SEG AND THIS WILL AUTOMATICALLY MAKE THE 7SEG TO CHANGE BY 1 SEC INTERVAL
//NO CHANGES MADE TO SEVEN_SEGMENT.C
	
	
//	value = value - digit * 100;
//	digit = value / 10;
//	close_seven_segment();
//	show_seven_segment(1,digit);
//	DrvSYS_Delay(5000);

//	value = value - digit * 10;
//	digit = value;
//	close_seven_segment();
//	show_seven_segment(0,digit);
//	DrvSYS_Delay(5000);
}

int32_t main (void)
{
	uint32_t i=0;
	
	UNLOCKREG();           // Unlock System Registers
	DrvSYS_Open(48000000); // set CPU clock to 25~50MHz
	LOCKREG();	           // Lock System Registers

  DrvSYS_Delay(1000);	

 	while(1) 
	{
	  seg_display(i);		// display i on 7-segment display	
		i++;
		if (i>9999) i=0;	
	}
}
