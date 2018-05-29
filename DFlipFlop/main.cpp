#include <systemc.h>
#include <d_ff.h>
#include <d_ff_tb.h>

using namespace sc_core;

int sc_main(int argc, char* argv[]) 
{
    sc_clock clk("clk", 10, SC_NS,0.5);

    d_ff d_ff("d_ff");
    d_ff_tb d_ff_tb("d_ff_tb");
    
    sc_signal<bool> din;
    sc_signal<bool> dout;

    d_ff.din(din);
    d_ff_tb.din(din);

    d_ff.dout(dout);
    d_ff_tb.dout(dout);
    
    d_ff.clk(clk);
    d_ff_tb.clk(clk);

    sc_trace_file *fp;                    
    fp = sc_create_vcd_trace_file("wave");
    fp->set_time_unit(100, SC_PS);        
    sc_trace(fp,clk,"clk");               
    sc_trace(fp,din,"din");
    sc_trace(fp,dout,"dout");
    
    sc_start();

    sc_close_vcd_trace_file(fp);
    

    sc_start();

return (0);
}


/*int sc_main(int argc, char* argv[])
{
    sc_signal<bool> din;
    sc_signal<bool> dout;
    sc_clock clk("clk",10,SC_NS,0.5);

    d_ff dff1("dff");

    dff1.din(din);
    dff1.dout(dout);
    dff1.clk(clk);

    // WAVE
    sc_trace_file *fp;                    
    fp=sc_create_vcd_trace_file("wave");
    fp->set_time_unit(100, SC_PS);        
    sc_trace(fp,clk,"clk");               
    sc_trace(fp,din,"din");
    sc_trace(fp,dout,"dout");

    //Inicialization
    din=0;

    //START
    sc_start(31, SC_NS);               
    din=1;
    cout << "Din=1" << endl;
    cout << "Tempo: " << sc_time_stamp() << endl;

    sc_start(31, SC_NS);
    din=0;
    cout << "Din=0" << endl;
    cout << "Tempo: " << sc_time_stamp() << endl;

    sc_start(31, SC_NS);

    sc_close_vcd_trace_file(fp);        // fecho(fp)

    char myLine[100];
    cin.getline(myLine, 100);*/

 