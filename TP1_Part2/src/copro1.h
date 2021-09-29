#include <systemc.h>
#include "packet.h"		// importation du type Packet

#ifndef COPRO1_H
#define COPRO1_H

SC_MODULE(copro1)
{
	/* *******************************************************************
	// MODULE PORTS 
	******************************************************************** */
	/*
	A compléter
	*/
	sc_in<Packet*> packetIn;
	sc_out<Packet*> packetOut;

	sc_out<bool> complete;
	sc_in<bool> valueReady;
	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	// Paquet local au module copro1
	Packet pkt;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	// Cette fonction reçoit un paquet de l'interconnexion, le traite, et le renvoie
	void pkt_processing(void); //THREAD

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	SC_CTOR(copro1)
	{
		// pkt_processing est un THREAD
		SC_THREAD(pkt_processing);
	}

};

#endif

