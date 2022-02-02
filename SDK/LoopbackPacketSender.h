#pragma once
#include "Packet/Packet.h"
#include <vector>

class LoopbackPacketSender {
public:
	virtual void Destructor();
	virtual void send(Packet&);
	virtual void sendToServer(Packet&);
	virtual void sendToClient(class UserEntityIdentifierComponent const*, Packet const&);
	virtual void sendToClient(class NetworkIdentifier const&, Packet const&, struct uchar);
	virtual void sendToClients(std::vector<class NetworkIdentifierWithSubId> const&, Packet const&);
	virtual void sendBroadcast(Packet const&);
	virtual void sendBroadcast(NetworkIdentifier const&, uchar, Packet const&);
	virtual void flush(NetworkIdentifier const&, __int64);//Could potentially not work properly
};