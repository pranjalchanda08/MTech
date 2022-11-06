#include "systemc.h"

/* Program counter
 *
 * Keeps a counter, allowing to increase by 1 and jmp
 * a value. Address the instruction memory.
 * */
SC_MODULE(program_counter){
	//-- Signal declarations --//
	sc_in_clk  clock;
	sc_in<bool> reset;
	sc_in<bool> cnt_up;
	sc_in<bool> jmp;
	sc_out<sc_uint<16>> counter_out;
	sc_in<sc_uint<16>> counter_relative_in;

	//-- Local variables --//
	sc_uint<16> count = 0;

	//-- The logic --//
	void increment() {
		if(reset.read() == 1) {
			count = 0;
			counter_out.write(count);
		} else if (cnt_up.read() == 1) {
			count = count + 2;
			counter_out.write(count);
		} else if (jmp.read() == 1) {
			count = count + counter_relative_in.read();
			counter_out.write(count);
		}
	}
	//-- Constructor --//
	SC_CTOR(program_counter) {
		cout << "New component - Program Counter" << endl;
		SC_METHOD(increment);
		sensitive << reset << clock.pos();
	}
};
