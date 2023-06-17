#!/bin/bash
make clean
make
./parser < 0.c
#check pointer
riscv32-unknown-elf-gcc -o sample_prog main.c codegen.S
spike pk sample_prog
./parser < 1.c
riscv32-unknown-elf-gcc -o sample_prog main.c codegen.S
spike pk sample_prog
#check jump
make test
riscv32-unknown-elf-gcc -o sample_prog main.c codegen.S
spike pk sample_prog