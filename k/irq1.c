#include "port.h"
#include "screen.h"
#include "interrupthandlers.h"

void int128(){
  k_setchar(' ',26,10,0xF0);
  byte scancode = k_inportb(0x60);
  if(scancode == 0x5A) k_scroll();
  k_outportb(0x20,0x20);
}
