#include <iostream>
#include <systemc.h>

SC_MODULE (d_ff) 
{
private:
	void dff_method();
	
public:

    sc_in <bool> clk;
    sc_in <bool> din;
    sc_out <bool> dout;

    

    SC_CTOR (d_ff) 
    {
        SC_METHOD (dff_method);
            sensitive << clk.pos();
    }
};
