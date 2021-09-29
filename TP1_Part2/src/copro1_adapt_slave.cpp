#include "copro1_adapt_slave.h"

copro1_adapt_slave::~copro1_adapt_slave()
{
	/*
	A compléter
	*/
	if (MEM) delete [] MEM;
	MEM = (int*)0;
}

void copro1_adapt_slave::wait_loop()
{
	/*
	A compléter
	*/
	if (m_wait_count > 0) m_wait_count--;
}

simple_bus_status copro1_adapt_slave::read(int *data, unsigned int address)
{
	/*
	A compléter
	*/
	//est appelé lorsque le maitre appel burst_read
	
}

simple_bus_status copro1_adapt_slave::write(int* data, unsigned int address)
{
	/*
	A compléter
	*/
	//est appelé lorsque le maitre appel burst_write
	if (m_wait_count < 0) {
		m_wait_count = m_nr_wait_states;
		return SIMPLE_BUS_WAIT;
	}

	if (m_wait_count == 0) {
		if (payloadCounter == 0) m_current_packet_start_address = address;
		MEM[(address - m_start_address) / 4] = *data;
		payloadCounter++;
		if (payloadCounter == 6) {
			m_wait_count = -1;
			payloadCounter = 0;
			start_dispatch.notify();
		}
		return SIMPLE_BUS_OK;
	}
}

unsigned int copro1_adapt_slave::start_address() const
{
	/*
	A compléter
	*/
	return m_start_address;
}

unsigned int copro1_adapt_slave::end_address() const
{
	/*
	A compléter
	*/
	return m_end_address;
}

void copro1_adapt_slave::dispatch()
{
	/*
	A compléter
	*/
	//int* myValues = new int[6];
	//myValues = MEM[m_current_packet_start_address];
	packet = *(new Packet((unsigned int*)MEM));
	wait();
	pktTocopro1.write(&packet);
	valueSent1.write(true);

	// Réception paquet envoyé par copro 1 (attente bloquante)

	wait(readReady1.posedge_event());
	valueSent1.write(false);
	packet = *pktFromcopro1.read();
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
