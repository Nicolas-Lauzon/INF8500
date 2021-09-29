#include "processor_adapt_master.h"
#include "globals.h"

void processor_adapt_master::pkt_dispatch(void)
{

	unsigned int addr;
	simple_bus_status status;

	/*
	A compl�ter si n�cessaire
	*/
	int addr = 0;
	const unsigned int myLength = 0x20;

	while (true)
	{
		wait();
		//R�cup�ration du paquet
		/*
		A compl�ter
		*/
		Packet* receivedPacket = new Packet(*packetFromProc.read());
		pkt = *receivedPacket;


		//Lecture de l'adresse du paquet
		/*
		A compl�ter
		*/
		addr = pkt.getAddress();

		int* temp = (int*)pkt.getPayload();

		// Envoi payload sur SimpleBus 
		/*
		A compl�ter
		*/
		myBus->burst_write(m_unique_priority, temp, addr, myLength, m_lock);


		//R�ception payload du coprocesseur
		/*
		A compl�ter
		*/


		//Envoi du paquet au processeur
		/*
		A compl�ter
		*/

	}
}
