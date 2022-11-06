/**
 * @file    instruction_parser.c
 * @brief   This file contains the algo related to the OPCODE and Pipeline to parse it.
 * @author  Pranjal Chanda (2022HT01011)
 */
#include "isa.h"
#include "inttypes.h"

int pipeline(const bytecode_t bytecode, CPU_CONTEXT_t* context)
{
    /* Decode */
    printf("[DUBUG]: [ PC: %04X R[0-7]:{ ",(uint16_t) (((uintptr_t)context->PC - (uintptr_t)g_code_mem) & (uint16_t)0xFFFF));
    for (size_t i = 0; i < 8; i++)
    {
        printf("%02Xh ", context->R[i]);
    }
    
    printf("} B1: %02Xh B2: %02Xh ] -> ", bytecode.byte1, bytecode.byte2);
    switch ( (bytecode.byte1 >> 4) & 0x0F )
    {
        case OP_MOV_Rn_DIR:
            /* Rn = M[Direct]*/
            context->R[bytecode.byte1 & 0x0F] = g_data_mem[bytecode.byte2];
            printf("MOV R%1u, M[%02X]\n", (bytecode.byte1 & 0x0F), bytecode.byte2);
            break;
        case OP_MOV_DIR_Rn:
            /* M[Direct] = Rn */
            g_data_mem[bytecode.byte2] = context->R[bytecode.byte1 & 0x0F];
            printf("MOV M[%02X], R%u\n", bytecode.byte2, (bytecode.byte1 & 0x0F));
            break;
        case OP_MOV_MRn_Rm:
            /* M[Rn] = Rm */
            g_data_mem[ context->R[(bytecode.byte2 >> 4) & 0x0F] ] = context->R[bytecode.byte2 & 0x0F];
            printf("MOV M[R%1u], R%u\n", ((bytecode.byte2 >> 4) & 0x0F), (bytecode.byte2 & 0x0F));
            break;
        case OP_MOV_Rn_IMM:
            /* Rn = Immidiate */
            context->R[bytecode.byte1 & 0x0F] = bytecode.byte2;
            printf("MOV R%1u, %02Xh\n", (bytecode.byte1 & 0x0F), (bytecode.byte2));
            break;
        case OP_ADD_Rn_Rm:
            /* Rn = Rn + Rm */
            context->R[(bytecode.byte2 >> 4) & 0x0F] = context->R[(bytecode.byte2 >> 4) & 0x0F] + context->R[bytecode.byte2 & 0x0F];
            printf("ADD R%1u, R%u\n", ((bytecode.byte2 >> 4) & 0x0F), (bytecode.byte2 & 0x0F));
            break;
        case OP_SUB_Rn_Rm:
            /* Rn = Rn - Rm */
            context->R[(bytecode.byte2 >> 4) & 0x0F] = context->R[(bytecode.byte2 >> 4) & 0x0F] - context->R[bytecode.byte2 & 0x0F];
            printf("SUB R%1u, R%u\n", ((bytecode.byte2 >> 4) & 0x0F), (bytecode.byte2 & 0x0F));
            break;
        case OP_JZ_Rn_REL:
            /* Set PC (Jump) if Rn is Zero */
            context->PC += context->R[bytecode.byte1 & 0x0F] == 0 ? (char)bytecode.byte2 : 1;
            printf("JZ  R%1u, %02Xh\n", (bytecode.byte1 & 0x0F), (char)bytecode.byte2 & 0xFF);
            return 0;
        case OP_JNZ_Rn_REL:
            /* Set PC (Jump) if Rn is not Zero */
            context->PC += context->R[bytecode.byte1 & 0x0F] != 0 ? (char)bytecode.byte2 : 1;
            printf("JNZ R%1u, %02Xh\n", (bytecode.byte1 & 0x0F), (char)bytecode.byte2 & 0xFF);
            return 0;
        default:
            printf("Case EOF\n");
            return 1;
    }
    context->PC++;
    return 0;
}