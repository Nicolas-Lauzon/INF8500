#include "copro2.h"


void copro2::pkt_processing()
{
	/* 
		A compléter
	*/
	packetOut.write(false);
	while (true) {
		wait(packetIn.posedge_event());
		
		packetOut.write(false);
		wait(1, SC_NS);

		Packet* receivedPacket = packetIn_buf.read();
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
				if (tableau[i] < tableau[i + 1])
				{
					unsigned int tempElement = tableau[i];
					tableau[i] = tableau[i + 1];
					tableau[i + 1] = tempElement;
					inversion = 1;
				}
			}
			longueur--;
		} while (inversion);

		/*for (int i = 0; i < 6; i++) {
			printf("valeur tableu : %d\n", tableau[i]);
		}*/

		// Renvoi du paquet traité vers le processeur via l'interconnexion
		/*
		A compléter
		*/
		printf("fin traitement copro2\n");
		receivedPacket->setPayload(tableau);
		packetOut_buf.write(receivedPacket);
		packetOut.write(true);
	}
	
}
