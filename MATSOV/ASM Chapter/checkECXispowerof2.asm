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
    MOV EAX, 0FFFFFFFFh
    MOV EBX, ECX 	; Move the number to EBX
    MOV ECX, 32 	; Use ECX as a loop counter
    MOV EDX, 0 		; Use EDX as a counter
    CNTBITS:
        TEST EBX, 1
        JNZ INCEDX
    SHREBX:
        SHR EBX, 1
        LOOP CNTBITS
        JMP CHCKCNT
    INCEDX:
        INC EDX
        JMP SHREBX
    CHCKCNT:
        CMP EDX, 1
        JNZ end_prog
        INC EAX 	; if the one's number is exactly 1, increase EAX to 0
end_prog:
    PUSH EAX
    call ExitProcess
end _start
