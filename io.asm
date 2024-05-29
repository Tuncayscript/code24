
; takes in the pointer in EBX to a zero-terminated string
print_string:
    mov al, [ebx]
    cmp al, 0
    je print_string_exit
    push ebx
    mov bl, al
    call print_char
    pop ebx
    add ebx, 1
    jmp print_string

    print_string_exit:
        ret


; this reads in a line from stdin
; and puts it into a buffer (ret eax)

; the string is zero-terminated and *must* be freed when not needed
read_line:
    ; max line length: 512 characters
    mov ebx, 520 ; pad our 512 limit a bit
    call malloc
    mov ebx, [eax] ; segfault if malloc returns NULL
    mov ebx, 0 ; character counter
    read_line_loop1:
    ; ok time to read a single character
    push eax ; push these to preserve them
    push ebx 
      push eax   ; use ESP as a place to store the character temporarilly
      mov eax, 0x3 ; sys_read
      mov ebx, 0   ; stdin
      mov ecx, esp ; the buffer
      mov edx, 1   ; 1 byte
      int 0x80
    pop ecx  ; CL  the character just read in
    pop ebx  ; EBX the character counter
    pop eax  ; EAX the char pointer
    ; check to see if it's a newline
    ; if it is, just return EAX
    cmp cl, 0x0A ; newline char
    je read_line_return
    cmp cl, 0x00 ; EOL
    je read_line_return
    ; else, lets stick it on the buffer
    mov [eax + ebx], cl
    add ebx, 1
    ; ok lets check our buffer size
    cmp ebx, 512; jump if greater 
    jg read_line_buffer_overflow
    ; ok, looks... good?
    ; jump back to the begining
    jmp read_line_loop1

    read_line_return:
      ret
    read_line_buffer_overflow:
      mov ebx, 2
      jmp exit


print_newline:
   mov ebx, 10
   jmp print_char

; prints the character in the bl register
print_char:
   ; mov bl, bl ; bl should already be set
   mov bh, 0x0a
   push ebx
   mov eax, 0x4 ; sys_write
   mov ebx, 1 ; stdout
   mov edx, 1 ; # of bytes
   mov ecx, esp ; the buffer location - on the stack
   int 0x80 ; sys_write
   pop ebx
   ret

