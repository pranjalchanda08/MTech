#include "systemc.h"
#include "processor.hpp"

void processor::pipeline()
{
    char a,b,c,d;

    a=sig_BYTECODE[0].read();
    b=sig_BYTECODE[1].read();
    c=sig_BYTECODE[2].read();
    d=sig_BYTECODE[3].read();
        cout << a << b << c << d << endl;

    if (sig_RST == 0)
    {
        sig_PC.write(0);
    }
    else
    {
        // switch ()
        // {
        // case 0:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
    }
}
