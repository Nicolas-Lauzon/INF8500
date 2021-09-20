#include <systemc.h>
#include "packet.h"		// importation du type Packet

#ifndef INTERCONNEXION_H
#define INTERCOONEXION_H

SC_MODULE(interconnexion)
{
	/* *******************************************************************
	// MODULE PORTS
	******************************************************************** */
	//////// Interface avec la génération de paquets ////////
	sc_fifo_in<Packet*> pkt_in;
	sc_fifo_out<Packet*> pkt_out;

	//////// Interface avec le coprocesseur 1 ////////
	// Sortie du paquet à transmettre au coprocesseur 1
	sc_in<Packet*> pkt_in_copro1;
	sc_out<Packet*> pkt_out_copro1;

	sc_in<bool> readReady1;
	sc_out<bool> valueSent1;
	//////// Interface avec le corocesseur 2 ////////
	// Sortie du paquet à transmettre au coprocesseur 2
	sc_in<bool> pkt_in_copro2;
	sc_out<bool> pkt_out_copro2;

	sc_in<Packet*> pkt_in_copro2_buf;
	sc_out<Packet*> pkt_out_copro2_buf;

	//////// Interface avec le coprocesseur 3 ////////
	// Sortie du paquet à transmettre au coprocesseur 3
	sc_fifo_in<Packet*> pkt_in_copro3;
	sc_fifo_out<Packet*> pkt_out_copro3;

	/* *******************************************************************
	// LOCAL VARIABLES
	******************************************************************** */
	// Paquet local au module interconnexion
	Packet pkt;

	/* *******************************************************************
	// MODULE METHODS
	******************************************************************** */
	// Ce fonction reçoit un paquet du processeur, le dispatche au bon coprocesseur,
	void pkt_dispatch(void); //THREAD
	void pkt_copro1(void);
	void pkt_copro2(void);
	void pkt_copro3(void);

	/* *******************************************************************
	// MODULE CONSTRUCTOR
	******************************************************************** */
	SC_CTOR(interconnexion)
	{
		// pkt_dispatch est un thread de interconnexion
		SC_THREAD(pkt_dispatch);
	}

};

#endif
