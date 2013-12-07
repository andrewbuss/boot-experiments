#include "idt.h"
#include "common.h"
#include <string.h>
#include "isr.h"

extern void idt_flush(u32int);
void init_idt();
static void idt_set_gate(u8int,u32int,u16int,u8int);
idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;
extern isr_t interrupt_handlers[];

void init_idt()
{
  idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
  idt_ptr.base  = (u32int)&idt_entries;
  memset(&idt_entries, 0, sizeof(idt_entry_t)*256);
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x0);
  outb(0xA1, 0x0);
  for(int i=0; i<32; i++){
    idt_set_gate(i, (u32int) exceptionhandler, 0x08, 0x8E);
  }
  idt_set_gate(32, (u32int) irq0, 0x08, 0x8E);
  idt_set_gate(33, (u32int) irq1, 0x08, 0x8E);
  idt_set_gate(255, (u32int)isr255 , 0x08, 0x8E);
  idt_flush((u32int)&idt_ptr);
  memset(&interrupt_handlers, 0, sizeof(isr_t)*256);
}

static void idt_set_gate(u8int num, u32int base, u16int sel, u8int flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[num].sel     = sel;
   idt_entries[num].always0 = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
   idt_entries[num].flags   = flags /* | 0x60 */;
}

