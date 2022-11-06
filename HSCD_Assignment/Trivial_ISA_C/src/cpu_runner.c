/**
 * @file    cpu_runner.c
 * @brief   This file contains the algo related to CPU and Memory initialisation and Fetch the Byte-code
 * @author  Pranjal Chanda (2022HT01011)
 */

#include "isa.h"

/* CPU RAM ATTACHMENT */
CPU_CONTEXT_t g_context;
bytecode_t    g_code_mem[CODE_MEM_SIZE];
uchar         g_data_mem[DATA_MEM_SIZE];

/* Runner */
int main(void)
{
    FILE *f_ptr;
    uchar byte;
    uchar *mem_ptr;

    printf("*********************************************\n");
    printf("* Trivial Instruction Set Simulator using C *\n");
    printf("*********************************************\n");

    printf("[INFO]: Reading Code Memory\n");
    mem_ptr = (uchar *)g_code_mem;

    /* Erase Code Mem */
    memset(g_code_mem, 0xFF, CODE_MEM_SIZE);
    memset(g_data_mem, 0xFF, DATA_MEM_SIZE);

    /* Read Flash Mem */
    f_ptr = fopen("code.bin","rb");
    if(f_ptr == NULL)
    {
        perror("File Error!");
        exit(1);
    }
    byte = fgetc(f_ptr);

    /* Load The Data to Data Mem */
    while(byte != (uchar) EOF)
    {
        *mem_ptr = byte;
        byte = fgetc(f_ptr);
        mem_ptr++;
    }
    fclose(f_ptr);

    printf("[INFO]: Reading Data Memory\n");

    mem_ptr = (uchar *)g_data_mem;

    f_ptr = fopen("data.bin","rb");
    if(f_ptr == NULL)
    {
        perror("File Error!");
        exit(1);
    }
    byte = fgetc(f_ptr);

    /* Load The Code to code Mem */
    while(byte != (uchar) EOF)
    {
        *mem_ptr = byte;
        byte = fgetc(f_ptr);
        mem_ptr++;
    }
    fclose(f_ptr);

    printf("[INFO]: Reseting PC=0x00\n");
    /* Reset The Program Counter to code mem offset: 0x00 */
    g_context.PC = g_code_mem;
    printf("[INFO]: Staring Pipeline\n");

    while (1)
    {
        if (g_context.PC >= (g_code_mem + CODE_MEM_SIZE))
        {
            perror("[ERROR]: PC out of Limits Exception");
            exit(1);
        }

        /* Fetch and send to Decode */
        if(pipeline(*g_context.PC, &g_context))
        {
            /* Break if Error */
            break;
        }
    }

    /* Save Memory Dump */
    f_ptr = fopen("mem_op.bin","wb");
    fwrite(g_data_mem, sizeof(uchar), DATA_MEM_SIZE, f_ptr);
    fclose(f_ptr);
    printf("[INFO]: Memory Dump Saved\n");
}