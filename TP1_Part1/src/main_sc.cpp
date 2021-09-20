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
	sc_fifo<Packet*> processorIn(1000);
	sc_fifo<Packet*> processorOut(1000);


	// Connexions entre interconnexion et copro1 
	/* 
	A compléter
	*/
	sc_signal<Packet*> copro1In;
	sc_signal<Packet*> copro1Out;

	// Connexions entre interconnexion et copro2 
	/* 
	A compléter
	*/
	sc_signal<Packet*> copro2InSignal;
	sc_buffer<Packet*> copro2InBuffer;

	sc_signal<Packet*> copro2OutSignal;
	sc_buffer<Packet*> copro2OutBuffer;

	// Connexions entre interconnexion et copro3 
	/* 
	A compléter
	*/

	sc_fifo<Packet*> copro3In(333);
	sc_fifo<Packet*> copro3Out(333);

	//------------------------------------------
	// Instanciation
	//------------------------------------------

	processor i0_processor("i0_processor");
	/* 
	A compléter
	*/
	copro1 i_copro1("i_copro1");
	copro2 i_copro2("i_copro2");
	copro3 i_copro3("i_copro3");
	interconnexion i_interconnexion("i_interconnexion");

	//------------------------------------------
	// Connexions entre les ports
	//------------------------------------------

	/* 
	A compléter
	*/
	/*i0_processor.pkt_out(processorOut);
	i0_processor.pkt_in(processorIn);


	i_interconnexion.pkt_in(processorOut);
	i_interconnexion.pkt_out(processorIn);
	

	i_interconnexion.pkt_in_copro1(copro1Out);
	i_interconnexion.pkt_out_copro1(copro1In);

	i_interconnexion.pkt_in_copro2(copro2OutSignal);
	i_interconnexion.pkt_out_copro2(copro2InSignal);

	i_interconnexion.pkt_in_copro2_buf(copro2OutBuffer);
	i_interconnexion.pkt_out_copro2_buf(copro2InBuffer);

	i_interconnexion.pkt_in_copro3(copro3Out);
	i_interconnexion.pkt_out_copro3(copro3In);


	i_copro1.packetIn(copro1In);
	i_copro1.packetOut(copro1Out);
	

	i_copro2.packetIn(copro2InSignal);
	i_copro2.packetIn_buf(copro2InBuffer);
	i_copro2.packetOut(copro2OutSignal);
	i_copro2.packetOut_buf(copro2OutBuffer);

	i_copro3.pkt_in_copro3(copro3In);
	i_copro3.pkt_out_copro3(copro3Out);
	*/
	i0_processor(processorOut, processorIn);
	i_interconnexion(processorOut, processorIn, copro1Out, copro1In, copro2OutSignal, copro2InSignal, copro2OutBuffer, copro2InBuffer,
		copro3Out, copro3In);
	i_copro1(copro1In, copro1Out);
	i_copro2(copro2InSignal, copro2OutSignal, copro2InBuffer, copro2OutBuffer);
	i_copro3(copro3In, copro3Out);

	//------------------------------------------
	// Démarrer la simulation
	//------------------------------------------
      
	sc_start(100, SC_SEC);

	return 0;
}
