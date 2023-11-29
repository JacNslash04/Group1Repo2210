.global _GCDfinder
.align 4
_GCDfinder:
    cbz x1, end

loop:
    udiv x2, x0, x1
    msub x2, x2, x1, x0
    mov x0, x1
    mov x1, x2
    cbnz x1, loop

end:
    ret
