#ifndef _PIPELINE_DECODER_
#define _PIPELINE_DECODER_

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

#endif