#include <systemc.h>
#include "packet.h"		// importation du type Packet

#ifndef COPRO3_H
#define COPRO3_H

SC_MODULE(copro3)
{
	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */
	
	sc_fifo_in<Packet*> pkt_in_copro3;
	sc_fifo_out<Packet*> pkt_out_copro3;

	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	// Paquet local au module copro3
	Packet pkt;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	SC_HAS_PROCESS(copro3);
	// Cette fonction reçoit un paquet de l'interconnexion, le traite, et le renvoie
	void pkt_processing(void);

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	copro3(sc_module_name _name) : sc_module(_name) {
		SC_THREAD(pkt_processing);
	}
	

};

#endif

