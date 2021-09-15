#include "copro1_adapt_slave.h"

copro1_adapt_slave::~copro1_adapt_slave()
{
	/*
	A compléter
	*/
}

void copro1_adapt_slave::wait_loop()
{
	/*
	A compléter
	*/
}

simple_bus_status copro1_adapt_slave::read(int *data, unsigned int address)
{
	/*
	A compléter
	*/
}

simple_bus_status copro1_adapt_slave::write(int *data, unsigned int address)
{
	/*
	A compléter
	*/
}

unsigned int copro1_adapt_slave::start_address() const
{
	/*
	A compléter
	*/
}

unsigned int copro1_adapt_slave::end_address() const
{
	/*
	A compléter
	*/
}

void copro1_adapt_slave::dispatch()
{
	/*
	A compléter
	*/
}

void copro1_adapt_slave::copro_interface(void)
{
	/*
	A compléter
	*/
}

// Ajout nécessaire pour ne pas avoir d'erreur à la compilation. Ne pas toucher à la suite.

bool copro1_adapt_slave::direct_read(int *data, unsigned int address)
{
  return (read(data, address) == SIMPLE_BUS_OK);
}

bool copro1_adapt_slave::direct_write(int *data, unsigned int address)
{
  return (write(data, address) == SIMPLE_BUS_OK);
}
