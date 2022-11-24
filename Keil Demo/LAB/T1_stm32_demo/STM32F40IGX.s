;STM32F40IGX    
    AREA RESET, CODE, READONLY
    THUMB                           ; Code with THUMB 2 mode
IN DCD 0x20000100, 0x80000009       ; SP_start : 0x20000000 Offset: 0x100, RESET Vector start at 0x80000009
    ENTRY
    LDR R4, =SRC
    LDR R5, =DST
    LDR R0,[R4],#4
    LDR R1,[R4],#4
    LDR R2,[R4]
    ADD R0,R0,R1
    SUB R0,R0,R2
    STR R0,[R5]
LOOP
    B LOOP
SRC DCD 0x30303030, 0x20202020, 0x40404040
    AREA RES1, DATA, READWRITE
DST DCD 0x00
    END