.global _main
.extern _atoi     // External reference to 'atoi'
.extern _printf   // External reference to 'printf'
.extern _puts     // External reference to 'puts'

.text
_main:

    sub sp, sp, #16
    stp x19, x20, [sp]

    // Check for arguments
    cmp x0, #3
    blt error         

    // Convert first num to int
    ldr x0, [x1, #8]
    bl _atoi
    mov x19, x0

    // Convert second num to int
    ldr x0, [x1, #16]
    bl _atoi
    mov x20, x0

    // Call the gcd function with converted arguments
    mov x0, x19
    mov x1, x20
    bl _gcd

    // printf sol.
    ldr x1, =result_format
    mov x2, x0
    mov x0, x1
    bl _printf

    // Restore registers
    ldp x19, x20, [sp]
    add sp, sp, #16

    b end_main

error:
    ldr x0, =error_message
    bl _puts

    // Restore registers
    ldp x19, x20, [sp], #16

end_main:
    ret //end program

_gcd:

    cbz x20, end_gcd

gcd_loop:
    udiv x2, x19, x20
    msub x2, x2, x20, x19
    mov x19, x20
    mov x20, x2
    cbnz x20, gcd_loop

end_gcd:
    mov x0, x19  // put result in x0
    ret

.data
result_format: .asciz "The GCD is: %d\n"
error_message: .asciz "Error: Two integer arguments are required\n"

