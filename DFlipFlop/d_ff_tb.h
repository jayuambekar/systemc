#include <systemc>

SC_MODULE(d_ff_tb) 
{
	
private:
   	
    void tb_method();
    void monitor();

public:
	sc_in <bool> clk;
    sc_out <bool> din;
    sc_in <bool> dout;

	SC_CTOR(d_ff_tb):
	din("din"),
	dout("dout")
	{
		SC_THREAD(tb_method);
		//sensitive << clk.pos();

		SC_METHOD(monitor);
		sensitive << dout;
	}
};