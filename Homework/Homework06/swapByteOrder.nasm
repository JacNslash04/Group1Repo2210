section .text
    global _start

_start:
    mov eax, 12345678
    call callSwapByteOrder

    mov eax, 87654321
    call callSwapByteOrder

    mov eax, 13572468
    call callSwapByteOrder

    mov eax, 24681357
    call callSwapByteOrder

    mov eax, 50678932
    call callSwapByteOrder

    mov eax, 1

    push eax
    call swapByteOrder
    add esp, 4
    ret
