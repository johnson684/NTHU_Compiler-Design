.global codegen
codegen:
    // BEGIN PROLOGUE
    sw s0, -4(sp) // save frame pointer
    addi sp, sp, -4
    addi s0, sp, 0 // set new frame pointer
    sw sp, -4(s0)
    sw s1, -8(s0)
    sw s2, -12(s0)
    sw s3, -16(s0)
    sw s4, -20(s0)
    sw s5, -24(s0)
    sw s6, -28(s0)
    sw s7, -32(s0)
    sw s8, -36(s0)
    sw s9, -40(s0)
    sw s10, -44(s0)
    sw s11, -48(s0)
    addi sp, s0, -48 // update stack pointer
    // END PROLOGUE
    
    li t0, 17
    sw t0, -4(sp)
    addi sp, sp, -4
    addi sp, sp, -4
    sw zero, -52(s0)
    addi sp, sp, -4
    sw zero, -56(s0)
    addi sp, sp, -4
    sw zero, -60(s0)
    addi sp, sp, -4
    sw zero, -64(s0)
    addi sp, sp, -4
    sw zero, -68(s0)
    addi sp, sp, -4
    sw zero, -72(s0)
    addi sp, sp, -4
    sw zero, -76(s0)
    addi sp, sp, -4
    sw zero, -80(s0)
    addi sp, sp, -4
    sw zero, -84(s0)
    addi sp, sp, -4
    sw zero, -88(s0)
    addi sp, sp, -4
    sw zero, -92(s0)
    addi sp, sp, -4
    sw zero, -96(s0)
    addi sp, sp, -4
    sw zero, -100(s0)
    addi sp, sp, -4
    sw zero, -104(s0)
    addi sp, sp, -4
    sw zero, -108(s0)
    addi sp, sp, -4
    sw zero, -112(s0)
    addi sp, sp, -4
    sw zero, -116(s0)
    lw t0, -52(s0)
    sw t0, -4(sp)
    addi sp, sp, -4
    li t0, 2
    sw t0, -4(sp)
    addi sp, sp, -4
    lw t0, 0(sp)
    addi sp, sp, 4
    li t1, -52
    li t3, 4
    mul t0, t0, t3
    sub t0, t1, t0
    sw t0, -4(sp)
    addi sp, sp, -4
    lw t0, -52(s0)
    sw t0, -4(sp)
    addi sp, sp, -4
    li t0, 3
    sw t0, -4(sp)
    addi sp, sp, -4
    lw t0, 0(sp)
    addi sp, sp, 4
    li t1, -52
    li t3, 4
    mul t0, t0, t3
    sub t0, t1, t0
    sw t0, -4(sp)
    addi sp, sp, -4
    lw t0, 0(sp)
    addi sp, sp, 4
    add t0, t0, s0
    lw t1, 0(t0)
    sw t1, -4(sp)
    addi sp, sp, -4
    
    // BEGIN EPIL OGUE
    lw s11, -48(s0)
    lw s10, -44(s0)
    lw s9, -40(s0)
    lw s8, -36(s0)
    lw s7, -32(s0)
    lw s6, -28(s0)
    lw s5, -24(s0)
    lw s4, -20(s0)
    lw s3, -16(s0)
    lw s2, -12(s0)
    lw s1, -8(s0)
    lw sp, -4(s0)
    addi sp, sp, 4
    lw s0, -4(sp)
    // END EPILOGUE
    
    jalr zero, 0(ra) // return
