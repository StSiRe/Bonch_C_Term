#pragma once
#include <vector>
#include <string>
class Client
{
private:	
	std::string name;
	int clientID;

public:
	void SetClientID(int clientId);
	int GetClientID();
	void SetClientName(std::string clientName);
	std::string GetClientName();
};

