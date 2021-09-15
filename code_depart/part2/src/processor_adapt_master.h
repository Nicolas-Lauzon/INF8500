#ifndef PROCESSOR_ADAPT_H
#define PROCESSOR_ADAPT_H

#include <systemc.h>
// importation du type Packet
#include "packet.h"	
#include "simple_bus_types.h"
#include "simple_bus_blocking_if.h"

SC_MODULE(processor_adapt_master)
{
	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */
	sc_in_clk clock;
	
	/*
	A compléter
	*/

	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	// Paquet local au module
	Packet pkt;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	
	SC_HAS_PROCESS(processor_adapt_master);
	// Ce thread reçoit un paquet du processeur, l'envoie sur le simple bus, puis réceptionne le paquet venant du coprocesseur
	void pkt_dispatch(void); //THREAD

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	processor_adapt_master(sc_module_name name_
		, unsigned int unique_priority
		, unsigned int address
		, bool lock
		, int timeout)
		: sc_module(name_)
		, m_unique_priority(unique_priority)
		, m_address(address)
		, m_lock(lock)
		, m_timeout(timeout)
	{
		// process declaration
		SC_THREAD(pkt_dispatch);
		sensitive << clock.pos();
	}
private:
	unsigned int m_unique_priority;
	unsigned int m_address;
	bool m_lock;
	int m_timeout;
};

#endif

