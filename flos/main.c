
#include "vga.h"
#include "common.h"
#include "idt.h"
#include "gdt.h"
#include "timer.h"
#include "isr.h"
#include "keyboard.h"
#include <string.h>

int main(struct multiboot *mboot_ptr)
{
  vga_clear(0x07);
  vga_print("Welcome to FLOS.\nSetting up GDT: ");
  init_gdt();
  vga_print("OK\nSetting up IDT: ");
  init_idt();
  vga_print("OK\nTesting interrupts:\n\tSending interrupt:\t0xFF\n");
  __asm__ volatile("int $0xFF");
  vga_print("Enabling timer: ");
  __asm__ volatile("sti");
  init_timer(25);
  vga_print("OK\nExpecting PIT tick... ");
  wait(25);
  vga_print("1 second and 25 ticks have elapsed.\nEnabling keyboard: ");
  init_keyboard();
  vga_print("OK\n\n");
  unsigned int* c = (unsigned int*)0;
  while(1){
    *c = 0;
    c++;
  }
  return 0xDEADF411;
}
