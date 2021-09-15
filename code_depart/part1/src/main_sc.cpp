#include <systemc.h>

// Définitions globales
#include "globals.h"

// Définitions des modules
#include "processor.h"
#include "copro1.h"
#include "copro2.h"
#include "copro3.h"
#include "interconnexion.h"


// Définitions des classes
#include "packet.h"

// Fonction principale
int sc_main( int argc, char* argv[] )
{
	//------------------------------------------
	// Déclaration des signaux
	//------------------------------------------

	// Connexions entre processeur et interconnexion 
	/* 
	A compléter
	*/

	// Connexions entre interconnexion et copro1 
	/* 
	A compléter
	*/

	// Connexions entre interconnexion et copro2 
	/* 
	A compléter
	*/

	// Connexions entre interconnexion et copro3 
	/* 
	A compléter
	*/

	//------------------------------------------
	// Instanciation
	//------------------------------------------

	processor i0_processor("i0_processor");
	/* 
	A compléter
	*/
	

	//------------------------------------------
	// Connexions entre les ports
	//------------------------------------------

	/* 
	A compléter
	*/

	//------------------------------------------
	// Démarrer la simulation
	//------------------------------------------
      
	sc_start(100, SC_SEC);

	return 0;
}
