#include "copro3.h"


void copro3::pkt_processing()
{
	/* 
	A compléter
	*/
	while (true) 
	{
		//Récupération du paquet envoyé par le processeur via l'interconnexion (attente bloquante)
		
		Packet* receivedPacket = pkt_in_copro3.read();
		pkt = *receivedPacket;

		// Traitement du paquet (tri)
		unsigned int* refToPayload = (receivedPacket->getPayload());
		unsigned int* tableau = new unsigned int[receivedPacket->getPayloadSize()];
		for (int i = 0; i < receivedPacket->getPayloadSize(); i++)
		{
			tableau[i] = *(refToPayload + i);
		}

		int longueur = receivedPacket->getPayloadSize();
		int inversion;
		do
		{
			inversion = 0;

			for (int i = 0; i < longueur - 1; i++)
			{
				if (tableau[i] > tableau[i + 1])
				{
					unsigned int tempElement = tableau[i];
					tableau[i] = tableau[i + 1];
					tableau[i + 1] = tempElement;
					inversion = 1;
				}
			}
			longueur--;
		} while (inversion);


		// Renvoi du paquet traité vers le processeur via l'interconnexion
		
		receivedPacket->setPayload(tableau);
		pkt_out_copro3.write(receivedPacket);
		


	}
}
