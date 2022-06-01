#include "Client.h"
void Client::SetClientID(int clientId)
{
	clientID = clientId;
}
int Client::GetClientID()
{
	return clientID;
}
void Client::SetClientName(std::string clientName)
{
	name = clientName;
}
std::string Client::GetClientName()
{
	return name;
}