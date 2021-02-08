#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	//first wee will configure the output LED present on the port P1.0
	P1DIR=P1DIR|0x01;//first wee will configure the output LED present on the port P1.0
	P1REN=P1REN|0x02; // now we will do the pullup request of port 1 enable or say for that switch
	P1OUT=P1OUT|0x02; // now we will send the same signal to the output as the starting one should be same
	while(1)
	{
	    if(P1IN & BIT1) // this loop will check whether the input switch is 1 and will be anded with the bit which is at 0x02 adderess
	    {
	        P1OUT=P1OUT|BIT0; // here out will be or with the bit present at the P1DIR LED so bit 0
	    }
	    else// so if the bit value will be less than the processer will always come to this section
	    {
	        P1OUT=P1OUT&~(BIT0);//here and means we always want the led off
	    }
	}
	return 0;
}
