# Pre-requisite
You will have to provide `code.bin` and `data.bin` in the `bin` folder

# Build Instructions

```sh
$ cd Trivial_ISA_C/bin/
$ cd ../;gcc -Iinc src/cpu_runner.c src/instruction_parser.c  -g -o bin/trivial_sim;cd ./bin
```

# Execute

```sh
$ ./trivial_sim
```

# Output

```sh
./trivial_sim
*********************************************
* Trivial Instruction Set Simulator using C *
*********************************************
[INFO]: Reading Code Memory
[INFO]: Reading Data Memory
[INFO]: Reseting PC=0x00
[INFO]: Staring Pipeline
[DUBUG]: [ PC: 0000 R[0-7]:{ 00h 00h 00h 00h 00h 00h 00h 00h } B1: 30h B2: 00h ] -> MOV R0, 00h
[DUBUG]: [ PC: 0002 R[0-7]:{ 00h 00h 00h 00h 00h 00h 00h 00h } B1: 31h B2: 0Ah ] -> MOV R1, 0Ah
[DUBUG]: [ PC: 0004 R[0-7]:{ 00h 0Ah 00h 00h 00h 00h 00h 00h } B1: 32h B2: 01h ] -> MOV R2, 01h
[DUBUG]: [ PC: 0006 R[0-7]:{ 00h 0Ah 01h 00h 00h 00h 00h 00h } B1: 33h B2: 00h ] -> MOV R3, 00h
[DUBUG]: [ PC: 0008 R[0-7]:{ 00h 0Ah 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 00h 0Ah 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 0Ah 0Ah 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 0Ah 09h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 0Ah 09h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 0Ah 09h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 13h 09h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 13h 08h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 13h 08h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 13h 08h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 1Bh 08h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 1Bh 07h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 1Bh 07h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 1Bh 07h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 22h 07h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 22h 06h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 22h 06h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 22h 06h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 28h 06h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 28h 05h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 28h 05h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 28h 05h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 2Dh 05h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 2Dh 04h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 2Dh 04h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 2Dh 04h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 31h 04h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 31h 03h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 31h 03h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 31h 03h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 34h 03h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 34h 02h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 34h 02h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 34h 02h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 36h 02h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 36h 01h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 36h 01h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 000A R[0-7]:{ 36h 01h 01h 00h 00h 00h 00h 00h } B1: 40h B2: 01h ] -> ADD R0, R1
[DUBUG]: [ PC: 000C R[0-7]:{ 37h 01h 01h 00h 00h 00h 00h 00h } B1: 50h B2: 12h ] -> SUB R1, R2
[DUBUG]: [ PC: 000E R[0-7]:{ 37h 00h 01h 00h 00h 00h 00h 00h } B1: 83h B2: FDh ] -> JZ  R3, FDh
[DUBUG]: [ PC: 0008 R[0-7]:{ 37h 00h 01h 00h 00h 00h 00h 00h } B1: 81h B2: 04h ] -> JZ  R1, 04h
[DUBUG]: [ PC: 0010 R[0-7]:{ 37h 00h 01h 00h 00h 00h 00h 00h } B1: 10h B2: 01h ] -> MOV M[01], R0
[DUBUG]: [ PC: 0012 R[0-7]:{ 37h 00h 01h 00h 00h 00h 00h 00h } B1: FFh B2: FFh ] -> Case EOF
[INFO]: Memory Dump Saved
```

![Binary_Compilation_Inputs]("./Screen-Shot/Binary_Compilation_Inputs.jpg")
![Binary_Compilation_Inputs]("./Screen-Shot/Simulation_Output.jpg")