; Controller: STM32F407IGX 
; Architecture: ARMv7T
; Q.2. Write an assembly language program (ALP) in Keil uV5 for 
; STM-32 to find the largest integer from a collection 
; of 10 signed integers stored in consecutive memory 
; locations in ROM and store the result in RAM.
; Also take a suitable snapshot of the KEIL IDE 
; in the debug mode to demonstrate the desired output 
;(Register window, Memory window for RAM/ROM). 
; Ensure that the screenshot captures system time & day. 
; Comment your code.

	AREA RESET, CODE, READONLY
    THUMB                           ; Code with THUMB 2 mode
IN DCD 0x20000100, 0x80000009       ; SP_start : 0x20000000 Offset: 0x100, RESET Vector start at 0x80000009
	ENTRY
    LDR R4, =SRC					; Load Source Address in R4
    LDR R5, =DST					; Load Dest Address in R5
CMPL
	LDR R0,[R4],#4					; Load value at address present in R4. Post increment R4 by 4
	CMP R0,R1						; Compare the values kept at R0 and R1
	MOVGE R1,R0						; Replace value at R1 with R0 if R0 >= R1
	ADD R3,R3,#1					; Increment counter register
	CMP R3, #10						; Counter compare with max value i.e., 10
	BLT CMPL						; Loop back to CMPL if R3 is less than 10
	STR R1,[R5]						; Store max value in Dest Address
LOOP
    B LOOP
SRC DCD 30, 40, -20, -30, 50, 40, 12, 122, 16, -333
    AREA RES1, DATA, READWRITE
DST DCD 0x00
    END