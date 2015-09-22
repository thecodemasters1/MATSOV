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
    ROR AX, 8
    ROR EAX, 16
    ROR AX, 8
end_prog:
    PUSH EAX
    call ExitProcess
end _start