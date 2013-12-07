#include "interrupt.h"
#include "kernel.h"
#include "port.h"

void k_loadIDTR(){
  IDTR.limit = 256*(sizeof(x86_interrupt)-1);
  IDTR.base = IDT;
  idtr* IDTRptr = &IDTR;
  __asm__ __volatile__("LIDT (%0) ": : "p" (IDTRptr));
}

void k_addinterrupt(byte number, void (*handler)(), byte gatetype, bool storagesegment, byte dpl){
  word selector = 0x08;
  word settings = 0;
  dword offset = (dword) handler;
  __asm volatile("movw %%cs,%0" :"=g"(selector));
  IDT[number].low_offset = (offset & 0xFFFF);
  IDT[number].selector = selector;
  IDT[number].high_offset = (offset >> 16);
  settings = (word) 0x01;
  settings = settings << 2;
  settings = settings & (dpl & 0x03);
  settings = settings << 1;
  settings = settings & (storagesegment & 0x01);
  settings = settings << 4;
  settings = settings & (gatetype & 0x0f);
  settings = settings << 8;
  settings = 0x8E;
  IDT[number].settings = settings;
}

void k_remapPIC(byte pic1, byte pic2){
  byte md = k_inportb(0x21);
  byte sd = k_inportb(0xA1);
  k_outportb(0x20, 0x20);                  
  k_outportb(0x20, 0x11);  
  k_outportb(0xA0, 0x11); 
  k_outportb(0x21, pic1);                 
  k_outportb(0xA1, pic2);                
  k_outportb(0x21, 0x04);                
  k_outportb(0xA1, 0x02);
  k_outportb(0x21, 0x01);           
  k_outportb(0xA1, 0x01);
  k_outportb(0x21,md);                   
  k_outportb(0xA1,sd);                  
}

void k_maskIRQ(byte irq){
  if(irq==0xFF){
    k_outportb(0x21,0xFF);
    k_outportb(0xA1, 0xFF);
  }else{
    irq = irq | (1<<irq);
    if(irq < 8) k_outportb(0x21,irq & 0xFF);
    else k_outportb(0xA1, irq>>8);
  }
}

void k_unmaskIRQ(byte irq){
  if(irq==0xFF){
    k_outportb(0x21,0x00);
    k_outportb(0xA1,0x00);
  }else{
    irq = irq & (1<<irq);
    if(irq<8) k_outportb(0x21,irq & 0xFF);
    else k_outportb(0xA1, irq>>8);
  }
}

void k_enableinterrupts(){
  __asm__("sti");
}

void k_disableinterrupts(){
  __asm__("cli");
}
