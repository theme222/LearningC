add: ; 0x10
    ADD r15, r1 ; +x
    ADD r15, r2 ; +i
    JUMP r2, 0x30
    ADD r2, r10 ; decrement
    JUMP r0, 0x10

_start: ; 0x00
    LOAD r1, 0x50 ; x
    LOAD r2, 0x51 ; i
    LOADI r10, 0xFF ; -1
    JUMP r0, 0x10

_fin: ; 0x30
    STORE r15, 0x52
    HALT
