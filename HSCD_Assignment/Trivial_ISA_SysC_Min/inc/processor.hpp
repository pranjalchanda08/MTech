#include "systemc.h"
#include "code.h"
#include "data.h"
#include <iostream>

SC_MODULE(processor)
{
    sc_in<bool> sig_CLK;
    sc_in<bool> sig_RST;
    sc_in<sc_uint<4>> sig_BYTECODE[4];
    sc_inout<sc_uint<16>> sig_PC;

    void pipeline();

    SC_CTOR(processor)
    {
        cout << "Constructor Processor";
        SC_METHOD(pipeline);
        sensitive << sig_CLK.pos();
    };
};