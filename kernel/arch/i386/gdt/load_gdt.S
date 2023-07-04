.intel_syntax noprefix

gdtr: .word 0 # For limit storage
     .long 0 # For base storage

.global setGdt
setGdt:
   MOV   AX, [esp + 4]
   MOV   [gdtr], AX
   MOV   EAX, [ESP + 8]
   MOV   [gdtr + 2], EAX
   LGDT  [gdtr]
   jmp reload_segments
   RET