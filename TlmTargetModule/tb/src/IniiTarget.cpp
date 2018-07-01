/*
#include <systemc>
#include "tlm.h"

using namespace sc_core;
using namespace std;

//INITIATOR
struct Initiator: sc_module, tlm::tlm_bw_transport_if<>
{
	tlm::tlm_initiator_socket<32> init_socket;SC_CTOR(Initiator) :
			init_socket("init_socket")
	{
		SC_THREAD(thread);
		init_socket.bind(*this);
	}
	void thread() {
		tlm::tlm_generic_payload trans;
		sc_time delay = SC_ZERO_TIME;
		init_socket->b_transport(trans, delay);
	}

	virtual tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_core::sc_time& t)
	{
		return tlm::TLM_COMPLETED;
	}

	virtual void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)
	{
	}

};

//TARGET
struct Target: sc_module, tlm::tlm_fw_transport_if<>
{
	tlm::tlm_target_socket<32> targ_socket;
	SC_CTOR(Target) :
			targ_socket("targ_socket")
	{
		targ_socket.bind(*this);
	}

	virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_core::sc_time& t)
	{
		return tlm::TLM_COMPLETED;
	}

	virtual void b_transport( tlm::tlm_generic_payload& trans, sc_time& delay )
	{

	}

	virtual bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data)
	{
		return false;
	}

	virtual unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
	{
		return 0;
	}
};

SC_MODULE(Top1)
{
	Initiator *init;
	Target *targ;

	SC_CTOR(Top1)
	{
		init = new Initiator("init");
		targ = new Target("targ");
		init->init_socket.bind(targ->targ_socket);
	}
};

struct Parent_of_initiator: sc_module
{
	tlm::tlm_initiator_socket<32> init_socket;

	Initiator* initiator;
	SC_CTOR(Parent_of_initiator) :
			init_socket("init_socket")
	{
		initiator = new Initiator("initiator");
		initiator->init_socket.bind(init_socket);
	}
};

struct Parent_of_target: sc_module
{
	tlm::tlm_target_socket<32> targ_socket;
	Target* target;SC_CTOR(Parent_of_target) :
			targ_socket("targ_socket")
	{
		target = new Target("target");
		targ_socket.bind(target->targ_socket);
	}
};

SC_MODULE(Top2)
{
	Parent_of_initiator *init;
	Parent_of_target *targ;SC_CTOR(Top2)
	{
		init = new Parent_of_initiator("init");
		targ = new Parent_of_target("targ");
		init->init_socket.bind(targ->targ_socket);
	}
};
*/
