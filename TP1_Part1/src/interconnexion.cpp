#include "interconnexion.h"
#include "globals.h"

void interconnexion::pkt_dispatch(void) 
{
	
	int addr = 0;
	valueSent1.write(false);
	valueSent1.write(false);
	while (true)
	{
		//Récupération du paquet (attente bloquante)
		/* 
		A compléter 
		*/
		Packet* receivedPacket = new Packet(*pkt_in.read());
		pkt = *receivedPacket;

		//Lecture de l'adresse du paquet
		/* 
		A compléter 
		*/
		addr = pkt.getAddress();

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
	pkt_out_copro1.write(&pkt); 
	valueSent1.write(true);
	
	// Réception paquet envoyé par copro 1 (attente bloquante)
	/*
	A compléter
	*/
	wait(readReady1.posedge_event());
	valueSent1.write(false);
	pkt = *pkt_in_copro1.read();

}

void interconnexion::pkt_copro2(void) 
{
	/* 
	A compléter 
	*/
	pkt_out_copro2_buf.write(&pkt);
	pkt_out_copro2.write(true);

	wait(pkt_in_copro2.posedge_event());
	pkt_out_copro2.write(false);
	pkt = *pkt_in_copro2_buf.read();
}


void interconnexion::pkt_copro3(void) 
{
	/* 
	A compléter 
	*/
	pkt_out_copro3.write(&pkt);
	pkt = *pkt_in_copro3.read();
}
