; Assignment 1 a) Code 2
; Controller: LPC2378
; Architecture: ARMv4
; Assembly Language Programs (ALP) for an ARMv4T processor to implement the
; following IF-ELSE statement are given below:
; if ( a<b)
; {
;   x=5
;   y=c+d
; }
; else
;   y=c-d

    AREA RESET, CODE, READONLY
    ENTRY
START
    ADR R4,SRC          ; Get Address of SRC[0] in R4
    LDR R5,=DST         ; Load Address of DST[0] in R5
    BL SUB1             ; Branch to SUB1
STOP 
		B STOP              ; Infinite loop
SUB1 
	LDR R0,[R4],#4		; Load SRC[0]; Increment SRC address by 4 => SRC[1]
    LDR R1,[R4],#4		; Load SRC[1]; Increment SRC address by 4 => SRC[2]
    CMP R0,R1			; R0-R1, changes CPSR[N] value    
	LDR R0,[R4],#4		; Load SRC[2]; Increment SRC address by 4 => SRC[3]
    LDR R1,[R4]			; Load SRC[3]
    MOVLT R2,#5			; R2=5 if CPSR[N] = 1; Else pass
    STRLT R2,[R5]		; Store R2 ==> R5 address CPSR[N] = 1; Else pass
    ADDLT R0, R0, R1    ; ADD if CPSR[N] = 1; Else pass
    SUBGE R0, R0, R1	; SUB if >=
    STR R0,[R5,#4]		; Store results
AFT 
    MOV PC,LR			; Return
SRC DCD 0x40, 0x40, 0x30, 0x10
    AREA RESULT, DATA, READWRITE
DST DCD 0, 0
    END