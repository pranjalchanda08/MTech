#include "systemc.h"
#include "processor.hpp"

#include <iostream>
#include <fstream>


int sc_main(int argn, char * argc[]){

	cout << "Loading processor..." << endl;
	
	processor p("PROC");
	
	sc_signal<bool> clock;
	sc_signal<bool> rst;
	sc_signal<sc_uint<4>> sig_BC[4];	
	sc_signal<sc_uint<16>> sig_PC;	

	p.sig_CLK(clock);
	p.sig_RST(rst);
	p.sig_BYTECODE[0](sig_BC[0]);
	p.sig_BYTECODE[1](sig_BC[1]);
	p.sig_BYTECODE[2](sig_BC[2]);
	p.sig_BYTECODE[3](sig_BC[3]);
	p.sig_PC(sig_PC);

	char imem[256];
	char dmem[256];

	char *p_PC = (imem + sig_PC.read());
	int numberCycles = 0;

	memcpy(imem, __code_bin, 256);
	memcpy(dmem, __data_bin, 256);

	rst = 1;

	while (not sc_end_of_simulation_invoked()) 
	{
		sig_BC[0] = (*p_PC & 0xF0) >> 4;
		sig_BC[1] = *p_PC & 0x0F;
		p_PC++;
		sig_BC[2] = (*p_PC & 0xF0) >> 4;
		sig_BC[3] = *p_PC & 0x0F;

		clock = 0;
		sc_start(1, SC_NS);
		clock = 1;
		sc_start(1, SC_NS);
		// break;
		numberCycles++;
	}
	
	// cout << "\nFinished after " << numberCycles - 4 << " cicles. Final state:\n" << endl;	

	// cout << "/******* REGISTERS ********/" << endl;
	// p.REGISTERS.print(10);
	// cout << "/******* MEMORY ********/" << endl;
	// p.DM.print(10);
	return 0;
}
