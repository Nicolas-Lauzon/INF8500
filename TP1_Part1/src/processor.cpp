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
		address = 1 + (rand() % (3));
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
		for (int z = 0; z < pkt_original->getPayloadSize(); z++) {
			printf("valeur processeur : %d\n", tableau[z]);
		}
		// Réception du paquet envoyé par le coprocesseur via interconnexion (attente bloquante)
		pkt_copro = *pkt_in.read();

		// Comparaison du paquet envoyé et reçu
		// Et affichage d'un message pour dire si c'est le résultat attendu ou non (Id, adresse et payload)
		printf("fini");
		for (int i = 0; i < 6; i++) {
			printf("paquet recu du copro1 = %d\n", *(pkt_copro.getPayload() + i));
		}
		printf("valeur de i = %d\n", i);
		/*if (pkt_copro.getPayload() == tableau) {
			//printf("tout va bien %d%d%d", pkt_copro.getPacketId(), pkt_copro.getAddress(), pkt_copro.getPayload());
			printf("ok");
		}
		else {
			//printf("ca va mal %d%d%d", pkt_copro.getPacketId(), pkt_copro.getAddress(), pkt_copro.getPayload());
			printf("pas ok");
		}*/
		//printf("%p", pkt_original->getPayload());
		delete pkt_original;
		i++;
	}

	printf("Fin de la simulation");
	wait(50, SC_MS);
	sc_stop();
}
