# OS
- System S/W _ controls execution of app. programs and acts as an interface b/w user and H/W.

# Its functions
- Convenience:
- Efficiency:
- Ability to evolve: effective development and upgrades.
- Throughput: maximize throughput(number of tasks per unit time).

# Functionalities (need some improvement)
- Resource Management:
  - Everything is resource. Maximize efficiency and decrease load on system.
- Process Management:
  - Scheduling, termination of process.
- Storage Management:
  - Keeping track of data on disk.
- Memory Management:
- Security and protection

# OS structure
1. Kernel:
   - Os core _ controls all tasks of system.

2. Shell/Interface:
   - interface _ allow users to communicate with kernel.

3. Utilities/App. program

![](2_01_OS_Services.jpg)

## Shell
- Program _ interface to user to use OS services
- Functionalities:
    - Provides interface.
    - Protection (kernel from dumb users/programs)
    - Programming constructs (Shell scripting) (vars, loops, ops, conitionals)

## Kernel

- Core _ provides essential services for all other parts.
- Main layer b/w OS and H/W
- Manages applications and H/W devices.
- Main functionalities:
    - Scheduling and management.
    - To establish communication between user level application and hardware. 
    - To decide state of incoming processes. 
    - To control disk management. 
    - To control memory management. 
    - To control task management. 

## Kernel space vs User space

- KS reserved for privilifed OS functions.
- US runs app. S/W.

![](2022-10-18_19-44-14_firefox.png)

## Microkernel and Monolithic Kernels

![](2022-10-18_micro_vs_mon.png)

Eg:
  - Micro: Mach, Minix, Hurd, QNX, AmigaOS
  - Mono: Linux, OS X, Unix.

# Types of OS

1. Uniprocessing systems:
  - execute 1 program at a time.

2. Batch:
  - Similiar programs are batched.
    - How similiar? Same Lang, same arch, etc.
    - Why though?
      - same execution req.
      - low H/W capabilities
      - only x RAM
      - only x compiler loaded in memory that day

  - Limitations:
    - No multiprogramming (uniprocessing/serial processing)
    - CPU often idle (when pro. waiting for another resource)
    - Low throughput
    - Internal fragmentation (RAM wastage _ system cant understand different memory areas of different pro.)

3. Multiprocessing:
  - execure multi. pro. at once.
  - they are scheduled (order of execution).
  - only 1 pro. can use CPU, others can use other resources till then.
  