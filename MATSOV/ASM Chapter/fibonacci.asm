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
    FIBO: ; parameters: CX - the n'th number,
          ; return value: EAX
        PUSH EBP
        MOV EBP, ESP
	  PUSH EBX         ; save EBX value
        CMP ECX, 0       ; return 0 if the parameter is 0 or below
        JLE WRONGPARAM
        CMP ECX, 2
        JA CALCPREV1     ; if CX is 2 or less - it is 1 or 2 (return 1)
	  MOV EAX, 1
        JMP ENDFIBO
        CALCPREV1:
            MOV EBX, 2
        CALCPREV2:
		DEC ECX
		PUSH EAX
		PUSH ECX
		MOV EAX, 0
            CALL FIBO
		POP ECX
		POP EDX      ; EAX before FIBO call
		ADD EAX, EDX
		DEC EBX
		JNZ CALCPREV2
            JMP ENDFIBO
        WRONGPARAM:
            MOV EAX, 0   ; is not a possible option for a fibonacci number
        ENDFIBO:
		POP EBX
            MOV ESP, EBP
            POP EBP
        	RET
end_prog:
    PUSH EAX
    call ExitProcess
end _start
