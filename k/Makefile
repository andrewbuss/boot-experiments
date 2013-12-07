PREFIX=/home/andrew/p/asm/cc
CC=$(PREFIX)/bin/i586-elf-gcc
CFLAGS= -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -std=c99
LD=$(PREFIX)/bin/i586-elf-ld
AS=yasm
ASFLAGS= -f elf

all: kernel.bin

objects: $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.s,%.o,$(wildcard *.s))

kernel.bin: objects
	$(LD) -T linker.ld -o kernel.bin *.o

clean:
	rm *.o 
	rm *.bin

again: clean all
