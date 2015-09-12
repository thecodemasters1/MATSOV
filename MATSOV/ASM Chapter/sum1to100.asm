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
    MOV ECX, 100
    MOV EAX, 0
    COUNT:
        ADD EAX, ECX
        LOOP COUNT
end_prog:
    PUSH EAX
    call ExitProcess
end _start