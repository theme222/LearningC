; This assembly code is for a brookshear machine.
; We are trying to make a factorial funciton which takes in n
; Input and Output is stored in 0xFF
; registers are represented as r0 - r15

multiply: ; 0x30
    ; Takes in r1 and r2
    ; Returns in r3
    LOADI r3, 0 ; Total
    ; falls through to multiply_loop

multiply_loop: ; 0x32

    JUMP r2, factorial_loop_aftermult ; Returns if r2 is equal to r0 (0)
    ADD r3, r1
    ADD r2, r11 ; Decrement r2
    JUMP r0, multiply_loop ; Otherwise run the function again

factorial: ; 0x10
    ; Takes in r14 (n)
    ; Returns in r15

    LOADI r15, 1 ; Result of the factorial (unsigned)
    ; Falls through to factorial_loop

factorial_loop: ; 0x12

    JUMP r14, _start_afterfac ; return if r14 equals r0 (0)
    ; Prepare function arguments
    MOVE r15, r1
    MOVE r14, r2
    JUMP r0, multiply ; Call multiply with r1 and r2

factorial_loop_aftermult: ; 0x20
    MOVE r3, r15 ; Save the result back to r15
    ADD r14, r11 ; Decrement r14
    JUMP r0, factorial_loop ; else run the factorial again

_start: ; 0x00
    LOADI r10, 1 ; Incrementer (signed) (unused)
    LOADI r11, -1 ; Decrementer (signed)

    ; Load arguments for factorial
    LOAD r14, 0xFF ; the n value for the factorial

    JUMP r0, factorial

_start_afterfac: ; 0x08
    STORE r15, 0xFF ; Store the result
    HALT

; Link:
; https://joeledstrom.github.io/brookshear-emu/#2A012BFF1EFFB0103FFFC000000000002F01BE0840F140E2B030000000000000403F5EEBB012000000000000000000002300B2205331522BB032000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000005
