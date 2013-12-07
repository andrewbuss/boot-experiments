PREFIX=/home/andrew/p/asm/cc
AS=yasm 
LD=$(PREFIX)/bin/i586-elf-ld
CC=$(PREFIX)/bin/i586-elf-gcc

LIB=-L $(PREFIX)/i586-elf/lib -L $(PREFIX)/lib/gcc/i586-elf/4.6.1
INC=-I $(PREFIX)/i586-elf/include -I $(PREFIX)/lib/gcc/i586-elf/4.6.1/include
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -std=c99 $(INC) $(LIB)
LDFLAGS=-m elf_i386 $(LIB) -l c -l gcc -T link.ld
ASFLAGS=-felf

all: link 

clean:
	-rm -v *.o
	-rm -v kernel

again: clean all

link: $(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.s,%.o,$(wildcard *.s))
	ld -o kernel *.o $(LDFLAGS)

.s.o:
	$(AS) $(ASFLAGS) $<


