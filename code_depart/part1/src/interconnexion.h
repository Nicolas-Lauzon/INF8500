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
	/* 
	A compléter 
	*/

	//////// Interface avec le coprocesseur 1 ////////
	// Sortie du paquet à transmettre au coprocesseur 1
	/* 
	A compléter 
	*/	

	//////// Interface avec le corocesseur 2 ////////
	// Sortie du paquet à transmettre au coprocesseur 2
	/* 
	A compléter 
	*/

	//////// Interface avec le coprocesseur 3 ////////
	// Sortie du paquet à transmettre au coprocesseur 3
	/* 
	A compléter 
	*/

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
