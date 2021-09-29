#include "packet.h"

// Crée un paquet vide
Packet::Packet()
{
	m_packet_id = 0;
	m_address = 0;
	for (unsigned int i = 0; i < m_payload_size; i++) 
	{
		m_payload[i] = 0;
	}
}

// Crée un paquet avec juste une payload
Packet::Packet(unsigned int* payload)
{
	m_packet_id = 0;
	m_address = 0;
	for (unsigned int i = 0; i < m_payload_size; i++)
		m_payload[i] = *(payload + i);
}

// Crée un paquet avec charge utile aléatoire (0 à 999)
Packet::Packet(unsigned int packet_id, unsigned int address)
{
	m_packet_id = packet_id;
	m_address = address;

	for (unsigned int i = 0; i < m_payload_size; i++) 
	{
		m_payload[i] = rand() % 1000;
	}
}

// Crée un nouveau paquet en copiant un paquet existant
Packet::Packet(const Packet& a_packet)
{
	m_packet_id = a_packet.m_packet_id;
	m_address = a_packet.m_address;
	for (unsigned int i = 0; i < m_payload_size; i++) 
	{
		m_payload[i] = a_packet.m_payload[i];
	}
}

Packet::~Packet()
{
}

const Packet& Packet::operator=(const Packet& old_packet)
{
	if (&old_packet != this)
	{
		m_packet_id = old_packet.m_packet_id;
		m_address = old_packet.m_address;
		for (unsigned int i = 0; i < m_payload_size; i++) 
		{
			m_payload[i] = old_packet.m_payload[i];
		}
	}
	return *this;
}

void Packet::setPacketId(unsigned int packet_id)
{
	m_packet_id = packet_id;
}

void Packet::setAddress(unsigned int address)
{
	m_address = address;
}

void Packet::setPayload(unsigned int* data)
{
	for (unsigned int i = 0; i < m_payload_size; i++) 
	{
		m_payload[i] = data[i];
	}
}

/*
ostream& operator<< (ostream& o, const Packet& p)
{
	o << "Adresse du paquet : " << p.m_Address << endl
		<< "Contenu du paquet : " << p.m_Payload << endl;
	return o;
}
*/


