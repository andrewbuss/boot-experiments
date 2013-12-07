#include "keyboard.h"
#include "common.h"
#include "isr.h"
#include "vga.h"

char buffer[256];
byte buffront = 0;
byte shiftstate = 0;
char keymap[256] = {0,0x1b,'1','2','3','4','5','6','7','8','9','0','-',
		     '=','\b','\t','q','w','e','r','t','y','u','i','o',
		     'p','[',']','\n',0,'a','s','d','f','g','h','j','k',
		    'l',';','\'', 0,0, '\\','z','x','c','v','b','n','m',',','.',
		    '/',0,0,0,' '};
static void keyboard_callback(){
  byte scancode = inb(0x60);
  switch(scancode) {
  case 0x2a: 
    shiftstate = 1; 
    break;
  case 0xaa: 
    shiftstate = 0;
    break; 
  case 0x80:
    break;
  default:
    vga_put(keymap[scancode],true);
    break;
  }
}

void init_keyboard(){
  register_interrupt_handler(33, &keyboard_callback);
}

