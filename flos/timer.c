#include "timer.h"
#include "isr.h"
#include "vga.h"

u32int tick = 0;

static void timer_callback(registers_t regs){
   tick++;
   if(tick==1) vga_print("received PIT tick: OK\nWaiting 25 ticks: ");
   if(tick>1 && tick<25) vga_print(".");
   if(tick == 25) vga_print("\n");
}

void init_timer(u32int frequency){
  register_interrupt_handler(32, &timer_callback);
  u32int divisor = 1193180 / frequency;
  outb(0x43, 0x36);
  u8int l = (u8int)(divisor & 0xFF);
  u8int h = (u8int)( (divisor>>8) & 0xFF );
  outb(0x40, l);
  outb(0x40, h);
}

void wait(int nticks){
  int start = tick;
  while(tick != start+nticks){}
}
