[bits 32]

[extern main]
[global start]

BOOT_PAGE_ALIGN		equ 1<<0
BOOT_MEMORY_INFO	equ 1<<1
BOOT_HEADER_MAGIC	equ 0x1BADB002
BOOT_HEADER_FLAGS	equ BOOT_PAGE_ALIGN | BOOT_MEMORY_INFO
BOOT_CHECKSUM		equ -(BOOT_HEADER_MAGIC + BOOT_HEADER_FLAGS)

section .text

start:
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	mov esp, 0x000A0000

	call main	
	cli
	hlt

ALIGN 4
boot:
    dd BOOT_HEADER_MAGIC
    dd BOOT_HEADER_FLAGS
    dd BOOT_CHECKSUM

