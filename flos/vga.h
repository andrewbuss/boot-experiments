#pragma once
#include "common.h"

void vga_put(char c, bool exec);
void vga_setchar(char c, byte x, byte y);
void vga_setattr(byte a, byte x, byte y);
char vga_getchar(byte x, byte y);
void vga_copy(byte sx, byte sy, byte dx, byte dy, byte wide, byte tall);
void vga_clear(byte a);
void vga_print(char *c);
void vga_printat(char *c, byte x, byte y);
void vga_printhexbyte(byte a);
static void vga_updatecursor();
static void vga_scroll();

