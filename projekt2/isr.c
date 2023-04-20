/********************************************************************************
* isr.c: Innehåller avbrottsrutiner.
********************************************************************************/
#include "display.h"
#include "header.h"

/********************************************************************************
* ISR (PCINT0_vect)
********************************************************************************/
ISR(PCINT0_vect)
{
	if(button_is_pressed(&button1))
	{
		display_toggle_count();
	}
	else if(button_is_pressed(&button2))
	{
		display_toggle_count_direction();
	}
	else if(button_is_pressed(&button3))
	{
		display_toggle_output();
	}
}

/********************************************************************************
* ISR (TIMER1_COMPA_vect): Avbrottsrutin som äger rum vid uppräkning till 256 av
*                          Timer 1 i CTC Mode, vilket sker var 0.128:e
*                          millisekund när timern är aktiverad. En gång per
*                          millisekund togglas talet utskrivet på 
*                          7-segmentsdisplayerna mellan tiotal och ental.
********************************************************************************/
ISR (TIMER1_COMPA_vect)
{
   display_toggle_digit();
   return;
}

/********************************************************************************
* ISR (TIMER2_OVF_vect): Avbrottsrutin som äger rum vid uppräkning till 256 av
*                        Timer 2 i Normal Mode, vilket sker var 0.128:e
*                        millisekund när timern är aktiverad. En gång per sekund
*                        inkrementeras talet utskrivet på 7-segmentsdisplayerna.
********************************************************************************/
ISR (TIMER2_OVF_vect)
{
   display_count();
   return;
}
