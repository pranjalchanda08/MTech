#include "systemc.h"

/* Components */
#include "ram.h"
#include "reg_bank.h"
#include "ula.h"
#include "program_counter.cpp"

SC_MODULE(processor)
{
    sc_in<bool> sig_CLK;
    sc_out<bool> sig_RST;

    ram<sc_uint<16>,256> IM{"IM"};
    ram<sc_uint<8>,512> DM{"DM"};
    reg_bank REGISTERS{"REGISTERS"};
    program_counter PC{"PC"};
    ula ALU{"ALU"};
    
    processor(sc_module_name _name, const char * instructionsPath) : sc_module {_name} 
    {
        /* Signal Connections */

        /* Instruction Memory Control Signals */
        sc_signal<bool> sig_EN_IM;
        sc_signal<bool> sig_IM_WR;
        sc_signal<sc_uint<16>> sig_IN_IM;
        sc_signal<sc_uint<16>> sig_OUT_IM;
        sc_signal<sc_uint<16>> sig_PC_OUT;

        /* Instruction Memory Control Signals */
        sc_signal<bool> sig_DM_EN;
        sc_signal<bool> sig_DM_WR;
        sc_signal<sc_uint<8>> sig_DM_IN;
        sc_signal<sc_uint<8>> sig_DM_OUT;
        sc_signal<sc_uint<16>> sig_DM_ADDR;
        
        /* Program Counter Signals */
        sc_signal<bool> sig_PC_CNT_UP;
        sc_signal<bool> sig_PC_JMP;
        sc_signal<sc_uint<16>> sig_PC_IN;

        /* ALU Signals */
        sc_signal<sc_uint<8>> sig_ALU_IN1;
        sc_signal<sc_uint<8>> sig_ALU_IN2;

        /* REG Bank signals */
        sc_signal<sc_uint<4>> sig_OP_OUT;

        /* IM Connections */
        IM.clock(sig_CLK);
        IM.enable(sig_EN_IM);
        IM.write(sig_IM_WR);
        IM.address(sig_PC_OUT);
        IM.dataIn(sig_IN_IM);
        IM.dataOut(sig_OUT_IM);

        /* DM Connections */
        DM.clock(sig_CLK);
        DM.enable(sig_DM_EN);
        DM.write(sig_DM_WR);
        DM.address(sig_DM_ADDR);
        DM.dataIn(sig_DM_IN);
        DM.dataOut(sig_DM_OUT);

        /* Program counter */
		PC.clock(sig_CLK);
		PC.reset(sig_RST);
		PC.cnt_up(sig_PC_CNT_UP);
		PC.jmp(sig_PC_JMP);
		PC.counter_relative_in(sig_PC_IN);
		PC.counter_out(sig_PC_OUT);

        /* ALU */
        ALU.in1(sig_ALU_IN1);
        ALU.in2(sig_ALU_IN2);
        ALU.opcode(sig_OP_OUT);
        ALU.reset(sig_RST);
        
    }
};