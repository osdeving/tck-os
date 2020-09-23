#ifndef STRING_H
#define STRING_H

void* memcpy(void* dst, void* src, unsigned sz);
void* memset(void* dst, const char value, unsigned sz);
unsigned short* memsetw(unsigned short* dst, unsigned short value, unsigned sz);
unsigned strlen(char* str);

#endif /* STRING_H */

