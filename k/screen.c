#include "kernel.h"
#include "screen.h"
#include "port.h"

char* hexdigits = "0123456789ABCDEF";

void k_setchar(char c, byte x, byte y, byte a){
  byte * vr = (byte *) 0xb8000+y*160+x*2;
  *vr = c;
  if(a>0) *(vr+1) = a;
}

void k_clearscreen(byte a){
  byte x = 0;
  while(x<80){
    byte y = 0;
    while(y<25){
      k_setchar(0,x,y,a);
      y++;
    }
    x++;
  }
}

void k_print(char* a, byte x, byte y){
  while (*a != 0){
    if(*a=='\n' || x==80){
      k_scroll();
      x=0;
    }
    k_setchar(*a, x, y, 0);
    x++;
    a++;
  }
}

void k_scroll(){
  word * src = (word *) 0xb80A0;
  word * dst = (word *) 0xb8000;
  while(src<(word*) 0xb8fa0){
    *dst = *src;
    dst++;
    src++;
  }
  while(dst<(word*) 0xb8fa0){
    *dst = 0;
    dst++;
  }
}

void k_setcursorpos(byte x, byte y){
  word position=y*80+x;
  k_outportb(0x3D4, 0x0F);
  k_outportb(0x3D5, (unsigned char)(position&0xFF));
  k_outportb(0x3D4, 0x0E);
  k_outportb(0x3D5, (unsigned char)((position>>8)&0xFF));
}

char* htoa(byte h){
  char b = hexdigits[h%16];
  char a = hexdigits[(h-h%16)/16];
  char* c = a,b;
}
  
