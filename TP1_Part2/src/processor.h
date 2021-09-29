
#include <systemc.h>
#include "packet.h"		// importation du type Packet

#ifndef PROCESSOR_H
#define PROCESSOR_H

SC_MODULE(processor)
{
	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */
	sc_fifo_out<Packet*> pkt_out;
	sc_fifo_in<Packet*> pkt_in;

	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	Packet *pkt_original;
	Packet pkt_copro;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	SC_HAS_PROCESS(processor);
	// Méthode qui gère les paquets (THREAD)
	void packet_handling(void);

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	processor(sc_module_name name_) : sc_module(name_)
	{
		SC_THREAD(packet_handling);
	}

	/*SC_CTOR(processor)
	{
		// generate est un thread
		SC_THREAD(packet_handling);
	}*/
};

#endif
