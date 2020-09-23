OBJS = start.o main.o string.o console.o utils.o
CFLAGS = -Wall -O -fno-builtin -fno-exceptions -nostdlib -nostdinc

all: $(OBJS) link
	
clean:
	rm *.o
	rm ../bin/kernel.sys

link:
	ld -T ../config/link.ld -o ../bin/kernel.sys $(OBJS) -M >> ../config/mapfile.map

.s.o:
	nasm -felf $< -o $@

.c.o:
	gcc $(CFLAGS) -c $< -o $@

