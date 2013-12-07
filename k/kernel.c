#include "screen.h"
#include "interrupt.h"
#include "interrupthandlers.h"

void kmain(){
  k_clearscreen(0x07);
  char* prompt = "$]";
  k_print(prompt,2,2);
  k_disableinterrupts();
  k_setchar(' ', 10, 10, 0xFF);
  k_maskIRQ(0xFF);
  k_setchar(' ', 12, 10, 0xFF);
  k_remapPIC(0x20,0x30);
  k_setchar(' ', 14, 10, 0xFF);
  k_addinterrupt(0x80, int128,true,14,0);
  k_setchar(' ', 16, 10, 0xFF);
  k_loadIDTR();
  k_setchar(' ', 18, 10, 0xFF);
  k_unmaskIRQ(0xFF);
  k_setchar(' ', 20, 10, 0xFF);
  k_enableinterrupts();
  k_setchar(' ', 22, 10, 0xFF);
  k_scroll();
  k_setcursorpos(5,1);
  raiseinterrupt();
}
