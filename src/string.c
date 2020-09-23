#include "../include/string.h"

void* memcpy(void* dst, void* src, unsigned sz)
{
	char* p1 = dst;
	char *p2 = src;

	while(sz--)
		*p1++ = *p2++;

	return dst;
}

void* memset(void* dst, const char value, unsigned sz)
{
	char *p = dst;

	while(sz--)
		*p++ = value;

	return dst;
}

unsigned short* memsetw(unsigned short* dst, unsigned short value, unsigned sz)
{
	unsigned short* p = dst;

	while(sz--)
		*p++ = value;

	return dst;
}

unsigned strlen(char* str)
{
	unsigned i = 0;

	while(*str++)
		i++;

	return i;
}

