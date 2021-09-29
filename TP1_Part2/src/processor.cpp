#include <systemc.h>
#include "processor.h"


// SC_THREAD(packet_handling)
void processor::packet_handling(void)
{  
	int i = 0;
	unsigned int address = 0; 

	while (i < 8)
	{
		// Générer un nouveau paquet et l'envoyer à un coprocesseur
		// Partie 1: générer un nombre aléatoire entre 1 et 3 ("adresse" du copro).
		// A modifier pour partie 2: générer l'adresse dans la bonne plage (voir énoncé)
		//address = 1 + (rand() % (3));
		address = 4 * (rand() % (19));
		//address = 1;  // Debug avec 1 copro
		pkt_original = new Packet(i, address);

		// Envoi du paquet vers le coprocesseur (via interconnexion) 
		pkt_out.write(pkt_original);

		// Calcul du tri pour comparer avec celui du coprocesseur
		unsigned int* refToPayload = (pkt_original->getPayload());
		unsigned int* tableau = new unsigned int[pkt_original->getPayloadSize()];

		for (int y = 0; y < pkt_original->getPayloadSize(); y++)
		{
			tableau[y] = *(refToPayload + y);
		}


		if (pkt_original->getAddress() == 2) {
			int longueur = pkt_original->getPayloadSize();
			int inversion;
			do
			{
				inversion = 0;

				for (int z = 0; z < longueur - 1; z++)
				{
					if (tableau[z] < tableau[z + 1])
					{
						unsigned int tempElement = tableau[z];
						tableau[z] = tableau[z + 1];
						tableau[z + 1] = tempElement;
						inversion = 1;
					}
				}
				longueur--;
			} while (inversion);
		}

		else {
			int longueur = pkt_original->getPayloadSize();
			int inversion;
			do
			{
				inversion = 0;

				for (int z = 0; z < longueur - 1; z++)
				{
					if (tableau[z] > tableau[z + 1])
					{
						unsigned int tempElement = tableau[z];
						tableau[z] = tableau[z + 1];
						tableau[z + 1] = tempElement;
						inversion = 1;
					}
				}
				longueur--;
			} while (inversion);
		}
		// Réception du paquet envoyé par le coprocesseur via interconnexion (attente bloquante)
		pkt_copro = *pkt_in.read();

		// Comparaison du paquet envoyé et reçu
		// Et affichage d'un message pour dire si c'est le résultat attendu ou non (Id, adresse et payload)

		unsigned int* receivedPayload = pkt_copro.getPayload();
		bool badPacket = false;
		if (pkt_copro.getPacketId() == pkt_original->getPacketId() && pkt_copro.getAddress() == pkt_original->getAddress()) {
			for (int i = 0; i < 6; i++) {
				if (tableau[i] != *(receivedPayload + i)) {
					badPacket = true;
					break;
				}
			}
			if (badPacket) {
				printf("Le payload du paquet reçu n'est pas bon\n Paquet Original : id = %d   adresse = %d   Payload = ", pkt_original->getPacketId(), pkt_original->getAddress());
				for (int i = 0; i < 6; i++) {
					printf("%d ;", tableau[i]);
				}
				printf("\n paquet reçu : id = %d   adresse = %d   Payload = ", pkt_copro.getPacketId(), pkt_copro.getAddress());
				for (int i = 0; i < 6; i++) {
					printf("%d ;", *(receivedPayload + i));
				}
			}
			else {
				printf("Le Paquet est bon : id = %d   adresse = %d   Payload = ", pkt_copro.getPacketId(), pkt_copro.getAddress());
				for (int i = 0; i < 6; i++) {
					printf("%d ;", *(receivedPayload + i));
				}
				printf("\n");
			}
		}
		else {
			printf("Le paquet reçu n'est pas bon\n Paquet Original : id = %d   adresse = %d   Payload = ",pkt_original->getPacketId(), pkt_original->getAddress() );
			for (int i = 0; i < 6; i++) {
				printf("%d ;", tableau[i]);
			}
			printf("\n paquet reçu : id = %d   adresse = %d   Payload = ", pkt_copro.getPacketId(), pkt_copro.getAddress());
			for (int i = 0; i < 6; i++) {
				printf("%d ;", *(receivedPayload+i));
			}
			printf("\n");
		}

		delete pkt_original;
		i++;
	}

	printf("Fin de la simulation");
	wait(50, SC_MS);
	sc_stop();
}
