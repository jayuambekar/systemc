
#include <Top.h>

Top::Top(sc_core::sc_module_name module_name, size_t num_slaves)
	: sc_module(module_name)
	, data_sig("data_sig")
	, addr_sig("addr_sig")
	, data_out_sig("data_out_sig", num_slaves)
{
	master = new Master("master");
	interconnect = new Interconnect("interconnect", num_slaves);
/*	target = new Target*[3];
	for(int i = 0; i < 3; i++){
		target[i] = new Target("target_" + i);
	}
*/
	master->data_out(data_sig);
	interconnect->data_in(data_sig);

	master->addr_out(addr_sig);
	interconnect->addr_in(addr_sig);

	interconnect->data_out(data_out_sig);
	for(size_t i = 0; i < num_slaves; i++){
		target[i].data_in(data_out_sig[i]);
	}

}
