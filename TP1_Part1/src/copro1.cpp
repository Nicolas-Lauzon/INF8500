#include "copro1.h"

// SC_THREAD(pkt_processing)
void copro1::pkt_processing() 
{
	// Initialisation des variables locales et des sorties
	/*
	A compléter si nécessaire
	*/
	completeSignal.write(false);
	while(true) 
	{

		//Récupération du paquet envoyé par le processeur via l'interconnexion (attente bloquante)
		/*int cmpt = 0;
		int timpe = 0;
		while (!packetIn.event()){
			if (cmpt == 100) {
				printf("waiting %d", timpe);
			}
			timpe++;
			cmpt++;
		}*/
		wait(startSignal.posedge_event());
		Packet* receivedPacket = packetIn.read();
		pkt = *receivedPacket;

		// Traitement du paquet (tri)
		unsigned int* tableau = (pkt.getPayload());
		if (pkt.getAddress() == 2) {
			int longueur = pkt.getPayloadSize();
			int i, inversion;
			do
			{
				inversion = 0;

				for (i = 0; i < longueur - 1; i++)
				{
					if (tableau[i] < tableau[i + 1])
					{
						int tempElement = tableau[i];
						tableau[i] = tableau[i + 1];
						tableau[i + 1] = tempElement;
						inversion = 1;
					}
				}
				longueur--;
			} while (inversion);
		}

		// Renvoi du paquet traité vers le processeur via l'interconnexion
		/*
		A compléter
		*/
		receivedPacket->setPayload(tableau);
		packetOut.write(receivedPacket);
		completeSignal.write(true);
		wait(1, SC_NS);
		completeSignal.write(false);
	}
}
