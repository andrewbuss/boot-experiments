#pragma once

#define u8int unsigned char
#define s8int char
#define u16int unsigned short
#define s16int short
#define u32int unsigned int
#define s32int int
#define word unsigned short
#define dword unsigned int
#define bool unsigned char
#define byte unsigned char
#define true 1
#define false 0

void outb(word port, byte value);
byte inb(word port);
word inw(word port);
