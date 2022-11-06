#include "reg_bank.h"

#include "pipeline_decoder.hpp"

void reg_bank::print(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "[" << i << "]" << "-" << regdata[i] << endl;
	}
	cout << endl;
}

void reg_bank::reg_bank_routine() {
	if (enable.read() == 1) {
		// if (write.read() == 1) {
		// 	regdata[addressDest.read()] = dataToWrite.read();
		// } else {
		// 	dataSource1.write(regdata[addressSource1.read()]);
		// 	dataSource2.write(regdata[addressSource2.read()]);
		// }
        switch (OPCODE.read())
        {
        case OP_MOV_Rn_DIR:
            regdata[Rn_IN.read()] = Rn_IN.read();
            break;
        case OP_MOV_DIR_Rn:
			
			Rn_OUT.write(regdata[Rn_IN.read()]);
			break;
        default:
            break;
        }
	}
}