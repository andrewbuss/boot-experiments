#include "common.h"

void outb(word port, byte value){
  __asm__ volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

byte inb(word port){
  byte ret;
  __asm__ volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}

word inw(word port){
  u16int ret;
  __asm__ volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
  return ret;
}
