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
    STRCMP: ; parameters: 2 strings in the stack (null terminated)
            ; return value: EAX = 1 if identical, EAX = 0xFFFFFFFF if not
        PUSH EBP
        PUSH EBX
        MOV EBP, ESP
        MOV EDX, EBP
        ADD EDX, 12 		; Set EDX to point to the start of the first string
        GETSECSTRP: 		; Scan to find the start of the second string
            INC EDX
            CMP BYTE PTR [EDX], 0
            JNE GETSECSTRP
        SAVEPOINTER:
            INC EDX
        MOV ECX, 0
        SCANSTRS:
            MOV AL, BYTE PTR [EBP + ECX]
            MOV BL, BYTE PTR [EDX + ECX]
            CMP AL, BL
            JNE NOTEQUAL
            CMP AL, 0 		; if AL is 0, BL is also
            JE EQUAL
	      INC ECX
            JMP SCANSTRS
        NOTEQUAL:
            MOV EAX, 0FFFFFFFFh
            JMP ENDSTRCMP
        EQUAL:
            MOV EAX, 1
        ENDSTRCMP:
            POP EBX
            MOV ESP, EBP
            POP EBP
        	RET
end_prog:
    PUSH EAX
    call ExitProcess
end _start
