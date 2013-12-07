#pragma once
#include "kernel.h"

typedef struct{
  word low_offset;                        
  word selector;                          
  word settings;                          
  word high_offset;                       
} __attribute__((__packed__)) x86_interrupt;

typedef struct{
  word limit;
  x86_interrupt* base;
} __attribute__((__packed__)) idtr;

idtr IDTR;
x86_interrupt IDT[256];

void k_loadIDTR();
void k_addinterrupt(byte number, void (*handler)(), byte gatetype, bool storagesegment, byte dpl);
void k_remapPIC(byte pic1, byte pic2);      //remap PIC
void k_maskIRQ(byte irq);                 //PIC irq masking
void k_unmaskIRQ(byte irq);               //PIC irq unmasking
void k_disableinterrupts();
void k_enableinterrupts();
extern void raiseinterrupt();

