#!/bin/bash
make clean
make
make test
riscv32-unknown-elf-gcc -o sample_prog main.c codegen.S
spike pk sample_prog