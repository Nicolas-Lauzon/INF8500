
#ifndef __simple_bus_test_h
#define __simple_bus_test_h

#include <systemc.h>

#include "simple_bus.h"
#include "simple_bus_arbiter.h"
#include "packet.h"

#include "processor_adapt_master.h"
#include "copro1_adapt_slave.h"
#include "copro2_adapt_slave.h"
#include "copro3_adapt_slave.h"

/*
A compl�ter
*/


SC_MODULE(simple_bus_test)
{
	// channels
	sc_clock C1;

	// Signaux entre processeur et adapteur processeur
	/*
	A compl�ter
	*/

	// Signaux entre adaptateur de coprocesseur 1 et coprocesseur 1
	/*
	A compl�ter
	*/

	// Signaux entre adaptateur de coprocesseur 2 et coprocesseur 2
	/*
	A compl�ter
	*/

	// Signaux entre adaptateur de coprocesseur 3 et coprocesseur 3
	/*
	A compl�ter
	*/

	// instances de modules
	/*
	A d�commenter
	*/
	//processor				*proc;
	//processor_adapt_master	*processor_adapt;
	//simple_bus				*bus;
	//simple_bus_arbiter      *arbiter;
	//copro1					*copro_1;
	//copro1_adapt_slave		*copro1_adapt;
	//copro2                  *copro_2;
	//copro2_adapt_slave		*copro2_adapt;
	//copro3                  *copro_3;
	//copro3_adapt_slave		*copro3_adapt;	

	// constructor
	SC_CTOR(simple_bus_test)
		: C1("C1")
	{
		// create instances
		//bus = new simple_bus("bus", true); // verbose output
		//arbiter = new simple_bus_arbiter("arbiter", true); // verbose output
		bus = new simple_bus("bus");
		arbiter = new simple_bus_arbiter("arbiter");
		/*
		A compl�ter
		*/

		// connect instances	
		bus->clock(C1);
		bus->arbiter_port(*arbiter);

		/*
		A compl�ter
		*/

	}

	// destructor
	~simple_bus_test()
	{
		if (bus) { delete bus; bus = 0; }
		if (arbiter) { delete arbiter; arbiter = 0; }
		/*
		A compl�ter
		*/

	}

}; // end class simple_bus_test

#endif
