[BITS 32]

section .asm
global print:function
global shearos_getkey:function
global shearos_malloc:function
global shearos_free:function
global shearos_putchar:function

print:
    push ebp
    mov ebp, esp

    push dword[ebp+8]
    mov eax, 1
    int 0x80
    add esp, 4
    pop ebp
    ret


shearos_getkey:
    push ebp
    mov ebp, esp;
    mov eax, 2
    int 0x80
    pop ebp
    ret

shearos_putchar:
    push ebp
    mov ebp, esp
    mov eax, 3
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

shearos_malloc:
    push ebp
    mov ebp, esp
    mov eax, 4
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret

shearos_free:
    push ebp
    mov ebp, esp
    mov eax ,5
    push dword[ebp+8]
    int 0x80
    add esp, 4
    pop ebp
    ret