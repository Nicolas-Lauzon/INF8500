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
		address = 1;  // Debug avec 1 copro
		pkt_original = new Packet(i, address);

		// Envoi du paquet vers le coprocesseur (via interconnexion) 
		pkt_out.write(pkt_original);

		unsigned int* tab[500] = { pkt_original->getPayload() };
		// Calcul du tri pour comparer avec celui du coprocesseur
		unsigned int* tableau = (pkt_original->getPayload());
		if (pkt_original->getAddress() == 2) {
			int longueur = pkt_original->getPayloadSize();
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

		else {
			int longueur = pkt_original->getPayloadSize();
			int i, inversion;
			do
			{
				inversion = 0;

				for (i = 0; i < longueur - 1; i++)
				{
					if (tableau[i] > tableau[i + 1])
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
		printf("avant read");
		// Réception du paquet envoyé par le coprocesseur via interconnexion (attente bloquante)
		pkt_copro = *pkt_in.read();

		// Comparaison du paquet envoyé et reçu
		// Et affichage d'un message pour dire si c'est le résultat attendu ou non (Id, adresse et payload)
		printf("fini");
		if (pkt_copro.getPayload() == tableau) {
			//printf("tout va bien %d%d%d", pkt_copro.getPacketId(), pkt_copro.getAddress(), pkt_copro.getPayload());
			printf("ok");
		}
		else {
			//printf("ca va mal %d%d%d", pkt_copro.getPacketId(), pkt_copro.getAddress(), pkt_copro.getPayload());
			printf("pas ok");
		}

		delete pkt_original;
		i++;
	}

	printf("Fin de la simulation");
	wait(50, SC_MS);
	sc_stop();
}
