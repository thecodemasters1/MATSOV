.486
.model flat, stdcall
option casemap :none ;case sensitive

;;___________MASM MACROS___________
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib

;;___________CODE__________________
.code
_start:
    POW: ; parameters: EAX - base, ECX - exponent ; return value is in EDX:EAX
        PUSH EBP
        MOV EBP, ESP
        ZEROEXPON: 		; Return 1 if exponent is 0
		CMP ECX, 0
		JNE NOTZEROEXPON
		MOV EDX, 0
		MOV EAX, 1
		JMP ENDPOW
        NOTZEROEXPON: 		; Calculate return value if exponent is different than 0
		SUB ESP, 4 	; Allocate one local variable
		MOV [EBP-4], EAX
		JMP CHECKEXPON
		MULTIPLY:
			IMUL DWORD PTR [EBP-4]
		CHECKEXPON:
			LOOP MULTIPLY
        ENDPOW:
            MOV ESP, EBP
            POP EBP
        	RET
end_prog:
    PUSH EAX
    call ExitProcess
end _start
