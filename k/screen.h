#pragma once
#include "kernel.h"

void k_setchar(char c, byte x, byte y, byte a);
void k_clearscreen(byte a);
void k_print(char* a, byte x, byte y);
void k_scroll();
void k_setcursorpos(byte x, byte y);
