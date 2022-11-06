#ifndef _REGS_
#define _REGS_

#include "systemc.h"

SC_MODULE(reg_bank) {

	//-- Signals --//
	sc_in<bool> CLK;			// Clock
	sc_in<bool> EN;				// Available to read/write
	sc_in<bool> OPCODE;			// write if true; read if false
	sc_in<sc_uint<4>> Rn;		// Addressing first operand
	sc_in<sc_uint<4>> Rm;		// Addressing second operand 
	sc_in<sc_uint<8>> Rn_IN; 		// Data to be written
	sc_out<sc_uint<8>> Rn_OUT; 		// Data for the first operand
	sc_out<sc_uint<8>> Rm_OUT; 		// Data for the second operand

	//-- Method --//
	void register_base_routine();	// Performs RAM's behaviour
	void print(int);

	SC_HAS_PROCESS(reg_bank);
	
	//-- Constructor --//
	reg_bank (sc_module_name _name) : sc_module {_name} {
		cout << "New component - Register base" << endl;
		SC_METHOD(register_base_routine);	
		sensitive << CLK.pos();
		// Create memory in memory
		regdata = new sc_signal<sc_uint<8>>[8];
	};

	private:
		sc_signal<sc_uint<8>> * regdata;	// Keeps the data written

};
#endif
