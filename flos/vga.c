#pragma once

#include "vga.h"
#include "common.h"
#include "commands.h"

static byte cursor_x=0;
static byte cursor_y=1;
static byte currattr=0x07;

static char* hexdigits = "0123456789ABCDEF";

char buffer[1024];
char blen = 0;

static void vga_scroll(){
  if(cursor_y >= 24){
    for(byte x=0; x<80; x++){
      for(byte y=0; y<23; y++){
	vga_setchar(vga_getchar(x, y+1),x,y);
      }
    }
    for (int i = 23*80; i < 24*80; i++) *((byte *) 0xB8000+2*i) = ' ';
    cursor_y = 23;
  }
}

void vga_copy(byte sx, byte sy, byte dx, byte dy, byte w, byte t){
  for(byte x=0; x<=w; x++){
    for(byte y=0; y<=t; y++){
      vga_setchar(vga_getchar(sx+x, sy+y),dx+x,dy+y);
    }
  }
}

void vga_setcurrattr(byte a){
  currattr = a;
}

char vga_getchar(byte x, byte y){
  byte* vr = (byte*) 0xB8000 + 2*(80*y+x);
  return *vr;
}

void vga_setchar(char c, byte x, byte y){
  *((byte*) 0xB8000 + 2*(80*y+x)) = c;
}

void vga_setattr(byte a, byte x, byte y){
  *((byte*) 0xB8001 + 2*(80*y+x)) = a;
}

void vga_put(char c, bool exec){
  word *location;
  if (c == 0x08 && cursor_x>1){
    vga_setchar(0, cursor_x-1, cursor_y);
    cursor_x--;
  }
  else if (c == 0x09) cursor_x = (cursor_x+8) & ~(8-1);
  else if (c == '\r') cursor_x = 0;
  else if (c == '\n'){
    cursor_x = 1;
    cursor_y++;
    if(exec) submitcommand(&buffer);
    blen = 0;
    for(int i = 0; i<1024; i++){buffer[i]=0;}
  }
  else if(c >= ' '){
    buffer[blen] = c;
    blen++;
    buffer[blen] = 0;
    vga_setattr(currattr, cursor_x, cursor_y);
    vga_setchar(c,cursor_x,cursor_y);
    cursor_x++;
  }
  if (cursor_x >= 80){
    cursor_x = 1;
    cursor_y++;
  }
  vga_scroll();
  vga_updatecursor();
}

void vga_clear(byte a){
  word* vr = (word *) 0xB8000;
  word b = (a << 8);
  while(vr < 0xB8FA0){
    *vr = b;
    vr++;
  }
}

static void vga_updatecursor(){
  word cursorLocation = cursor_y * 80 + cursor_x;
  outb(0x3D4, 14);                  // Tell the VGA board we are setting the high cursor byte.
  outb(0x3D5, cursorLocation >> 8); // Send the high cursor byte.
  outb(0x3D4, 15);                  // Tell the VGA board we are setting the low cursor byte.
  outb(0x3D5, cursorLocation);      // Send the low cursor byte.
}

void vga_print(char* c){
  while(*c != 0){
    vga_put(*c, false);
    c++;
  }
}

void vga_printat(char* c, byte x, byte y){
  while(*c != 0){
    vga_setchar(*c, x, y);
    c++;
    x++;
  }
}

void vga_printhexbyte(byte a){
  vga_put(hexdigits[(a-(a%16))/16],false);
  vga_put(hexdigits[a%16],false);
}
