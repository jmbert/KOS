section .text

global load_page_dir
load_page_dir:
    push ebp ; Stackframe adjustment
    mov ebp, esp

    mov eax, [esp+8] ; Page Directory Address

    mov cr3, eax ; Load page directory into control register 3

    mov esp, ebp ; Stackframe readjustment
    pop ebp 
    ret

global enable_paging
enable_paging:
    push ebp ; Stackframe adjustment
    mov ebp, esp

    mov eax, cr0 ; Copy control register into eax for modification
    or eax, 0x80000000 ; Enable Paging bit
    mov cr0, eax ; Copy eax back to control register 0

    mov esp, ebp ; Stackframe readjustment
    pop ebp 

    pop ebx
    sub ebx, 0x100000
    add ebx, 0xC0000000
    push ebx

    ret