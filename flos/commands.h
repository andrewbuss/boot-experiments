#pragma once

#include "vga.h"
#include <string.h>

void submitcommand(char* buffer){
  if(buffer[0] != 0){
    if(!strcmp("echo",buffer)){
      vga_print("Echo command received\n");
    }else{
      vga_print("Unknown command!\n");
    }
  }
}
