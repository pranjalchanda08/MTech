/**
 * @file    isa.h
 * @brief   Header file containing Memory and Pipeline prototype
 * @author  Pranjal Chanda (2022HT01011)
 */

#ifndef _ISA_H_
#define _ISA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CODE_MEM_SIZE           1024
#define DATA_MEM_SIZE           256

typedef enum opcode
{
    OP_MOV_Rn_DIR   = 0x00,
    OP_MOV_DIR_Rn   = 0x01,
    OP_MOV_MRn_Rm   = 0x02,
    OP_MOV_Rn_IMM   = 0x03,
    OP_ADD_Rn_Rm    = 0x04,
    OP_SUB_Rn_Rm    = 0x05,
    OP_JZ_Rn_REL    = 0x08,
    OP_JNZ_Rn_REL   = 0x09,
}opcode_t;

typedef unsigned char uchar;

typedef struct bytecode
{
    uchar byte1;
    uchar byte2;
}bytecode_t;

typedef struct CPU_CONTEXT
{
    uchar R[8];           // CPU Reg R0...R7
    bytecode_t* PC;       // Program Counter
}CPU_CONTEXT_t;

extern bytecode_t g_code_mem[];
extern uchar g_data_mem[];

int pipeline(const bytecode_t bytecode, CPU_CONTEXT_t* g_context);

#endif