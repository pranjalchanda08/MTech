#include "ram.h"

template<typename TData, int TSize> 
void ram<TData,TSize>::print(int n) {
	for (int i = 0; i < n; ++i) {
		cout << "[" << i << "] - " << ramdata[i] << endl;
	}	
	cout << endl;
}

template<typename TData, int TSize> 
void ram<TData,TSize>::ram_routine() {
	while (true) {
		wait();
		if (enable.read() == 1) {
			if (write.read() == 1) {
				ramdata[address.read()] = dataIn.read();
			} else {
				dataOut.write(ramdata[address.read()]);
			}
		}
	}
}