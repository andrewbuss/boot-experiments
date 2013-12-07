#include "common.h"
#include "isr.h"
#include "vga.h"

isr_t interrupt_handlers[256];
void isr_handler(registers_t regs){
   vga_print("\tRecieved interrupt:\t0x");
   vga_printhexbyte(regs.int_no);
   vga_print("\n");
}



void irq_handler(registers_t regs){
  if (regs.int_no >= 40) outb(0xA0, 0x20);
  outb(0x20, 0x20);
  if (interrupt_handlers[regs.int_no] != 0){
    isr_t handler = interrupt_handlers[regs.int_no];
    handler(regs);
  }
}

void register_interrupt_handler(u8int n, isr_t handler){
  interrupt_handlers[n] = handler;
}

void panic(byte exception){
  vga_setcurrattr(0x0c);
  vga_print("\n\n==  Kernel Panic!  ==\n== Exception: 0x");
  vga_printhexbyte(exception);
  vga_print(" ==\n==   Description   ==\n");
  switch(exception){
  case 0x00: vga_print("Divide by Zero Error\n"); break;
  case 0x01: vga_print("Debug Error\n"); break;
  case 0x02: vga_print("Non-Maskable Interrupt (NMI)\n"); break;
  case 0x03: vga_print("Breakpoint\n"); break;
  case 0x04: vga_print("Overflow\n"); break;
  case 0x05: vga_print("Bound Range Exceeded"); break;
  case 0x06: vga_print("Invalid Opcode\n"); break;
  case 0x07: vga_print("Device Not Available\n"); break;
  case 0x08: vga_print("Double Fault\n"); break;
  case 0x09: vga_print("Coprocessor Segment Overrun\n"); break;
  case 0x0a: vga_print("Invalid TSS\n"); break;
  case 0x0b: vga_print("Segment not Present\n"); break;
  case 0x0c: vga_print("Stack Segment Fault\n"); break;
  case 0x0d: vga_print("General Protection Fault\n"); break;
  case 0x0e: vga_print("Page Fault\n"); break;
  case 0x10: vga_print("FPU Floating Point Error\n"); break;
  case 0x11: vga_print("Alignment Check\n"); break;
  case 0x12: vga_print("Machine Check\n"); break;
  case 0x13: vga_print("SIMD Floating-Point\n"); break;

  }
  __asm__ volatile("hlt");
}

void exceptionhandler(registers_t registers){
  panic(registers.int_no);
}
  
