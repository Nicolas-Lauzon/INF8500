
#ifndef __simple_bus_test_h
#define __simple_bus_test_h

#include <systemc.h>

#include "simple_bus.h"
#include "simple_bus_arbiter.h"
#include "packet.h"
#include "processor.h"
#include "copro1.h"

#include "processor_adapt_master.h"
#include "copro1_adapt_slave.h"
#include "copro2_adapt_slave.h"
#include "copro3_adapt_slave.h"
#define FIFO_SIZE 20;

/*
A compléter
*/


SC_MODULE(simple_bus_test)
{
	// channels
	sc_clock C1;

	// Signaux entre processeur et adapteur processeur
	sc_fifo<Packet*> processorIn;
	sc_fifo<Packet*> processorOut;

	// Signaux entre adaptateur de coprocesseur 1 et coprocesseur 1
	sc_signal<Packet*> copro1In;
	sc_signal<Packet*> copro1Out;

	sc_signal<bool> readyToSend_1;
	sc_signal<bool> readyToSendBack_1;

	// Signaux entre adaptateur de coprocesseur 2 et coprocesseur 2
	sc_signal<bool> copro2InSignal;
	sc_buffer<Packet*> copro2InBuffer;

	sc_signal<bool> copro2OutSignal;
	sc_buffer<Packet*> copro2OutBuffer;

	// Signaux entre adaptateur de coprocesseur 3 et coprocesseur 3
	sc_fifo<Packet*> copro3In;
	sc_fifo<Packet*> copro3Out;

	// instances de modules
	/*
	A décommenter
	*/
	processor				*proc;
	processor_adapt_master	*processor_adapt;
	simple_bus				*bus;
	simple_bus_arbiter      *arbiter;
	copro1					*copro_1;
	copro1_adapt_slave		*copro1_adapt;
	//copro2                  *copro_2;
	//copro2_adapt_slave		*copro2_adapt;
	//copro3                  *copro_3;
	//copro3_adapt_slave		*copro3_adapt;	

	// constructor
	SC_CTOR(simple_bus_test)
		: C1("C1")
		, processorIn(50)
		, processorOut(50)
	{
		// create instances
		//bus = new simple_bus("bus", true); // verbose output
		//arbiter = new simple_bus_arbiter("arbiter", true); // verbose output
		proc = new processor("processor");
		processor_adapt = new processor_adapt_master("processor_adapt_master", 4, 0xFF, false, 300);
		copro1_adapt = new copro1_adapt_slave("copro1_adapt", 0x00, 0x5F, 1);
		copro_1 = new copro1("copro_1");
		bus = new simple_bus("bus");
		arbiter = new simple_bus_arbiter("arbiter");
		/*
		A compléter
		*/

		// connect instances	
		bus->clock(C1);
		bus->arbiter_port(*arbiter);

		proc->pkt_in(processorIn);
		proc->pkt_out(processorOut);
		
		processor_adapt->packetFromProc(processorOut);
		processor_adapt->PacketToProc(processorIn);
		processor_adapt->myBus(*bus);

		copro1_adapt->pktFromcopro1(copro1Out);
		copro1_adapt->pktTocopro1(copro1In);
		copro1_adapt->readReady1(readyToSendBack_1);
		copro1_adapt->valueSent1(readyToSend_1);
		copro1_adapt->slave1Bus(*bus);

		copro_1->packetIn(copro1In);
		copro_1->packetOut(copro1Out);
		copro_1->complete(readyToSendBack_1);
		copro_1->valueReady(readyToSend_1);
		/*
		A compléter
		*/

	}

	// destructor
	~simple_bus_test()
	{
		if (bus) { delete bus; bus = 0; }
		if (arbiter) { delete arbiter; arbiter = 0; }
		/*
		A compléter
		*/

	}

}; // end class simple_bus_test

#endif
