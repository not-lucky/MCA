# Unit 2

## Register Transfer & Micro-operations

### Organization vs arch

- org: concerned with how h/w component operate and hwo connected together to form comp. sys.
- arch: concerned with structure and behavior of comp., processors, memories, instruction set, etc.

### Functions of comp

- Data Processing
- Data Storage
- Data Movement
- Control

### Structure of comp

- CPU
- Main mem
- I/O
- sys. interconnection (communication b/w ALU, registers, control unit)

### Register Transfer Language

symbolic notation used to descibe micro-op transfers among registers.

### Micro-operation

- ele. operation on info. stored in registers.
- R1 <- R2 + R3
- all are registers, apply ADD micro-op, and store in R1.

### Micro instruction, micro program and micro operation

- to represent micro-op, we need micro instruc.
- set of micro ins. = micro program
- def of micro op.

### Memory Transfer

- transfer of info
- Data Reg: holds data during mem trans.
- Address Reg: hold add. of mem location from where trans takes place.
- M[AR]: specifies mem word selected by DR (M is the memory word).
- Mem Read: Basically translate following into english.
  - Ex: READ: DR <- M[AR]
- Mem Write: WRITE: M[AR] <- R1

IMP: 4096x16: M (no. of mem word) is 4096 and 16 is word length

## Common Bus System
