#include "interconnexion.h"
#include "globals.h"

void interconnexion::pkt_dispatch(void) 
{
	
	int addr = 0;

	while (true)
	{
		//Récupération du paquet (attente bloquante)
		/* 
		A compléter 
		*/

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

	}
}

void interconnexion::pkt_copro1(void) 
{
	// Envoi paquet vers copro 1
	/* 
	A compléter 
	*/

	// Réception paquet envoyé par copro 1 (attente bloquante)
	/*
	A compléter
	*/
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
