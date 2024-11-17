#include <stdio.h>
#include <stdlib.h>
#include "led_sys.h"

#define LED 31

int main()
{
	printf("******************************\n");
	printf("***** Linux From Scratch *****\n\n");
	
	GPIOExport(LED);
	GPIODirection(LED,OUT);
	GPIOWrite(LED,HIGH);
	
	return 0;
}
