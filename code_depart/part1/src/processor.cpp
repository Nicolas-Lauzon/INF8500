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
		/*
		A compléter
		*/

		// Réception du paquet envoyé par le coprocesseur via interconnexion (attente bloquante)
		pkt_copro = *pkt_in.read();

		// Comparaison du paquet envoyé et reçu
		// Et affichage d'un message pour dire si c'est le résultat attendu ou non (Id, adresse et payload)
		/*
		A compléter
		*/

		delete pkt_original;
		i++;
	}

	printf("Fin de la simulation");
	wait(50, SC_MS);
	sc_stop();
}
