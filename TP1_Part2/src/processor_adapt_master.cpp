#include "processor_adapt_master.h"
#include "globals.h"

void processor_adapt_master::pkt_dispatch(void)
{

	unsigned int addr;
	simple_bus_status status;

	/*
	A compléter si nécessaire
	*/
	//unsigned int addr = 0;
	const unsigned int myLength = 0x6;
	unsigned int id;
	while (true)
	{
		wait();
		//Récupération du paquet
		/*
		A compléter
		*/
		Packet* receivedPacket = new Packet(*packetFromProc.read());
		pkt = *receivedPacket;
		
		id = pkt.getPacketId();
		//Lecture de l'adresse du paquet
		/*
		A compléter
		*/
		unsigned int addr = pkt.getAddress();

		int* temp = (int*)pkt.getPayload();

		// Envoi payload sur SimpleBus 
		/*
		A compléter
		*/
		status = myBus->burst_write(m_unique_priority, temp, addr, myLength, m_lock);
		wait();

		//Réception payload du coprocesseur
		/*
		A compléter
		*/
		status = myBus->burst_read(m_unique_priority, temp, addr, myLength, m_lock);
		


		//Envoi du paquet au processeur
		/*
		A compléter
		*/
		receivedPacket = new Packet((unsigned int*)temp);
		receivedPacket->setAddress(addr);
		receivedPacket->setPacketId(id);

		PacketToProc.write(receivedPacket);

	}
}
