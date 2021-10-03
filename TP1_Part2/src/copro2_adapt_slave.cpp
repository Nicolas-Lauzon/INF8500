#include "copro2_adapt_slave.h"

copro2_adapt_slave::~copro2_adapt_slave()
{
	/*
	A compléter
	*/
	if (MEM) delete[] MEM;
	MEM = (int*)0;
}

void copro2_adapt_slave::wait_loop()
{
	/*
	A compléter
	*/
	if (m_wait_count > 0) m_wait_count--;
}

simple_bus_status copro2_adapt_slave::read(int *data, unsigned int address)
{
	/*
	A compléter
	*/
	// accept a new call if m_wait_count < 0)
	if (m_wait_count < 0)
	{
		m_wait_count = m_nr_wait_states;
		return SIMPLE_BUS_WAIT;
	}
	if (m_wait_count == 0)
	{
		*data = MEM[(address - m_start_address) / 4];
		return SIMPLE_BUS_OK;
	}
	return SIMPLE_BUS_WAIT;
}

simple_bus_status copro2_adapt_slave::write(int *data, unsigned int address)
{
	/*
	A compléter
	*/
	if (m_wait_count < 0) {
		m_wait_count = m_nr_wait_states;
		return SIMPLE_BUS_WAIT;
	}

	if (m_wait_count == 0) {
		if (payloadCounter == 0) m_current_packet_start_address = address - m_start_address;
		MEM[(address - m_start_address) / 4] = *data;
		//printf("valeur recu   :%d\n", MEM[(address - m_start_address) / 4]);
		payloadCounter++;
		if (payloadCounter == 6) {
			m_wait_count = -1;
			payloadCounter = 0;
			packet_dispatched = 0;
			start_dispatch.notify();
		}
		return SIMPLE_BUS_OK;
	}
}

void copro2_adapt_slave::dispatch()
{
	while (1) {
		wait();
		pkt_send2();
		packet_dispatched = 1;
	}
}

unsigned int  copro2_adapt_slave::start_address() const
{
	return m_start_address;
}

unsigned int  copro2_adapt_slave::end_address() const
{
	return m_end_address;
}

void copro2_adapt_slave::pkt_send2(void)
{

	packet = *(new Packet((unsigned int*)MEM + (m_current_packet_start_address / 4)));

	packetOut_buf.write(&packet);
	packetOut.write(true);

	// Réception paquet envoyé par copro 1 (attente bloquante)

	wait(packetIn.posedge_event());
	packetOut.write(false);
	packet = *packetIn_buf.read();
	for (int i = 0; i < 6; i++) {
		MEM[((m_current_packet_start_address + (i * 4)) / 4)] = *(packet.getPayload() + i);
	}

}

// Ajout nécessaire pour ne pas avoir d'erreur à la compilation. Ne pas toucher à la suite.

bool copro2_adapt_slave::direct_read(int *data, unsigned int address)
{
  return (read(data, address) == SIMPLE_BUS_OK);
}

bool copro2_adapt_slave::direct_write(int *data, unsigned int address)
{
  return (write(data, address) == SIMPLE_BUS_OK);
}
