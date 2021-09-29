#include "processor_adapt_master.h"
#include "globals.h"

void processor_adapt_master::pkt_dispatch(void)
{

	unsigned int addr;
	simple_bus_status status;

	/*
	A compléter si nécessaire
	*/
	int addr = 0;
	const unsigned int myLength = 0x20;

	while (true)
	{
		wait();
		//Récupération du paquet
		/*
		A compléter
		*/
		Packet* receivedPacket = new Packet(*packetFromProc.read());
		pkt = *receivedPacket;


		//Lecture de l'adresse du paquet
		/*
		A compléter
		*/
		addr = pkt.getAddress();

		int* temp = (int*)pkt.getPayload();

		// Envoi payload sur SimpleBus 
		/*
		A compléter
		*/
		myBus->burst_write(m_unique_priority, temp, addr, myLength, m_lock);


		//Réception payload du coprocesseur
		/*
		A compléter
		*/


		//Envoi du paquet au processeur
		/*
		A compléter
		*/

	}
}
