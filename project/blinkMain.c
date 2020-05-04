//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "my_switches.h"
#include "led.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "my_buzzer.h"
int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  switch_init();
  buzzer_init();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  enableWDTInterrupts();	/* enable periodic interrupt */
  clearScreen(COLOR_BLUE);//makes blue background color
  drawString8x12(5,8,"hello",COLOR_WHITE,COLOR_RED);
  or_sr(0x18);		/* CPU off, GIE on */
}
//draws hexagon in white
//max parameter changes size
void drawHex(u_char x_right, u_char x_left, u_char center_y, int max)
{
  for(int i =0; i < max; i++){ //horizontal lines
    drawPixel(x_right+i, center_y+max, COLOR_WHITE);
    drawPixel(x_right+i, center_y-max,COLOR_WHITE);
    drawPixel(x_left-i,center_y+max,COLOR_WHITE);
    drawPixel(x_left-i,center_y-max,COLOR_WHITE);
  }
  for (int i=0; i < max; i++)//diagonal lines
  {
    drawPixel((x_right+max*2)-i,center_y+i,COLOR_WHITE);
    drawPixel((x_right+max*2)-i,center_y-i,COLOR_WHITE);
    drawPixel((x_left-max*2)+i,center_y+i,COLOR_WHITE);
    drawPixel((x_left-max*2)+i,center_y-i,COLOR_WHITE);
  }
}
      
