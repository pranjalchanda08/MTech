; Assignment 1 a) Code 1
; Controller: LPC2378
; Architecture: ARMv4T
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
    ADR R4,SRC			; Get Address of SRC[0] in R4
    LDR R5,=DST			; Load Address of DST[0] in R5
    BL SUB1				; Branch to SUB1
STOP
	B STOP				; Infinite loop
SUB1
	LDR R0,[R4],#4		; Load SRC[0]; Increment SRC address by 4 => SRC[1]
    LDR R1,[R4],#4		; Load SRC[1]; Increment SRC address by 4 => SRC[2]
    CMP R0,R1			; R0-R1, changes CPSR[N] value
    BGE FB1				; Branch if CPSR[N] = 1 due to CMP 
    LDR R0,[R4],#4		; if PC is here means CPSR[N] = 0 ; Load SRC[2]; Increment SRC address by 4 => SRC[3]
    LDR R1,[R4],#4		; Load SRC[3]; Increment SRC address by 4 => SRC[4] (Garbage)
    ADD R0,R0,R1		; SRC[2] + SRC[3]; Save to R0  
    MOV R2,#5			; Copy 5 (Immidiate) to R2
    STR R2,[R5],#4		; Store 5 at space pointed by R5 i.e., DST[0]; Increment DST address by 4 => DST[1]
    STR R0,[R5]			; Store R0 to DST[1]
    B AFT				; Branch AFT
FB1 
	LDR R0,[R4],#4		; if PC is here means CPSR[N] = 0 ; Load SRC[2]; Increment SRC address by 4 => SRC[3]
    LDR R1,[R4]			; Load SRC[3];
    SUB R0,R0,R1		; R0 = R0 - R1 => R0 = SRC[2]-SRC[3]
    STR R0,[R5,#4]		; Store result in R5 post incrementing value with 4 => at DST[1]
AFT 
	MOV PC,LR			; Copy PC with LR (Return from branch)
SRC DCD 0x20, 0x20, 0x30, 0x10
    AREA RESULT, DATA, READWRITE
DST DCD 0, 0
    END