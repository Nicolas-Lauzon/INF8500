#include "interconnexion.h"
#include "globals.h"

void interconnexion::pkt_dispatch(void) 
{
	
	int addr = 0;
	valueSent1.write(false);
	while (true)
	{
		//Récupération du paquet (attente bloquante)
		/* 
		A compléter 
		*/
		Packet* receivedPacket = new Packet(*pkt_in.read());
		//addr = receivedPacket->getAddress();
		pkt = *receivedPacket;
		//pkt = *pkt_in.read();
		addr = pkt.getAddress();

		//Lecture de l'adresse du paquet
		/* 
		A compléter 
		*/

		//Utiliser la bonne méthode d'envoi selon l'adresse
		switch (addr)
		{
		case PACKET_COPRO1:
			pkt_copro1();
			break;
		case PACKET_COPRO2:
			pkt_copro2();
			break;
		case PACKET_COPRO3:
			pkt_copro3();
			break;
		}

		//Envoi du paquet reçu du coprocesseur vers le processeur
		/*
		A compléter
		*/
		receivedPacket->setPayload(pkt.getPayload());
		pkt_out.write(receivedPacket);
	}
}

void interconnexion::pkt_copro1(void) 
{
	// Envoi paquet vers copro 1
	/* 
	A compléter 
	*/
	pkt_out_copro1.write(&pkt);  //crash à ce moment-ci. Probablement problème de pointeur
	valueSent1.write(true);
	wait(1, SC_NS);
	valueSent1.write(false);
	wait(readReady1.posedge_event());

	// Réception paquet envoyé par copro 1 (attente bloquante)
	/*
	A compléter
	*/
	//while (!pkt_in_copro1.event()) {}
	//wait(receiveStart1.posedge_event());
	pkt = *pkt_in_copro1.read();

}

void interconnexion::pkt_copro2(void) 
{
	/* 
	A compléter 
	*/
}


void interconnexion::pkt_copro3(void) 
{
	/* 
	A compléter 
	*/
}
