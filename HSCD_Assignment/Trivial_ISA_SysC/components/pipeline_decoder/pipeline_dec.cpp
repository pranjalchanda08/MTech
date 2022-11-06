#include "systemc.h"
#include <cstdio>
#include "components/program_counter/program_counter.cpp"
#include "components/pipeline_decoder/pipeline_decoder.hpp"

SC_MODULE(pipeline_dec){
    
    sc_in_clk clk;
    
    sc_in<sc_uint<16>> IBus;
    sc_in<sc_uint<8>> DBus;

    /* LOcal Variables */
    sc_uint<16> IBus_val;

    void pipeline()
    {
        IBus_val = IBus.read();
        switch ((IBus_val & 0xF000) >> 12)
        {
        case OP_MOV_Rn_DIR:
            printf("MOV R%1u, M[%02X]\n", ((IBus_val >> 8) & 0xFF), (IBus_val & 0xFF));
            break;
        
        default:
            break;
        }
    }

    SC_CTOR(pipeline_dec)
    {

    }
};