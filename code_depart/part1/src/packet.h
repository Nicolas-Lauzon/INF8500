//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//	Nom                    : Classe Paquet
//  Fichier				   : packet.h
//  Description            
//  Cette classe modélise un paquet. Le paquet contient 3 champs :       -----------------------------------------
//  Paquet --->     | Identifiant (32 bits) | adresse (32 bits) | payload (192 bits) |

#include <systemc.h>

#ifndef PACKET_H
#define PACKET_H

#define PAYLOAD_SIZE 6

class Packet
{
public:
	// CTOR
	Packet();	
	Packet(unsigned int* payload);
	Packet(unsigned int packet_id, unsigned int address);
	Packet(const Packet& a_packet);
	// DTOR
	virtual ~Packet();
 
	unsigned int getPacketId() { return m_packet_id; }
	unsigned int getAddress() { return m_address; }
	unsigned int* getPayload() { return m_payload; }
	unsigned int getPayloadSize() { return m_payload_size; }
	void setPacketId(unsigned int packet_id);
	void setAddress(unsigned int address);
	void setPayload(unsigned int* data);
	
	
	const Packet& operator=(const Packet& old_packet);
	// Surchage de l'opérateur de sortie à l'écran
	//friend ostream& operator << (ostream& o, const Packet& p);

private:
	// taille de la payload
	const unsigned int m_payload_size = PAYLOAD_SIZE;
	// ID unique pour un paquet
	unsigned int m_packet_id;	
	// champ adresse
	unsigned int m_address;
	// champ payload (charge utile)
	unsigned int m_payload[PAYLOAD_SIZE];
	
};

#endif
