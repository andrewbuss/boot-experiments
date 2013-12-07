#include "kernel.h"
#include "port.h"

void k_outportb(dword port,byte value){
  __asm__ volatile ("outb %%al,%%dx"::"d" (port), "a" (value));
}


void k_outportw(dword port,dword value){
  __asm__ volatile ("outw %%ax,%%dx"::"d" (port), "a" (value));
}

byte k_inportb(dword port){
  byte value;
  __asm__ volatile ("inb %w1,%b0" : "=a"(value) : "d"(port));
  return value;
}
