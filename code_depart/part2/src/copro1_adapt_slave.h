#ifndef COPRO1_ADAPT_SLAVE_H
#define COPRO1_ADAPT_SLAVE_H

#include <systemc.h>

#include "simple_bus_types.h"
#include "simple_bus_slave_if.h"
#include "packet.h"


class copro1_adapt_slave
	: public simple_bus_slave_if,
	public sc_module
{
public:

	SC_HAS_PROCESS(copro1_adapt_slave);

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
	// dispatch se réveille lorsqu'un paquet complet a éte reçu sur Simple bus
	void dispatch(void);
	// Slave Interface (Méthodes de l'interface à implémenter)
	simple_bus_status read(int *data, unsigned int address);
	simple_bus_status write(int *data, unsigned int address);
	unsigned int start_address() const;
	unsigned int end_address() const;

	bool direct_read(int *data, unsigned int address);
	bool direct_write(int *data, unsigned int address);

	// Communications entre l'adapteur et le copro 1
	void copro_interface(void);

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	copro1_adapt_slave(sc_module_name name_
		, unsigned int start_address
		, unsigned int end_address
		, unsigned int nr_wait_states)
		: sc_module(name_)
		, m_start_address(start_address)
		, m_end_address(end_address)
		, m_nr_wait_states(nr_wait_states)
		, packet_dispatched(1)
		, m_wait_count(-1)
	{
		SC_THREAD(dispatch);	// on peut utiliser une methode ou un thread avec une boucle infinie
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
	~copro1_adapt_slave();
	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
private:
	sc_event start_dispatch;
	int packet_dispatched;
	Packet packet;
	int *MEM;
	unsigned int m_start_address;
	unsigned int m_end_address;
	unsigned int m_current_packet_start_address;
	int m_wait_count;
	unsigned int m_nr_wait_states;
};

#endif