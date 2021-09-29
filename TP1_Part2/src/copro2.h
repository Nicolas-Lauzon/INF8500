#include <systemc.h>
#include "packet.h"		// importation du type Packet

#ifndef COPRO2_H
#define COPRO2_H

SC_MODULE(copro2)
{
	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */

	/* 
	A compléter
	*/
	sc_in<bool> packetIn;
	sc_out<bool> packetOut;

	sc_in<Packet*> packetIn_buf;
	sc_out<Packet*> packetOut_buf;

	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	// Paquet local au module copro2
	Packet pkt;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	// Cette fonction reçoit un paquet de l'interconnexion, le traite, et le renvoie
	void pkt_processing(void); //THREAD

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	SC_CTOR(copro2)
	{
		/* 
		A compléter
		*/
		SC_THREAD(pkt_processing);
	}

};

#endif

