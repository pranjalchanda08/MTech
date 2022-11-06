#ifndef _ULA_
#define _ULA_

#include "systemc.h"

SC_MODULE(ula) {

	//-- Sinais --//
	sc_out<sc_uint<8>> ula_out;
	sc_in<sc_uint<8>> in1;
	sc_in<sc_uint<8>> in2;
	sc_in<sc_uint<4>> opcode;
	sc_in<bool> reset;

	//-- Methods --//
	void compute();

	SC_HAS_PROCESS(ula);
	
	//-- Constructor --//
	ula (sc_module_name _name) : sc_module {_name} {
		SC_METHOD(compute);	
		sensitive << in1 << in2 << opcode << reset;
	};

};


void ula::compute(){
	int ar = in1.read();
	int br = in2.read();
	int op = opcode.read();
	
	if (reset.read() == 1) {
		ula_out.write(0);
	}	

	switch(op){
		case 4:
			ula_out.write(ar + br);
			break;
		case 5:
			ula_out.write(ar - br);
			break;
		default:
			ula_out.write(0);
			break;
	}
}

#endif
