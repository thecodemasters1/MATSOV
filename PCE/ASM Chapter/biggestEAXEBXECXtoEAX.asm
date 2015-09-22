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
    CMP EBX, ECX
    JC XCHGBC 		; if ECX is bigger than EBX, XCHG them
    CHECKAB:
        CMP EAX, EBX
        JC XCHGBA 	; if EBX is bigger than EAX, XCHG them
        JMP end_prog
    XCHGAB:
        XCHG EAX, EBX
        JMP CHECKAB
    XCHGBC:
        XCHG EBX, ECX
        JMP end_prog
end_prog:
    PUSH EAX
    call ExitProcess
end _start
