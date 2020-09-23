ENTRY(start)
OUTPUT_FORMAT("elf32-i386")

phys = 0x00100000;

SECTIONS
{
	.text phys :
	{
		textStart = .;
		*(.text)
		*(.text.*)
		*(.rodata.*)
		*(.rdata.*)
		. = ALIGN(4096);
	}
	textEnd = .;

	.data :
	{
		dataStart = .;
		*(.data*)

		. = ALIGN(4096);
	}
	dataEnd = .;

	.bss :
	{
		bssStart = .;
		*(.common)
		*(.bss*)

		. = ALIGN(4096);
	}
	bssEnd = .;
	end = .;
}

