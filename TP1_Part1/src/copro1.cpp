#include "copro1.h"

// SC_THREAD(pkt_processing)
void copro1::pkt_processing() 
{
	// Initialisation des variables locales et des sorties
	/*
	A compléter si nécessaire
	*/
	complete.write(false);
	while(true) 
	{

		//Récupération du paquet envoyé par le processeur via l'interconnexion (attente bloquante)
		wait(valueReady.posedge_event());
		complete.write(false);
		wait(1, SC_NS);
		Packet* receivedPacket = packetIn.read();
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
		packetOut.write(receivedPacket);
		complete.write(true);
	}
}
