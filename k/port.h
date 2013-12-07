#pragma once
#include "kernel.h"

void k_outportb(dword port,byte value);
void k_outportw(dword port,dword value);
byte k_inportb(dword port);
