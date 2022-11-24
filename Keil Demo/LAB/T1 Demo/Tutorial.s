; ROM Data region declaration	
	AREA RESET, CODE, READONLY		; Define Code Section
	ENTRY							; Entry point of Assembler
START								; Start of code section
; A = B+C-D
; Code  starts here
	LDR R6, =A						; Load A to R6
	ADR R5,B						; Load Address of B to R5
	LDR R0,[R5],#4					; [Reg] means point to the value at address stored in Reg. De-refernece R5 and store in R0. Increment R5 by 4 bytes		
	LDR R1,[R5],#4					; De-refernece R5 and store in R2. 
	LDR R2,[R5]						; Load without increment
	ADD R0,R0,R1					; ADD R0 and R1 and store in R0
	SUB R4,R0,R2					; SUB R0 and R2 and store in R4
	STR R4,[R6]						; Store data location pointed by R6
loop
	b loop							; End Loop
STOP
; Constant data declarations
B	DCD 0x11223344, 0x44559933, 0x00002233
; RAM Data region declaration	
	AREA RES, DATA, READWRITE		; RES is a random lable representing RAM
A 	DCD 0x0, 0x0
	END