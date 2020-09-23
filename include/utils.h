#ifndef UTILS_H
#define UTILS_H

#include "console.h"
#include "string.h"

unsigned char inportb (unsigned short _port);
void outportb (unsigned short _port, unsigned char _data);

#define PANIC(text) do {\
setforeground(FG_RED);\
	clear();\
	const unsigned len = strlen(text);\
	move_cursor(80/2 - len / 2, 12);\
	setforeground(FG_BROWN|INTENSITY);\
	kprintf(text);\
	putc('\n');\
	move_cursor(80/2 - len / 2, 13);\
	kprintf("%s: %d", __FILE__, __LINE__);\
	for(;;);\
} while(0)\

typedef struct _regs_t
{
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss;
} regs_t;

#endif /* UTILS_H */

