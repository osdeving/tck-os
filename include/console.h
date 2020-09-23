#ifndef CONSOLE_H
#define CONSOLE_H

#define INTENSITY  0x08
#define BLICKING   0x80

#define FG_BLACK   0x00
#define FG_BLUE    0x01
#define FG_GREEN   0x02
#define FG_CYAN    0x03
#define FG_RED     0x04
#define FG_MAGENTA 0x05
#define FG_BROWN   0x06
#define FG_GREY    0x07

#define BG_BLACK   0x00
#define BG_BLUE    0x10
#define BG_GREEN   0x20
#define BG_CYAN    0x30
#define BG_RED     0x40
#define BG_MAGENTA 0x50
#define BG_BROWN   0x60
#define BG_GREY    0x70


void kprintf(char* format, ...);
void putc(char c);
void clear();
void move_cursor(int x, int y);

void setforeground(unsigned char color);
void setbackground(unsigned char color);
unsigned char getforeground();
unsigned char getbackground();

#endif /* CONSOLE_H */
