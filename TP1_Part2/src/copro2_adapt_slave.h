#ifndef COPRO2_ADAPT_SLAVE_H
#define COPRO2_ADAPT_SLAVE_H

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_slave_if.h"
#include "packet.h"

class copro2_adapt_slave
	: public simple_bus_slave_if,
	public sc_module
{
public:

	SC_HAS_PROCESS(copro2_adapt_slave);

	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */
	sc_in_clk clock;
	/*
	A compléter
	*/

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	// Boucle d'attente lorque l'esclave se réveille
	void wait_loop(void); 
	// thread de dispatch se réveille lorsqu'un paquet est prêt (THREAD)
	void dispatch(void);
	// Slave Interface (Méthodes de l'interface à implémenter)
	simple_bus_status read(int *data, unsigned int address);
	simple_bus_status write(int *data, unsigned int address);
	unsigned int start_address() const;
	unsigned int end_address() const;

	bool direct_read(int *data, unsigned int address);
	bool direct_write(int *data, unsigned int address);

	void pkt_send2(void);

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	copro2_adapt_slave(sc_module_name name_
		, unsigned int start_address
		, unsigned int end_address
		,unsigned int nr_wait_states)
		: sc_module(name_)
		, m_start_address(start_address)
		, m_end_address(end_address)
		, m_nr_wait_states(nr_wait_states)
		, packet_dispatched(1)
		, m_wait_count(-1)
	{
		SC_THREAD(dispatch);
		/*
		A compléter
		*/

		SC_METHOD(wait_loop);
		dont_initialize();	// wait_loop ne sera pas appelé une première fois
		/*
		A compléter
		*/

	}
	/* *******************************************************************
	// MODULE DESTRUCTOR
	******************************************************************** */
	~copro2_adapt_slave();
	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
private:
	sc_event start_dispatch;
	int packet_dispatched;
	Packet *packet;
	unsigned int *MEM;
	unsigned int m_start_address;
	unsigned int m_end_address;
	unsigned int m_current_packet_start_address;
	int m_wait_count;
	unsigned int m_nr_wait_states;
};

#endif