MBT_HDR_FLAGS EQU 0x00010003
MBT_HDR_MAGIC EQU 0x1BADB002
MBT2_MAGIC EQU 0xe85250d6
global _start
extern inithead_entry
[section .text]
[bits 32]
_start:
    jmp _entry
align 4
mbt_hdr:
    dd MBT_HDR_MAGIC
    dd MBT_HDR_FLAGS
    dd -(MBT_HDR_MAGIC+MBT_HDR_FLAGS)
    dd mbt_hdr
    dd _start
    dd 0
    dd 0
    dd _entry
ALIGN 8
mbhdr:
    DD 0xE85250D6
    DD 0
    DD mhdrend - mbhdr
    DD -(0xE85250D6 + 0 + (mhdrend - mbhdr))
    DW 2, 0
    DD 24
    DD mbhdr 
    DD _start
    DD 0
    DD 0
    DW 3, 0
    DD 12
    DD _entry
    DD 0
    DD 0, 0
    DD 8
mhdrend: