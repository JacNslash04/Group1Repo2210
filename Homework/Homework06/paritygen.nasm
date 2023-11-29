
section .data
    byte_value db 0x6E  
    format db "The parity bit for byte 0x%02X is %d (Odd Parity)", 10, 0

section .text
    global paritygen
    extern printf

paritygen:
    mov ecx, 0    
    mov edx, 8    

    
bit_loop:
    test byte [byte_value], 1   
    jnz increment_counter       

    jmp shift_right

increment_counter:
    inc ecx

shift_right:
    shr byte [byte_value], 1   
    dec edx                   
    jnz bit_loop               

    
    test ecx, 1
    jnz odd_parity             

even_parity:
    mov eax, 0
    mov ebx, byte_value
    mov edi, format
    call printf
    jmp end_paritygen

odd_parity:
    mov eax, 0
    mov ebx, byte_value
    mov edi, format
    add edx, 1 
    call printf

end_paritygen:
    ret

 
