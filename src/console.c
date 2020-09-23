#include "../include/console.h"
#include "../include/string.h"
#include "../include/utils.h"

#define VIDEORAM 0xB8000
#define COLS     80
#define LINES    25

static unsigned curr_x = 0;
static unsigned curr_y = 0;
static unsigned short attribute = 0x0700;

static void scroll_up()
{

}

static void putc_internal(char c)
{
	switch(c)
	{
		case '\n':
			curr_x = 0;
			curr_y++;

			if(curr_y > LINES)
				scroll_up();
			return;

		case '\r':
			curr_x = 0;
			return;

		case '\t':
			curr_x = (curr_x + 8) & ~(8 - 1);
			return;

		case '\b':
			return;

		case '\a':
			return;
	}



	unsigned short* video = (unsigned short*)VIDEORAM;

	video[curr_x + curr_y * COLS] = attribute | c;

	if(++curr_x > COLS)
	{
		curr_x = 0;
		curr_y++;

		if(curr_y > LINES)
		{
			scroll_up();
		}
	}
}

static void itoa(char* buf, unsigned sz, unsigned num, unsigned base)
{
	int i = 0;
	int j = 0;

	do
	{
		unsigned rem = num % base;
		buf[i++] = "0123456789ABCDEF"[rem];

	} while(num /= base);



	while(i != j)
	{
		if((i - j) == 1) break;

		--i;
		buf[i] ^= buf[j];
		buf[j] ^= buf[i];
		buf[i] ^= buf[j];
		++j;
	}
}

void setforeground(unsigned char color)
{
	unsigned short c = color & 0x0F;
	attribute = (attribute & 0xF000) | (c << 8);
}

void setbackground(unsigned char color)
{
	unsigned short c = color & 0xF0;
	attribute = (attribute & 0x0F00) | (c << 8);
}

unsigned char getforeground()
{
	return (unsigned char)((attribute >> 8) & 0x000F);
}

unsigned char getbackground()
{
	return (unsigned char)((attribute >> 12) & 0x00F0);
}

void move_cursor(int x, int y)
{
	curr_x = x;
	curr_y = y;

	unsigned temp;

	temp = curr_y * COLS + curr_x;

	outportb(0x3D4, 14);
	outportb(0x3D5, temp >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
}

void clear()
{
	unsigned short attr = attribute | ' ';
	unsigned short* video = (unsigned short*)VIDEORAM;

	memsetw(video, attr, COLS * LINES);

	move_cursor(0, 0);
}

void putc(char c)
{
	putc_internal(c);
	move_cursor(curr_x, curr_y);
}

void kprintf(char* format, ...)
{
	char *p = format;
	char **arg = (char**)&format;
	arg++;
	unsigned base = 0;

	while(*p)
	{
		if(*p == '%')
		{
			p++;

			switch(*p)
			{
				case '%':
				{
					putc_internal('%');
					p++;
					break;
				}

				case 'b':
				case 'B':
					base = 2;
					break;
				case 'o':
				case 'O':
					base = 8;
					break;
				case 'x':
				case 'X':
					base = 16;
					break;
				case 'd':
				case 'D':
					base = 10;
					break;

				case 'c':
				case 'C':
				{
					putc_internal(*((char *) arg++));
					p++;
					break;
				}

				case 's':
				case 'S':
				{
					char *text = (char*)*arg++;
					while(*text)
						putc_internal(*text++);
					p++;

					break;
				}

				default:
					break;
			}

			if(!base) continue;

			char buf[32] = {0};
			itoa(buf, 32, *((int *) arg++), base);

			char *text = buf;
			while(*text)
				putc_internal(*text++);
			p++;

			base = 0;

			continue;
		}

		putc_internal(*p++);
	}

	move_cursor(curr_x, curr_y);
}
